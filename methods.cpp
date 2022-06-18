#ifndef METHODS
#define METHODS

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <chrono>

#include "ListGraph.cpp"
#include "MatrixGraph.cpp"

using namespace std;
using std::find;

void exitPage(){

    cout << " __________" << endl;
    cout << "|  __  __  |" << endl;
    cout << "| |  ||  | |" << endl;
    cout << "| |  ||  | |  buh bye" << endl;
    cout << "| |__||__| |" << endl;
    cout << "|  __  __()|" << endl;
    cout << "| |  ||  | |" << endl;
    cout << "| |  ||  | |" << endl;
    cout << "| |  ||  | |" << endl;
    cout << "| |  ||  | |" << endl;
    cout << "| |__||__| |" << endl;
    cout << "|__________|" << endl;

}



vector<int> matrixDijkstra(MatrixGraph input, int from) {
	auto prev = input.dijkstra(from);
    return prev;
}

vector<int> listDijkstra(ListGraph input, int from){
    auto prev = input.dijkstra(from);
    return prev;
}


void createMatrix(int size){
    int startNode;
    string nodeNames[size];
    int edgeWeights[size][size];
    int borderLen = (size+1)*9;
    string border(borderLen, '-');

    MatrixGraph matrixUser(size);
    ListGraph listUser(size);
    
    cout << "\nNOTE: ALL NODES WILL BE BI-DIRECTIONAL (GOES BOTH WAYS)"<< endl;

    cout << "\nEnter node names: ";

    // storing the node names
    for(int i = 0; i < size; i++){
        cin >> nodeNames[i];
    }

    //ignoring any extra inputs
    //for example, for a matrix with a size of 3:
    //if the user inputs 5 node names, will only detect the first 3
    cin.ignore(numeric_limits<streamsize>::max(),'\n');


    cout << "\nPlease input " << size*size << " edge values:" << endl;
    // enter values from one node to the other
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int weight;
            cin >> weight;
            edgeWeights[i][j] = weight;
            matrixUser.connect(i, j, weight, true);
            listUser.connect(i, j, weight, true);
        }
    }

    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\nYou've entered an invalid input, please make sure it's a numeric value (No words, no ASCII art, just numbers, ok?)"<< endl;
            cout << "\nEnter a valid input: ";
            for (int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    int weight;
                    cin >> weight;
                    edgeWeights[i][j] = weight;
                    matrixUser.connect(i, j, weight, true);
                    listUser.connect(i, j, weight, true);
                }
            }
        }
        if(!cin.fail()){
            break;
        }
    }


    //ignoring any extra inputs
    //for example, for a matrix with a size of 3, total weight needed is 9:
    //if the user inputs 12 node names, will only detect the first 9
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    
    // print the matrix
    // add space for matrix format
    cout << "\t\t  ";
    for(int i = 0; i < size; i++){
        cout << nodeNames[i] << "\t   ";
    }
    cout << endl;
    
    
    //printing the matrix in table form
    cout << border;
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << nodeNames[i] << " = " << i << "\t\t";
        for(int j = 0; j < size; j++){
            cout << "| " << edgeWeights[i][j] << "\t ";
        }
        cout << endl;
    }
    cout << border << endl;
    cout << endl;   

    //prompting for source node
    cout << "Enter source node: ";
    cin >> startNode;

    //prompting for end node
    int endNode;
    cout << "Enter end node:";
    cin >> endNode ;

    int endNodeList = endNode;
    int endNodeMatrix = endNode;


    
    //TESTING FOR TIME TAKEN
    srand(time(0));

    //MATRIX TIME TAKEN START
    auto startMatrixTime = chrono::steady_clock::now();

    //declaring the vectors for the matrix paths
    vector<int> matrixPrev = matrixDijkstra(matrixUser, startNode);
    vector<int> matrixPath;

    //initializing the values for the total matrix path costs
    int costMatrix = 0;
    matrixPath.push_back(endNodeMatrix);

    //adding the matrix path costs to find the total
    //adding the matrix path nodes to the resulting path list
    while(endNodeMatrix != startNode){
        int prevNodeMatrix = matrixPrev.at(endNodeMatrix);

        costMatrix += matrixUser.getWeight(prevNodeMatrix, endNodeMatrix);
        matrixPath.push_back(matrixPrev.at(endNodeMatrix));
        endNodeMatrix = matrixPrev.at(endNodeMatrix);
    }
    auto endMatrixTime = chrono::steady_clock::now();

    //MATRIX TIME TAKEN END

    //LIST TIME TAKEN START
    auto startListTime = chrono::steady_clock::now();

    //declaring the vectors for the list paths
    vector<int> listPrev = listDijkstra(listUser, startNode);
    vector<int> listPath ;

    //initializing the values for the total path costs
    int costList = 0;

    listPath.push_back(endNodeList);

    //adding the list path costs to find the total
    //adding the list path nodes to the resulting path list
    while(endNodeList != startNode){
        int prevNodeList = listPrev.at(endNodeList);

        costList += listUser.getWeight(prevNodeList, endNodeList);

        listPath.push_back(listPrev.at(endNodeList));
        endNodeList = listPrev.at(endNodeList);
    }
    auto endListTime = chrono::steady_clock::now();

    //LIST TIME TAKEN END

    //getting the end time taken
    double totalMatrixTime = double(chrono::duration_cast<chrono::nanoseconds> (endMatrixTime - startMatrixTime).count());
    double totalListTime = double(chrono::duration_cast<chrono::nanoseconds> (endListTime - startListTime).count());

    cout << "\nTime for matrix\t: " << totalMatrixTime << endl;
    cout << "\nTime for list\t: " << totalListTime << endl;

    //declaring the vectors for the paths

    //Printing out the cost and path
    cout << "Matrix Cost\t: " << costMatrix << endl;
    cout << "Matrix Path\t: START - ";
    for(int i = matrixPath.size() - 1 ; i > -1 ; i--){
        cout << nodeNames[matrixPath[i]] << " - ";
    }
    cout << "END\n" << endl;

    cout << "List Cost\t: " << costList << endl;
    cout << "List Path\t: START - ";
    for(int i = listPath.size() - 1; i > -1; i--){
        cout << nodeNames[listPath[i]] << " - ";
    }
    cout << "END\n" << endl;


}

int inputValidation(bool inputFail){

    int result;
    while(inputFail){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"\nYou've entered an invalid input, please make sure it's a numeric value (No words, no ASCII art, just numbers, ok?)"<< endl;
            cout << "\nEnter a valid input: ";
            cin >> result;
        }
        if(!cin.fail()){
            break;
        }
    }
    return result;
}

void processMatrixSize(){
    int size;
    //prompting user for the matrix size
    cout << "Enter matrix size: ";
    cin >> size;

    //input validation for the matrix size
    bool inputFail2 = cin.fail();
    if(inputFail2){
        size = inputValidation(inputFail2);
    }
    createMatrix(size);

}

//function for showing the main menu options
bool MainMenu(){
    int userChoice;
    //printing the main menu options
    cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "1. Custom Matrix " << endl;
    cout << "2. More Info" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter an option, dude. We're waiting. : ";
    cin >> userChoice;
    
    //input validation for the options
    bool inputFail = cin.fail();
    if(inputFail){
        userChoice = inputValidation(inputFail);
    }
    //processing if the input = 1
    if(userChoice == 1){
        cout << "You have chosen option 1." << endl;
        cout << "------------------------" << endl;
        processMatrixSize();
        MainMenu();
    }
    //processing if the input = 2
    else if(userChoice == 2){
        cout << "\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "You have chosen option 2." << endl;
        cout << "MORE INFORMATION" << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Custom Matrix"<< endl;
        cout << "This custom matrix option will help you to manually input the matrix based on your preferences."<< endl;
        cout << "Input the matrix you want to pathfind," <<endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "2. More Info" << endl;
        cout << "This option will open the guidebook on the Route-Bot program." << endl;
        cout << "(You're already in this option so idk why you need more info on this but here ya go) "<< endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "3. Quit... ಠ_ಠ"<< endl;
        MainMenu();

    }else if (userChoice == 3){ //processing if the input = 3

        exitPage();
    }
    else{
        cout << "                     _________________________________________________" << endl;
        cout << "            /|     |                                                 |" << endl;
        cout << "            ||     |   PLEASE ENTER THE RIGHT NUMBER 🔪              |" << endl;
        cout << "       .----|-----,|      PLEASE ENTER THE RIGHT NUMBER 🔪           |" << endl;
        cout << "       ||  ||   ==||           PLEASE ENTER THE RIGHT NUMBER 🔪      |" << endl;
        cout << "  .-----'--'|   ==||                PLEASE ENTER THE RIGHT NUMBER 🔪 |" << endl;
        cout << "  |)-      ~|     ||_________________________________________________|" << endl;
        cout << "  | ___     |     |____...==..._  >\\______________________________|==💨💨💨" << endl;
        cout << " [_/.-.\"---------- //.-.  .-.\\/                   \\ .-.  .-. //" << endl;
        cout << "   ( o )`===\"\"\"\"\"\"\"\"( o )( o )                    `( o )( o )`" << endl;
        cout << "    '-'              '-'  '-'                       '-'  '-'" << endl;
        MainMenu();
    }
    
}

#endif
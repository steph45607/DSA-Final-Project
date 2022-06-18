#ifndef METHODS
#define METHODS

#include <iostream>
#include <string>
#include <vector>

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





// void processMatrix(int size, int edgeArr[][50], string nameArr[]){
//     cout << "1. Only go from start to end, the crossed nodes doesn't matter (ignore them, they suck anyways)" << endl;
//     cout << "2. Add additional nodes, on top of the start and end nodes." << endl;
//     cout << "3. Select all options (you absolute fiend)" << endl;
//     cout << "These are our services, please kindly enter your choice: ";

//     int userChoice;
//     cin >> userChoice;

//     if (userChoice == 1) {
//         cout << "You've selected option 1. Like the number of times I've gone outside since 2020.";
//     } else if (userChoice == 2) {
//         cout << "You've picked option 2. Like how it takes 2 to tango out of difficult route.";
//     } else if (userChoice == 3) {
//         cout << "You've picked option 3. Like trees... In the forest. Yeah, I got nothing. ";
//     }

// }


vector<int> matrixDijkstra(MatrixGraph input, int from) {
	auto prev = input.dijkstra(from);
	print(prev);
    return prev;
}

vector<int> listDijkstra(ListGraph input, int from){
    auto prev = input.dijkstra(from);
    print(prev);
    return prev;
}

// void continueProgram(){
//     MainMenu();
// }

void createMatrix(int size){
    int startNode;
    string nodeNames[size];
    int edgeWeights[size][size];
    int borderLen = (size+1)*9;
    string border(borderLen, '-');

    MatrixGraph matrixUser(size);
    ListGraph listUser(size);
    
    cout << "NOTE: ALL NODES WILL BE BI-DIRECTIONAL (GOES BOTH WAYS)"<< endl;

    cout << "\nEnter node names: ";
    // enter the node names
    for(int i = 0; i < size; i++){
        cin >> nodeNames[i];
    }

    cout << "\nInput edge values:" << endl;
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

    //storing the last node visited before the index node
    vector<int> matrixPrev = matrixDijkstra(matrixUser, startNode);
    vector<int> listPrev = listDijkstra(listUser, startNode);
    
    //prompting for end node
    int endNode;
    cout << "Enter end node:";
    cin >> endNode ;

    //declaring the vectors for the paths
    vector<int> listPath ;
    vector<int> matrixPath;
    //declaring
    int costList = 0;
    int costMatrix = 0;

    listPath.push_back(endNode);
    matrixPath.push_back(endNode);

    while(endNode != startNode){
        int prevNodeList = listPrev.at(endNode);
        int prevNodeMatrix = matrixPrev.at(endNode);

        costList += listUser.getWeight(prevNodeList, endNode);
        costMatrix += matrixUser.getWeight(prevNodeMatrix, endNode);

        listPath.push_back(listPrev.at(endNode));
        matrixPath.push_back(matrixPrev.at(endNode));
        endNode = listPrev.at(endNode);
    }



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

void processMatrixSize(){
    int size;
    cout << "Enter matrix size: ";
    cin >> size;
    createMatrix(size);
}

bool MainMenu(){
    int n;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "1. Custom Matrix " << endl;
    cout << "2. More Info" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter an option, dude. We're waiting. : ";
    cin >> n;
    
    if(n == 1){
        cout << "You have chosen option 1." << endl;
        cout << "------------------------" << endl;
        processMatrixSize();
        MainMenu();
    }
    else if(n == 2){
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "You have chosen option 2." << endl;
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

    }else if (n == 3){
        
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
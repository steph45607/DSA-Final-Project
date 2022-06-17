#ifndef METHODS
#define METHODS

#include <iostream>
#include <string>
#include <vector>

#include "test3.cpp"


using namespace std;

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

void processMatrix(int size, int edgeArr[][50], string nameArr[]){
    cout << "1. Only go from start to end, the crossed nodes doesn't matter (ignore them, they suck anyways)" << endl;
    cout << "2. Add additional nodes, on top of the start and end nodes." << endl;
    cout << "3. Select all options (you absolute fiend)" << endl;
    cout << "These are our services, please kindly enter your choice: ";

    int userChoice;
    cin >> userChoice;

    if (userChoice == 1) {
        cout << "You've selected option 1. Like the number of times I've gone outside since 2020.";
    } else if (userChoice == 2) {
        cout << "You've picked option 2. Like how it takes 2 to tango out of difficult route.";
    } else if (userChoice == 3) {
        cout << "You've picked option 3. Like trees... In the forest. Yeah, I got nothing. ";
    }
    cout << "NOTE: ALL NODES WILL BE BI-DIRECTIONAL";
    cout << "Enter the start and end nodes:";
}


vector<int> test_dijkstra_mat(MatrixGraph input, int from) {
	auto prev = input.dijkstra(from);
	print(prev);
    return prev;
}

vector<int> test_dijkstra_list(ListGraph input, int from){
    auto prev = input.dijkstra(from);
    print(prev);
    return prev;
}

void createMatrix(int size){
    int n = size;
    int from;
    MatrixGraph matrixUser(size);
    ListGraph listUser(size);

    string nodeNames[size];
    cout << "\nEnter node names: ";
    // enter the node names
    for(int i = 0; i < size; i++){
        cin >> nodeNames[i];
    }

    cout << "\nInput edge values:" << endl;
    // enter values from one node to the other
    int edgeValues[size][size];
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int weight;
            cin >> weight;
            edgeValues[i][j] = weight;
            matrixUser.connect(i, j, weight, true);
            listUser.connect(i, j, weight, true);
        }
    }
    
    // print the matrix
    // add space for matrix format
    cout << "\t  ";
    for(int i = 0; i < size; i++){
        cout << nodeNames[i] << "\t   ";
    }
    cout << endl;
    for(int i = 0; i <= size; i++){
        
    }
    int x = (size+1)*9;
    string testing(x, '-');
    cout << testing;
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << nodeNames[i] << "\t";
        for(int j = 0; j < size; j++){
            cout << "| " << edgeValues[i][j] << "\t ";
        }
        cout << endl;
    }
    
    //prompting for source node
    cout << "Enter source node: ";
    cin >> from;

    //storing the last node visited before the index node
    vector<int> matrixPrev = test_dijkstra_mat(matrixUser, from);
    vector<int> listPrev = test_dijkstra_list(listUser, from);
    
    //prompting for end node
    int endNode;
    cout << "Enter end node:";
    cin >> endNode ;

    vector<int> listPath ;
    vector<int> matrixPath;
    int costList = 0;
    int costMatrix = 0;

    listPath.push_back(endNode);
    matrixPath.push_back(endNode);

    // while(endNode != -1){
    //     int prevNodeList = listPrev.at(endNode);
    //     int prevNodeMatrix = matrixPrev.at(endNode);

    //     costList += listUser.getWeight(prevNodeList, endNode);
    //     costMatrix += matrixUser.getWeight(prevNodeMatrix, endNode);

    //     listPath.push_back(listPrev.at(endNode));
    //     matrixPath.push_back(matrixPrev.at(endNode));
    //     endNode = listPrev.at(endNode);
    // }


    while(endNode != from){
        int prevNodeList = listPrev.at(endNode);
        int prevNodeMatrix = matrixPrev.at(endNode);

        costList += listUser.getWeight(prevNodeList, endNode);
        costMatrix += matrixUser.getWeight(prevNodeMatrix, endNode);

        listPath.push_back(listPrev.at(endNode));
        matrixPath.push_back(matrixPrev.at(endNode));
        endNode = listPrev.at(endNode);
    }




    cout << "Matrix Cost\t: " << costMatrix << endl;

    for(int i = 0; i < matrixPath.size(); i++){
        cout << matrixPath[i] << " ";
    }
    cout << endl;


    cout << "List Cost\t: " << costList << endl;

    for(int i = 0; i < listPath.size(); i++){
        cout << listPath[i] << " ";
    }
    cout << endl;

    

    //calling the processMatrix method
    // processMatrix(size, edgeValues[size][size], nodeNames[size]);
    
}

int customMenu(){
    int size;
    cout << "\nEnter matrix size: ";
    cin >> size;
    createMatrix(size);
    // algoTing(matrix);
    return 3;
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
        customMenu();
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

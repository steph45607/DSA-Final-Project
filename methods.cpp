#ifndef METHODS
#define METHODS

#include <iostream>
#include <string>
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
    
    cout << "Enter the start and end nodes:";
}


void createMatrix(int size){
    int n = size;

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
            cin >> edgeValues[i][j];
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

    // cout >> edgeValues

    //calling the processMatrix method
    // processMatrix(size, edgeValues[size][size], nodeNames[size]);

    cout << endl;
    cout << "1. Only go from start to end, node crossed doesn't matter (ignore them, they suck anyways)" << endl;
    cout << "2. Add additional nodes, on top of the start and end nodes." << endl;
    cout << "3. Select all options (you absolute fiend, think of the program)"<< endl;
    cout << "These are our services, please kindly enter your choice: ";

    int userChoice;
    cin >> userChoice;

    if (userChoice == 1) {
        cout << "You've selected option 1. You've got uno! Oh, wait, no. No. You don't. Oops.";
    } else if (userChoice == 2) {
        cout << "You've selected option 2. ";
    } else if (userChoice == 3) {
        cout << "You've selected option 3. I have 3 letters for you, RUN. As in Remotely Utilized Navigation-Bot :)";
    }
    
    cout << "\nEnter the start and end nodes:";
}

int customMenu(){
    int size;
    cout << "\nEnter matrix size: ";
    cin >> size;
    createMatrix(size);
    // algoTing(matrix);
    return 3;
}

int algoTing(){
    return true;
}

bool MainMenu(){
    int n;
    cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
    cout << "1. Randomly Generated Matrix and Route" << endl;
    cout << "2. Custom Matrix " << endl;
    cout << "3. More Info" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter an option, dude. We're waiting. : ";
    cin >> n;
    
    if(n == 1){
        cout << "You have chosen option 1." << endl;
        cout << "------------------------" << endl;
    }
    else if(n == 2){
        cout << "You have chosen option 2." << endl;
        cout << "------------------------" << endl;
        customMenu();
    }
    else if(n == 3){
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "You have chosen option 3" << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Randomly Generated Matrix and Route " << endl;
        cout << "This option will generate a random matrix (duh, it's in the name man). " << endl;
        cout << "You'll be prompted to input the size of the matrix you want, then it will generate a random matrix and" << endl;
        cout << "automatically search the shortest and most optimal routes for it. " << endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "2. Custom Matrix"<< endl;
        cout << "This custom matrix option will help you to manually input the matrix based on your preferences."<< endl;
        cout << "Input the matrix you want to pathfind," <<endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "3. More Info" << endl;
        cout << "This option will open the guidebook on the Route-Bot program." << endl;
        cout << "(You're already in this option so idk why you need more info on this but here ya go) "<< endl;
        cout << "-------------------------------------------------------------------------------------------------------" << endl;
        cout << "4. Quit... ಠ_ಠ"<< endl;
        MainMenu();

    }else if (n == 4){
        
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

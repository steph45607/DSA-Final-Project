#include <iostream>
#include "methods.cpp"
using namespace std;


int main(){
    bool check = true;
    cout <<"--------Welcome to--------" << endl;
    cout <<"╦═╗╔═╗╦ ╦╔╦╗╔═╗  ╔╗ ╔═╗╔╦╗" << endl;
    cout <<"╠╦╝║ ║║ ║ ║ ║╣───╠╩╗║ ║ ║ " << endl;
    cout <<"╩╚═╚═╝╚═╝ ╩ ╚═╝  ╚═╝╚═╝ ╩ " << endl;
    cout <<"Your pathfinding companion" << endl;

    cout <<"          _____" << endl;
    cout <<"         | _ _ |" << endl;
    cout <<"         | | | |" << endl;
    cout <<"         |_____|" << endl;
    cout <<"   ____ ___|_|___ ____" << endl;
    cout <<"  ()___)         ()___)" << endl;
    cout <<"  // /|    👨🏼     |\\ \\\\" << endl; 
    cout <<" // / |           | \\ \\\\" << endl;
    cout <<"(___) |___________| (___)" << endl;
    cout <<"(___)   (_______)   (___)"<< endl;
    cout <<"      |___________| " << endl;
    cout <<"       |||     ||| " << endl;
    cout <<"       |||     ||| " << endl;
    cout <<"       |||     |||  " << endl;
    cout <<"      ()__)   (__()" << endl;
    while(check == true){
        check = MainMenu();
    }
    // customMenu();

}
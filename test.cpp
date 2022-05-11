#include <iostream>
using namespace std;

int main(){
    int size = 3;
    int arr[size][size] = {{1,2,3}, {4,5,6}, {7,8,9}};
    char nodeNames[size];
    cout << "Enter node names: ";
    for(int i = 0; i < size; i++){
        cin >> nodeNames[i];
    }
    cout << "  ";
    for(int i = 0; i < size; i++){
        cout << nodeNames[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < size; i++){
        cout << nodeNames[i] << " ";
        for(int j = 0; j < size; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
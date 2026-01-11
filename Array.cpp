#include <iostream>
using namespace std;

int main (){
    int arr[5]={2, 4, 8 ,12, 16};
    for (int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    arr[3]=10;
    for (int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << sizeof(arr)/sizeof(arr[0]) << endl;

    cout << &arr[0] << endl;

    return 0;
}
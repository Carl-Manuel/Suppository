#include <iostream>
using namespace std; 

int main(){
    string myname = "Carl";
    string &palayaw = myname;
    string *ptr = &myname;

    cout << "My name is " << myname <<endl;
    cout << "My name address is: " << ptr <<endl;
    cout << "My name another address is: " << &myname <<endl;
    cout << "My name using pointer is: " << *ptr <<endl;
    cout << "My name using reference is: " << &palayaw <<endl;


    return 0;
}
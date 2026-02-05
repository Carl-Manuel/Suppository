#include <iostream>
using namespace std;

int fact(int n)
{
    
    if (n == 0)
        return 1;
  
    return n * fact(n - 1);
}

int main()
{
    cout << "Factorial of 10 : " << fact(10);
    return 0;
}
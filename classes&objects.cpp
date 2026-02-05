#include <iostream>
using namespace std;

// Class definition
class GfG
{
public:
    // Data member
    int val;

    // Member function
    void show()
    {
        cout << "Value: " << val << endl;
    }
};

int main()
{
    // Creating an object of class GfG
    GfG obj;

    // Assigning value to data member
    obj.val = 42;

    // Calling member function
    obj.show();

    return 0;
}

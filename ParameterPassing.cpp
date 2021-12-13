#include <iostream>
using namespace std;

class Parameters {
public:
    static void byVal(int param) {
        // This method copies the actual value of an argument into the formal parameter of the function.
        cout << "This parameter is passed by value: " << param << endl;
        cout << "The memory allocation of the parameter: " << &param << endl;
    }

    static void byRef(int *param) {
        // This method copies the reference of an argument into the formal parameter.
        cout << "This parameter is passed by reference: " << *param << endl;
        cout << "The memory allocation of the parameter: " << &param << endl;
    }
};

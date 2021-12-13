#include <iostream>
#include "Fibonacci.cpp"
#include "FunctionOverload.cpp"

using namespace std;

int main() {
    signed int num0 = 17;
    signed int num1 = 22;
    float num2 = 1.27;
    double num3 = 1.234567;

    cout << "Fibonacci number at " << num0 << "'th place: " << FibonacciClass::basicFibonacci(num0) << endl;
    cout << "Fibonacci number at " << num1 << "'th place: " << FibonacciClass::recursiveFibonacci(num1) << endl;

    return 0;
}
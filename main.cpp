#include <iostream>
#include "Fibonacci.cpp"

using namespace std;

int main() {
    signed int num0 = 17;
    signed int num1 = 22;

    cout << "Fibonacci number at " << num0 << "'th place: " << FibonacciClass::basicFibonacci(num0) << endl;
    cout << "Fibonacci number at " << num1 << "'th place: " << FibonacciClass::recursiveFibonacci(num1) << endl;

    return 0;
}
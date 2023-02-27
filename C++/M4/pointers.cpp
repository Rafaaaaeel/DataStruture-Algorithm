#include <iostream>

using namespace std;

int main() {
    int* num1 = new int(11);
    int* num2 = num1;


    // memory adress
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    // value
    cout << "num1 = " << *num1 << endl;
    cout << "num2 = " << *num2 << endl;
}
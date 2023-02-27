#include <iostream>

using namespace std;

int addItems(int n) {
    return n + n;
}

int main() {
    int total = addItems(10);
    cout << total;
}
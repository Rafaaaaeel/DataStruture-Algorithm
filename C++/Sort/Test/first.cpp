#include <iostream>
#include <vector>

// using namespace std;
void printItems(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i << std::endl;
    }
}

int main() {
    
    std::string name = "mia";
    std::string names[10];

    // std::cin >> name;
    
    int futurePositionIndex;

    for (int i = 0; i < name.length(); i++) {
        futurePositionIndex = futurePositionIndex + int(name[i]);
    }

    // std::cout << futurePositionIndex / 100;

    printItems(10);
    

}


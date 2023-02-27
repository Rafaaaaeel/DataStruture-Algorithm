#include <iostream>

int main() {
    int arr[] = { 20, 35, -15, 7, 55, 1, -22 };

    for (int lastUnsortedIndex = (sizeof(arr) / sizeof(int)) - 1; lastUnsortedIndex > 0; lastUnsortedIndex--) {
        for (int i = 0; i < lastUnsortedIndex; i++) {
            int j = i + 1;
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        std::cout << arr[i] << std::endl;
    }

    std::cout << sizeof(arr) / sizeof(int) << " elements" << std::endl;
}

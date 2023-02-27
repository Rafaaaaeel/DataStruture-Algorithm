#include <iostream>

int main() {

    int arr[] = { 20, 35, -15, 7, 55, 1, -22 };

    for (int lastUnsortedIndex = (sizeof(arr) / sizeof(arr[0]) - 1); lastUnsortedIndex > 0; lastUnsortedIndex--) {
        int largest = 0;
        for (int i = 1; i < lastUnsortedIndex; i++) {

            if(arr[i] > arr[largest]) {
                largest = i;
            }
        
        }

        int temp = arr[lastUnsortedIndex];
        arr[lastUnsortedIndex] = arr[largest];
        arr[largest] = temp;

    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        std::cout << arr[i] << std::endl;
    }
}

package SelectionSort;

public class ThirdTry {

    public static void main(String[] args) {
        int[] intArray = { 20, 35, -15, 7, 55, 1, -23 };

        for(int lastUnsorterdIndex = intArray.length - 1; lastUnsorterdIndex > 0; lastUnsorterdIndex--) {
            int largest = 0;
            for (int i = 1; i <= lastUnsorterdIndex; i++) {
                if (intArray[i] > intArray[largest]) {
                    largest = i;
                }
            }
            swap(intArray, largest, lastUnsorterdIndex);
        }

        printArray(intArray);
    }
    public static void swap(int[] array, int i, int j) {

        if (i == j) {
            return;
        }
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;

    }
    public static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++){
            System.out.println(array[i]);
        }
    }
}

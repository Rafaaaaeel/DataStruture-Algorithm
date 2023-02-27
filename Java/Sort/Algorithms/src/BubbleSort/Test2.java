package BubbleSort;

public class Test2 {
    public static void main(String[] args) {

        int[] numeros = { 42, -2, 0, 100, 30 };

        for (int lastUnsortedIndex = numeros.length - 1; lastUnsortedIndex > 0; lastUnsortedIndex--) {
            for (int i = 0; i < lastUnsortedIndex; i++) {
                if (numeros[i] > numeros[i + 1]) {
                    swap1(numeros, i, i + 1);
                }
            }
        }

        printArray1(numeros);
    }


    public static void printArray1(int[] array) {
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }

    public static void swap1(int[] array, int i, int j) {
        if (i == j) {
            return;
        }

        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

}

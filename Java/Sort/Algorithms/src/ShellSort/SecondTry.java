package ShellSort;

public class SecondTry {

    public static void main(String[] args) {
        int[] intArray = { 35, 40, -15, 7, 55, 1, -22 };

        for (int gap = intArray.length / 2; gap > 0; gap /= 2) {

            for (int i = gap; i < intArray.length; i ++) {
                int newElement = intArray[i];
                int j = i;

                while(j >= gap && intArray[j - gap] > newElement) {
                    intArray[j] = intArray[j - gap];
                    j -=gap;
                }

                intArray[j] = newElement;
            }

        }

        printArray(intArray);
    }

    public static void printArray(int[] array) {
        for(int i = 0; i < array.length; i++) {
            System.out.println(array[i]);
        }
    }


}

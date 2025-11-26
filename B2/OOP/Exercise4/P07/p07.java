import java.util.*;
public class p07 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter amount of numbers: ");
        int n = sc.nextInt();
        if (n < 1) {
            System.out.println("Array size must be at least 1. ");
            return;
        }
        double[] arr = new double[n];
        double mean = 0, ssd = 0;
        System.out.println("Enter the numbers: ");
        for (int i = 0; i <= n - 1; i++) {
            arr[i] = sc.nextDouble();
            mean += arr[i];
            ssd += Math.pow(arr[i], 2);
        }
        // another way to do the loop if the numbers have already been inputted:
        // for (double num: arr) {
        //  mean += num;
        //  ssd += Math.pow(num, 2);
        // }
        mean /= n;
        ssd = Math.sqrt(ssd) / (n - 1);
        System.out.printf("\nMean: %.4f\nSample standard deviation: %.4f", mean, ssd);
        System.out.printf("\nNumbers greater than the average: ");
        for (int i = 0; i <= n - 1; i++) {
            if (arr[i] > mean) {
                System.out.printf("%f ", arr[i]);
            }
        }
    }
}
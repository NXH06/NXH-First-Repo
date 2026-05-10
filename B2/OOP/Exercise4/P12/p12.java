import java.util.*;
public class p12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b;
        while (true) {
            System.out.print("a: ");
            a = sc.nextInt();
            if (a % 2 != 0) {
                System.out.println("Please enter an even number. ");
            }
            else {
                break;
            }
        }
        while (true) {
            System.out.print("b: ");
            b = sc.nextInt();
            if (b % 2 == 0) {
                System.out.println("Please enter an odd number. ");
            }
            else {
                break;
            }
        }
        int c = (int) (Math.random() * 1000);
        System.out.printf("c = %d\n", c);
        System.out.print("m, n: ");
        double m = sc.nextDouble();
        double n = sc.nextDouble();
        System.out.printf("Result: %f", a * Math.pow(2, n) + b * Math.pow(2, m) + c);
    }
}
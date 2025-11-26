import java.util.*;
public class p05 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter mark: ");
        int mark = sc.nextInt();
        if (mark < 0 || mark > 20) { // MUST HAVE SAFEGUARD to get full score!
            System.out.println("Mark must be in 0-20 range!");
            return;
        }
        if (mark >= 0 && mark < 10) {
            System.out.println("Fail");
        }
        else if (mark >= 10 && mark <= 12) {
            System.out.println("Average");
        }
        // the rest is too easy...
    }
}

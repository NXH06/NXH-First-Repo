import java.util.*;
public class VectorTester {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double tempX, tempY;
        System.out.println("Enter values of first vector: ");
        tempX = sc.nextDouble();
        tempY = sc.nextDouble();
        Vector a = new Vector(tempX, tempY);
        System.out.println("Enter values of second vector: ");
        tempX = sc.nextDouble();
        tempY = sc.nextDouble();
        Vector b = new Vector(tempX, tempY);
        // call static method by class name
        Vector s = Vector.sum(a, b);
        double d = Vector.dotProduct(a, b);
        Vector c = Vector.crossProduct(a, b);
        System.out.printf("Sum: (%.4f, %.4f)\nDot product: %.4f\nCross product: (%.4f, %.4f)", s.getX(), s.getY(), d, c.getX(), c.getY());
    }
}
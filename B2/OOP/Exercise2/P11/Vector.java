public class Vector {
    private double x;
    private double y;
    // Constructor
    public Vector (double x, double y) {
        this.x = x;
        this.y = y;
    }
    // Default constructor
    public Vector () {
        this.x = 0;
        this.y = 0;
    }
    // Getters
    public double getX () {
        return this.x;
    }
    public double getY () {
        return this.y;
    }
    // calculation-related methods are set as static so that they can be called as a class method (no need for obj.func())
    public static Vector sum (Vector a, Vector b) {
        Vector v = new Vector();
        v.x = a.x + b.x;
        v.y = a.y + b.y;
        return v;
    }
    public static double dotProduct (Vector a, Vector b) {
        return a.x * b.x + a.y * b.y;
    }
    public static Vector crossProduct (Vector a, Vector b) {
        Vector v = new Vector();
        v.x = v.y = a.x * b.y - a.y * b.x;
        return v;
    }
}
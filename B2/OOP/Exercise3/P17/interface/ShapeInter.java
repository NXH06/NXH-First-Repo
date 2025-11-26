public interface ShapeInter {
    public abstract double calArea();
    public abstract double calVolume();
    public abstract String getName();
}
class Point implements ShapeInter { // The interface will also be inherited. No need to re-implement for every subclass
    protected double x, y;
    public Point (double x, double y) { // Constructor: similar to a setter but has the same name as the class
        this.x = x;
        this.y = y;
    }
    @Override public String getName() {
        return "Point";
    }
    @Override public double calArea() {
        return 0; // a point has no area
    }
    @Override public double calVolume() {
        return 0; // a point has no volume
    }
    // some optional functions, added for fun
    public int getQuadrant() { 
        if (x*y > 0) {
            if (x > 0) return 1;
            else return 3;
        }
        else {
            if (x > 0) return 2;
            else return 4;
        }
    }
    public double getDistanceFromOrigin() {
        return (Math.sqrt(Math.pow(x, 2) + Math.pow (y, 2)));
    }
}
class Circle extends Point {
    protected double radius;
    public Circle (double x, double y, double radius) {
        super(x, y);
        if (radius > 0) { // check for validity in setter method!
            this.radius = radius;
        }
    }
    @Override public String getName() {
        return "Circle";
    }
    @Override public double calArea() {
        return calArea(radius); // override the generic method with a more specific one
    }
    public double calArea (double radius) {
        return radius * radius * Math.PI;
    }
    @Override public double calVolume() {
        return 0; // a circle has no volume
    }
    public double calCircumference(double radius) {
        return 2 * radius * Math.PI;
    }
}
class Cylinder extends Circle {
    protected double height;
    public Cylinder (double x, double y, double radius, double height) {
        super(x, y, radius);
        if (height > 0) {
        this.height = height;
        }
    }
    @Override public String getName() {
        return "Cylinder";
    }
    @Override public double calArea() {
        return calArea(radius, height);
    }
    public double calArea (double radius, double height) { // surface area
        return 2 * super.calArea(radius) + super.calCircumference(radius) * height;
    }
    @Override public double calVolume() {
        return calVolume(radius, height);
    }
    public double calVolume (double radius, double height) {
        return super.calArea(radius) * height;
    }
}
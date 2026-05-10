public class ShapeTest {
    public static void main(String[] args) {
        Shape shapes[] = new Shape[3];
        shapes[0] = new Point (-2, 2);
        shapes[1] = new Circle (-2, 2, 5);
        shapes[2] = new Cylinder (-2, 2, 5, 10);
        for (Shape shape: shapes) {
            System.out.println("Shape type: " + shape.getName());
            System.out.println("Area: " + shape.calArea());
            System.out.println("Volume: " + shape.calVolume());
            System.out.println("-------");
        }
        Point point = (Point) shapes[0]; // casting object of superclass Shape to subclass Point
        System.out.println("Point is in quadrant " + point.getQuadrant());
        System.out.println("Distance of Point from origin: " + point.getDistanceFromOrigin());
    }
}
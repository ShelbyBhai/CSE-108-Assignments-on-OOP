import java.util.Scanner;
abstract class Shape implements AreaImpl
{
    abstract public double area();
}
class Circle extends Shape implements AreaImpl
{
    double radius;
    static int  countcir=0;
    Circle(double r)
    {
        this.radius = r;
        countcir++;
    }
    public  double area()
    {
        return  3.14159*radius*radius;
    }
}
class Square extends Shape implements AreaImpl
{
    double side;
    static int countsqr=0;
    public    double area()
    {
        return side*side;
    }
    Square(double s)
    {
        this.side=s;
        countsqr++;
    }
}
class Cube extends Square implements AreaImpl
{
    static int countcube=0;
    Cube(double l)
    {
        super(l);
        countcube++;
        countsqr--;
    }
    public double volume()
    {
        return side*side*side;
    }
}
class Cylinder extends Circle implements  AreaImpl,VolumeImpl
{
    static int countcyl=0;
    double heigth;
    Cylinder(double h,double r)
    {
        super(r);
        this.heigth=h;
        this.radius=r;
        countcyl++;
        countcir--;
    }
    double basearea()
    {
        return area();
    }
    public  double surfarea()
    {
        return (2 * area()) + (2 * 3.1416 * radius * heigth);
    }
    public double volume()
    {
        return basearea()*heigth;
    }
}
class Sphere extends Circle implements VolumeImpl , AreaImpl
{
    static int countsphr=0;
    Sphere(double rad)
    {
        super(rad);
        countsphr++;
        countcir--;
    }
    public   double volume()
    {
        return (4*area()*radius)/3;
    }
}
class NegativeValueException extends Exception
{
    public NegativeValueException(String warning)
    {
        super(warning);
    }
}
public class ShapesTesting
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        while (true)
        {
            System.out.println("Enter The Shape : ");
            System.out.println("1. Circle");
            System.out.println("2. Square");
            System.out.println("3. Cylinder");
            System.out.println("4. Cube");
            System.out.println("5. Sphere");
            System.out.println("6. Exit from here");
            int choice = input.nextInt();
            input.nextLine();
            switch (choice) {
                case 1:
                    try {
                        System.out.println("Enter the radius : ");
                        double radi = input.nextDouble();
                        input.nextLine();
                        option(radi);
                        Circle c = new Circle(radi);
                        System.out.println("Name : Circle" + Circle.countcir);
                        System.out.println("Area : " + c.area());
                    } catch (NegativeValueException ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 2:
                    try {
                        System.out.println("Enter the length : ");
                        double radi = input.nextDouble();
                        input.nextLine();
                        option(radi);
                        Square s = new Square(radi);
                        System.out.println("Name : Square" + Square.countsqr);
                        System.out.println("Area : " + s.area());
                    } catch (NegativeValueException ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 3:
                    try {
                        System.out.println("Enter the radius : ");
                        double radi = input.nextDouble();
                        input.nextLine();
                        option(radi);
                        System.out.println("Enter the height : ");
                        double hght = input.nextDouble();
                        input.nextLine();
                        option(hght);
                        Cylinder cyl = new Cylinder(hght,radi);
                        System.out.println("Name : Cylinder" + Cylinder.countcyl);
                        System.out.println("Area of the base : " + cyl.basearea());
                        System.out.println("Area of Surface : " + cyl.surfarea());
                        System.out.println("Volume : " + cyl.volume());
                    } catch (NegativeValueException ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 4:
                    try {
                        System.out.println("Enter the length : ");
                        double radi = input.nextDouble();
                        input.nextLine();
                        option(radi);
                        Cube c = new Cube(radi);
                        System.out.println("Name : Cube" + Cube.countcube);
                        System.out.print("Volume : ");
                        System.out.println(c.volume());
                    } catch (NegativeValueException ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 5:
                    try {
                        System.out.println("Enter the radius : ");
                        double radi = input.nextDouble();
                        input.nextLine();
                        option(radi);
                        Sphere sp = new Sphere(radi);
                        System.out.println("Name : Sphere" + Sphere.countsphr);
                        System.out.print("Volume : ");
                        System.out.println(sp.volume());
                    } catch (NegativeValueException ex) {
                        System.out.println(ex.getMessage());
                    }
                    break;
                case 6:
                    return;
                default:
                    System.out.println("Please give a valid input(1-6)!!");
                    break;
            }
        }
    }
    public static void option ( double er) throws NegativeValueException
    {
        if (er < 0)
        {
            throw new NegativeValueException("You can not enter a negative value.");
        }
        else
            return;
    }
}


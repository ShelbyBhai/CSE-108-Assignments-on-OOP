#include<iostream>
using namespace std;

typedef enum {UNDEFINED, POINT2D, POINT3D, CIRCLE, SQUARE, RECTANGLE, SPHERE} STYPE;


//********* Shape *********

class Shape
{
    STYPE type;
public:
    Shape();
    Shape(STYPE type);
    virtual void print();
    virtual double area();
    virtual bool contains(const Shape *s);
    //Intentionally made non-virtual
    bool operator==(const Shape &rhs);
    virtual ~Shape() {}
};

Shape::Shape()
{
    type = UNDEFINED;
}

Shape::Shape(STYPE argtype)
{
    type = argtype;
}

double Shape::area()
{
    cout << "I am a dummy Shape";
    return 0.0;
}

bool Shape::contains(const Shape *rhs)
{
    cout << "You see this, because appropriate contains function is undefined";
    return false;
}

void Shape::print()
{
    cout << "Type: " << type;
}

bool Shape::operator==(const Shape &rhs)
{
    return (type == rhs.type);
}

//********* Point2D : Shape *********


class Point2D : public Shape
{
    double x,y;
public:
    Point2D();
    Point2D(STYPE argtype, int argx, int argy);
    void print();
    double area();
    bool contains(const Shape * rhs);
    bool contains(const Point2D * rhs);
    bool operator==(const Point2D &rhs);

    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    ~Point2D() {}
};

Point2D::Point2D() //calls Base's default constructor
{
    x = 0.0;
    y = 0.0;
}

Point2D::Point2D(STYPE argtype, int argx, int argy) : Shape(argtype)
{
    x = argx;
    y = argy;
}

void Point2D::print()
{
    Shape::print();
    cout << " (" << x << "," << y << ")";
}

double Point2D::area()
{
    return 0.0;
}

bool Point2D::contains(const Shape *s)
{
    const Point2D * pointType = dynamic_cast<const Point2D*>(s);
    if(pointType!=NULL)
    {
        //Supported
        return contains(pointType);
    }
    //By default, use base
    return Shape::contains(s);
}

bool Point2D::contains(const Point2D * rhs)
{
    return (x == rhs->x && y == rhs->y);
}

bool Point2D::operator==(const Point2D & rhs)
{
    if( !Shape::operator==(rhs) ) return false;
    return (x == rhs.x && y == rhs.y);
}

//********* Rectangle : Shape *********

class Rectangle : public Shape
{
    Point2D topRight;
    Point2D bottomLeft;
public:
    Rectangle();//implement this
    Rectangle(STYPE type, Point2D tr, Point2D bl);//implement this
    void print(); //implement this
    double area(); //implement this
    bool contains(const Shape *rhs); //implement this to check containment for point2d only
    bool operator==(const Rectangle &rhs); //implement this
    Point2D gettopright() const
    {
        return topRight;
    }
    Point2D getbottomleft() const
    {
        return bottomLeft;
    }
    ~Rectangle() {}
};

Rectangle::Rectangle()
{
    Point2D tr(UNDEFINED,0,0);
    Point2D bl(UNDEFINED,0,0);
}

Rectangle::Rectangle(STYPE type, Point2D tr, Point2D bl):Shape(type)
{
    topRight=tr;
    bottomLeft=bl;
}

void Rectangle::print()
{
    Shape::print();
    topRight.print();
    cout<<"\n";
    bottomLeft.print();
}

double Rectangle::area()
{
    if(!((topRight.getX()&& topRight.getY()&& bottomLeft.getX() && bottomLeft.getY())))
        return Shape::area();
    else
    {
        double a;
        a=((topRight.getX()-bottomLeft.getX())*(topRight.getY()-bottomLeft.getY()));
        if(a<0)
            return -a;
        else return a;
    }
}

bool Rectangle::contains(const Shape *rhs)
{
    const Point2D * pointType = dynamic_cast<const Point2D*>(rhs);
    if(pointType!=NULL)
    {
        bool c1,c2;
        c1=(topRight.getX()>=pointType->getX() && bottomLeft.getX()<=pointType->getX());
        c2=(topRight.getY()>=pointType->getY() && bottomLeft.getY()<=pointType->getY());
        if(c1 && c2)
            return true;
        else return false;
    }
    return Shape::contains(rhs);
}

bool Rectangle::operator==(const Rectangle &rhs)
{
    if(!Shape::operator==(rhs)) return false;
    return ((topRight==rhs.topRight) && (bottomLeft==rhs.bottomLeft));
}


//********* Circle : Shape *********

class Circle : public Shape
{
    Point2D center;
    double radius;
public:
    Circle();
    Circle(STYPE type, Point2D c, double r); //implement this
    double area(); //implement this
    void print();
    void setradius(double r)
    {
        radius=r;
    }
    void setcenter(Point2D p)
    {
        center=p;
    }
    double getradius()
    {
        return radius;
    }
    Point2D getcenter()
    {
        return center;
    }
    bool contains(const Shape * s); //implemented partially
    bool contains(const Point2D * p); //implement this
    bool contains(const Circle * rhs); //implement this
    bool contains(const Rectangle * p); //implement this
    bool operator==(const Circle &rhs); //implement this
    ~Circle() {}
};

bool Circle::contains(const Shape * s)
{
    const Point2D * pointType = dynamic_cast<const Point2D*>(s);
    if(pointType!= NULL)
    {
        //Supported
        return contains(pointType);
    }
    const Circle * circleType = dynamic_cast<const Circle*>(s);
    if(circleType!= NULL)
    {
        //Supported
        return contains(circleType);
    }
    const Rectangle * rectangleType = dynamic_cast<const Rectangle*>(s);
    if(rectangleType!= NULL)
    {
        //Supported
        return contains(rectangleType);
    }
    //By default
    return Shape::contains(s);
}

Circle::Circle()
{
    radius=0.0;
}

Circle::Circle(STYPE type, Point2D c, double r)
{
    center=c;
    radius=r;
}

double Circle::area()
{
    if(!radius)
        return Shape::area();
    else
        return 3.14159*radius*radius;
}

void Circle::print()
{
    Shape::print();
    center.print();
    cout<<"radius is: "<<radius<<endl;
}

bool Circle::contains(const Point2D *p)
{
    double d,x,y;
    x=(center.getX()-p->getX())*(center.getX()-p->getX());
    y=(center.getY()-p->getY())*(center.getY()-p->getY());
    d=x+y;
    if(d<=radius*radius)
    {
        return true;
    }
    return false;
}

bool Circle::contains(const Circle *rhs)
{
    double d1,d2,x,y;
    x=(center.getX()-rhs->center.getX())*(center.getX()-rhs->center.getX());
    y=(center.getY()-rhs->center.getY())*(center.getY()-rhs->center.getY());
    d1=x+y;
    d2=radius-rhs->radius;
    if(d2>d1)
        return true;
    else return false;
}

bool Circle::contains(const Rectangle *p)
{
    Point2D p2,p4;
    bool chck1,chck2;
    p2=p->getbottomleft();
    p4=p->gettopright();
    chck1=contains(&p2);
    chck2=contains(&p4);
    if(chck1 && chck2)
        return true;
    else return false;
}

bool Circle::operator==(const Circle &rhs)
{
    if( !Shape::operator==(rhs) ) return false;
    return radius==rhs.radius;
}




//********* Shape3D : Shape *********

class Shape3D : public Shape
{
public:
    Shape3D();
    Shape3D(STYPE type);
    virtual double volume();
    ~Shape3D() {}
};

Shape3D::Shape3D():Shape(UNDEFINED)
{

}

Shape3D::Shape3D(STYPE argtype) : Shape(argtype)
{

}

double Shape3D::volume()
{
    cout << "You see this, because appropriate function is missing in the derived class";
    return 0.0;
}

//********* Point3D : Point2D, Shape3D *********

class Point3D : virtual public Point2D, virtual public Shape3D
{
    double z;
public:
    Point3D(); //already implemented
    Point3D(STYPE type, double argx, double argy, double argz); //implement this
    virtual void print(); //already implemented
    //double area(); Not needed, base version is sufficient
    double getz()const
    {
        return z;
    }
    bool contains(const Shape *rhs); //implement this
    bool contains(const Point3D *rhs);  //implement this
    ~Point3D() {}
};

Point3D::Point3D()
{
    z = 0;
}

void Point3D::print()
{
    Shape3D::print();
    cout << " (" << Point2D::getX() << "," << Point2D::getY() << "," << z << ")";
}

Point3D::Point3D(STYPE type, double argx, double argy, double argz):Shape3D(POINT3D),Point2D(POINT2D,argx,argy)
{
    z=argz;
}

bool Point3D::contains(const Shape *rhs)
{
    const Point3D * pointType = dynamic_cast<const Point3D*>(rhs);
    if(pointType!=NULL)
    {
        return contains(pointType);
    }
    return Point2D::contains(rhs);
}

bool Point3D::contains(const Point3D *rhs)
{
    Point2D p1(POINT2D,rhs->getX(),rhs->getY()),p2(POINT2D,this->getX(),this->getY());
    if(p1==p2 && z==rhs->z)
        return true;
    else return false;
}


//********* Sphere : Shape3D *********

class Sphere : public Shape3D
{
    Point3D center;
    double radius;
public:
    Sphere();//implement this
    Sphere(STYPE type, Point3D c, double r);//implement this
    void print(); //implement this
    double area(); //implement this
    double volume(); //implement this
    Point3D getcenter()const
    {
        return center;
    }
    double getradius()const
    {
        return radius;
    }
    bool contains(const Shape * rhs); //implement this for checking containgment of Point3D, Sphere inside sphere
    bool contains(const Point3D * p); //implement this
    bool contains(const Sphere * s); //implement this
    ~Sphere() {}
};

Sphere::Sphere()
{
    Point3D c(UNDEFINED,0,0,0);
    center=c;
    radius=0.0;
}

Sphere::Sphere(STYPE type, Point3D c, double r):Shape3D(type)
{
    center=c;
    radius=r;
}

void Sphere::print()
{
    center.print();
    cout<<"radius is: "<<radius<<endl;
    Shape::print();
}

double Sphere::area()
{
    if(!radius)
        return Shape::area();
    else
        return 4*3.14159*radius*radius;
}

double Sphere::volume()
{
    if(!radius)
        return Shape3D::volume();
    else
        return (4*3.14159*radius*radius*radius)/3;
}

bool Sphere::contains(const Shape *rhs)
{
    const Point3D * pointType = dynamic_cast<const Point3D*>(rhs);
    if(pointType!=NULL)
    {
        return contains(pointType);
    }
    const Sphere * sphereType = dynamic_cast<const Sphere*>(rhs);
    if(sphereType!=NULL)
    {
        return contains(sphereType);
    }
    return Shape::contains(rhs);
}

bool Sphere::contains(const Point3D *p)
{
    double x,y,z,d3,d4;
    x=(center.getX()-p->getX())*(center.getX()-p->getX());
    y=(center.getY()-p->getY())*(center.getY()-p->getY());
    z=(center.getz()-p->getz())*(center.getz()-p->getz());
    d3=x+y+z;
    d4=radius*radius;
    if(d3<=d4)
        return true;
    else
        return false;
}

bool Sphere::contains(const Sphere *s)
{
    double x,y,z,d3,d4;
    x=(center.getX()-s->center.getX())*(center.getX()-s->center.getX());
    y=(center.getY()-s->center.getY())*(center.getY()-s->center.getY());
    z=(center.getz()-s->center.getz())*(center.getz()-s->center.getz());
    d3=x+y+z;
    d4=radius-s->radius;
    if(d3<=d4)
        return false;
}


int main(void)
{
    //Write main function to demonstrate your code
    //Create circles, rectanges, point2d,point3d,and sphere objects using base class pointers
    //then call the virtual methods to show that polymorphism works!
    while(1)
    {
        int choice = 10;
        Shape  *shape1,*shape2;
        Shape3D * shape3D1,*shape3D2;

        cout << "1. Point2D 2. Rectangle 3. Circle\n";
        cout << "4. Point3D 5. Sphere. 0. Exit\n";
        cout << "Your choice:";
        cin >> choice;
        switch(choice)
        {
        case 1:
        {
            shape1 = new Point2D(POINT2D, 5.0,10.0);
            shape1->print();
            cout<<"\n";
            break;
        }
        case 2:
        {
            Point2D p1(POINT2D,20.0,20.0);
            cout<<"\n";
            Point2D p2(POINT2D,5.0,5.0);
            cout<<"\n";
            Shape*shape3=new Point2D(POINT2D,10,10);
            shape1= new Rectangle(RECTANGLE, p1, p2);
            shape2=new Rectangle(RECTANGLE,p1,p2);
            shape1->print();
            cout << "\nArea: \n" << shape1->area();
            cout<<"\n";
            if(shape1->contains(shape3))
                cout<<"contains\n";
            else cout<<"does not contain";
            delete shape1;
            delete shape2;
            delete shape3;
            break;
        }
        case 3:
        {
            Point2D p1(POINT2D,0.0,0.0);
            Point2D p2(POINT2D,4.0,4.0);
            Shape*shape3=new Point2D(POINT2D,1,1);
            shape1 = new Circle(CIRCLE,p1,10.0);
            shape2=new Circle(CIRCLE,p1,5.0);
            Shape*shape4=new Rectangle(RECTANGLE,p2,p1);
            shape1->print();
            cout<<"\nArea: "<<shape1->area();
            cout<<"\n";
            if(shape1->contains(shape3))cout<<"contains point"<<endl;
            else cout<<"not contains point"<<endl;
            if(shape1->contains(shape2))cout<<"contains circle"<<endl;
            else cout<<"does not contain circle"<<endl;
            if(shape1->contains(shape4))cout<<"contains rectangle"<<endl;
            else cout<<"does not contain rectangle"<<endl;
            delete shape1;
            delete shape2;
            delete shape3;
            delete shape4;
            break;
        }
        case 4:
        {
            shape3D1 = new Point3D(POINT3D,5.0,10.0,20.0);
            shape3D2=new Point3D(POINT3D,5.0,10.0,20.0);
            shape3D1->print();
            cout << "\nArea: " << shape3D1->area();
            cout << "\nVolume: " << shape3D1->volume();
            if(shape3D1->contains(shape3D2))cout<<"contains"<<endl;
            else cout<<"does not contain"<<endl;
            delete shape3D1;
            delete shape3D2;
            break;
        }
        case 5:
        {
            Point3D p1(POINT3D,0.0,0.0,0.0);
            shape3D1 = new Sphere(SPHERE,p1,10.0);
            shape3D2=new Sphere(SPHERE,p1,5.0);
            Shape3D*shape3D3=new Point3D(POINT3D,0.0,2.0,0.0);
            shape3D1->print();
            cout << "\nArea: " << shape3D1->area();
            cout << "\nVolume: " << shape3D1->volume();
            if(shape3D1->contains(shape3D2))cout<<"contains sphere"<<endl;
            else cout<<"does not contain sphere"<<endl;
            if(shape3D1->contains(shape3D3))cout<<"contains point"<<endl;
            else cout<<"does not contain point"<<endl;
            delete shape3D1;
            delete shape3D2;
            delete shape3D3;
            break;
        }
        }
        if(choice==0)
            break;
    }


    return 0;
}

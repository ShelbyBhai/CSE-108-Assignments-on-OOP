#include<iostream>
#include<cmath>
using namespace std;


class Point2D
{
    double x,y;
public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(double argx, double argy)
    {
        x=argx;
        y=argy;
    }
    void setX(double x);
    void setY(double y);
    double getX();
    double getY();
    void print();
    ~Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D operator+(Point2D p2);
    Point2D operator*(double n);
    bool operator==(Point2D p);
    bool operator!=(Point2D p);
};


Point2D Point2D::operator+(Point2D p2)
{
    Point2D result_add;
    result_add.x=x+p2.x;
    result_add.y=y+p2.y;
    return result_add;
}


Point2D Point2D::operator*(double n)
{
    Point2D result_mult;
    result_mult.x=x*n;
    result_mult.y=y*n;
    return result_mult;
}
bool Point2D::operator==(Point2D p)
{
    return (x==p.x && y==p.y);
}
bool Point2D::operator!=(Point2D p)
{
    return (x!=p.x || y!=p.y);
}

void Point2D::setX(double argx)
{

    x=argx;

}

void Point2D::setY(double argy)
{

    y=argy;

}

double Point2D::getX()
{
    return x;
}

double Point2D::getY()
{
    return y;
}

void Point2D::print()
{
    cout << "(" << x << "," << y << ")";
}

class Circle
{
    Point2D center;
    double radius;
public:
    Circle()
    {
        center.setX(0);
        center.setY(0);
        radius=0;
    }
    Circle(Point2D c, double r);
    void setcenter(Point2D c)
    {
        center=c;
    };
    void setradius(double r)
    {
        radius=r;
    };
    Point2D getcenter()
    {
        return center;
    };
    double getradius()
    {
        return radius;
    };


    void print();
    Circle operator+(Point2D p);
    Circle operator+(Circle rhs);
    Circle operator*(double n);
    Circle operator-(Circle rhs);
    bool operator==(Circle rhs);
    bool operator>=(Circle rhs);
    bool operator>(Circle rhs);
    bool operator<(Circle rhs);
    bool operator<=(Circle rhs);
    Circle operator++();
    Circle operator++(int unused);
    ~Circle()
    {
        center.setX(0);
        center.setY(0);
        radius=0;
    }
};

Circle::Circle(Point2D c, double r)
{
    center=c;
    radius=r;

}
void Circle::print()
{
    cout << "Center: ";
    center.print();
    cout<<"\n";
    cout << "Radius: " << radius;
}
Circle Circle::operator+(Point2D p)
{
    Circle c;
    c.center.setX(center.getX()+p.getX());
    c.center.setY(center.getY()+p.getY());
    c.setradius(getradius());
    return c;
}
Circle Circle::operator*(double n)
{
    Circle c;
    c.center.setX(center.getX()*n);
    c.center.setY(center.getY()*n);
    c.setradius(getradius()*n);
    return c;
}
Circle Circle::operator+(Circle rhs)
{
    Circle c;
    double a;
    a=(radius)/(radius+rhs.radius);
    c.center=(center*a)+(rhs.center*(1-a));
    c.radius=radius+rhs.radius;
    return c;
}
Circle Circle::operator-(Circle rhs)
{
    Circle c;
    double a;
    a=(radius)/(radius+rhs.radius);
    c.center=(center*a)+(rhs.center*(1-a));
    c.radius=radius-rhs.radius;
    return c;
}
bool Circle::operator==(Circle rhs)
{
    return (3.1416*radius*radius==3.1416*rhs.radius*rhs.radius);
}
bool Circle::operator>(Circle rhs)
{
    return (3.1416*radius*radius>3.1416*rhs.radius*rhs.radius);
}
bool Circle::operator>=(Circle rhs)
{
    return (3.1416*radius*radius>=3.1416*rhs.radius*rhs.radius);
}
bool Circle::operator<(Circle rhs)
{
    return (3.1416*radius*radius<3.1416*rhs.radius*rhs.radius);
}
bool Circle::operator<=(Circle rhs)
{
    return (3.1416*radius*radius<=3.1416*rhs.radius*rhs.radius);
}
Circle Circle::operator++(int unused)//postfix
{
    Circle c;
    c.radius=radius;
    c.center=center;
    radius++;
    return c;
}
Circle Circle::operator++()//prefix
{
    Circle c;
    radius++;
    c.radius=radius;
    c.center=center;
    return c;
}
class Rectangle
{
    Point2D tR,bL;

public:
    Rectangle()
    {
        tR.setX(0);
        tR.setY(0);
        bL.setX(0);
        bL.setY(0);
    }
    Rectangle(Point2D tr,Point2D bl);
    void settR(Point2D tr)
    {
        tR=tr;
    }
    void setbL(Point2D bl)
    {
        bL=bl;
    }
    Point2D gettR()
    {
        return tR;
    }
    Point2D getbL()
    {
        return bL;
    }
    void print();
    Rectangle operator+(Point2D p);
    Rectangle operator*(int n);
    ~Rectangle()
    {
        tR.setX(0);
        tR.setY(0);
        bL.setX(0);
        bL.setY(0);
    }
};
Rectangle::Rectangle(Point2D tr,Point2D bl)
{
    tR=tr;
    bL=bl;
}
void Rectangle::print()
{
    cout<<"bottom left: "<<"\n";
    bL.print();
    cout<<"\n";
    cout<<"top right: "<<"\n";
    tR.print();
}
Rectangle Rectangle::operator+(Point2D p)
{
    Rectangle obj;
    obj.tR.setX(tR.getX()+p.getX());
    obj.tR.setY(tR.getY()+p.getY());
    obj.bL.setX(bL.getX()+p.getX());
    obj.bL.setY(bL.getY()+p.getY());
    return obj;
}
Rectangle Rectangle::operator*(int n)
{
    Rectangle obj;
    obj.tR.setX(tR.getX()*n);
    obj.tR.setY(tR.getY()*n);
    obj.bL.setX(bL.getX()*n);
    obj.bL.setY(bL.getY()*n);
    return obj;
}
int main(void)
{

    Point2D p1(2,3);
    p1.print();
    cout<<"\n";
    Point2D p2(3,4);
    p2.print();
    cout<<"\n";
    Point2D p;
    p=p1+p2;
    p.print();
    cout<<"\n";
    int n;
    cout << "Please enter the value of 'n' : ";
    cin>>n;
    p=p1*n;
    p.print();
    cout<<"\n";
    if(p1==p2)
        cout<<"they are same points"<<endl;
    if(p1!=p2)
        cout<<"they are not same points"<<endl;
    Circle c1,c2,c3,c_new;
    p.setX(5);
    p.setY(5);
    c1.setcenter(p);
    c1.setradius(10);
    c1.print();
    cout<<"\n";
    p.setX(10);
    p.setY(6);
    c2.setcenter(p);
    c2.setradius(8);
    c2.print();
    cout<<"\n";
    p.setX(5);
    p.setY(5);
    c3.setcenter(p);
    c3.setradius(10);
    c3.print();
    cout<<"\n";
    c_new=c3++;
    c_new.print();
    cout<<"\n";
    (++c3).print();
    cout<<"\n";
    Point2D p3(5,5);
    p3.print();
    cout<<"\n";
    c_new=c3+p3;
    c_new.print();
    cout<<"\n";
    cout << "Please enter the value of 'n' : ";
    cin>>n;
    c_new=c3*n;
    c_new.print();
    cout<<"\n";
    if(c1==c2)
        cout<<"they have the same area"<<endl;
    if(c1>c2)
        cout<<"circle 1 is greater than circle 2"<<endl;
    if(c1>=c2)
        cout<<"circle 1 is greater than or equal to circle 2"<<endl;
    if(c1<c2)
        cout<<"circle 1 is less than circle 2"<<endl;
    if(c1<=c2)
        cout<<"circle 1 is less than or equal to circle 2"<<endl;
    c_new=c1+c2;
    c_new.print();
    cout<<"\n";
    c_new=c1-c2;
    c_new.print();
    cout<<"\n";
    Point2D p4(2,2);
    Rectangle r1,r_new;
    p.setX(10);
    p.setY(15);
    r1.setbL(p);
    p.setX(15);
    p.setY(20);
    r1.settR(p);
    r1.print();
    cout<<"\n";
    r_new=r1+p4;
    r_new.print();
    cout<<"\n";
    cout << "Please enter the value of 'n' : ";
    cin>>n;
    r_new=r1*n;
    r_new.print();
}

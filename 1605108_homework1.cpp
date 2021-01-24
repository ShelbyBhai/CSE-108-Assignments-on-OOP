#include<iostream>
#include<cmath>
using namespace std;


class Point2D
{
    int x,y;
public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(int x, int y);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void print();
    ~Point2D()
    {
        x = 0;
        y = 0;
    }
};

Point2D::Point2D(int argx,int argy)
{
    x = argx;
    y = argy;
}

void Point2D::setX(int argx)
{

    x=argx;

}

void Point2D::setY(int argy)
{

    y=argy;

}

int Point2D::getX()
{
    return x;
}

int Point2D::getY()
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

    double area();
    void print();
    int intersect(Circle rhs);
    int contains(Circle rhs);
    int contains(Point2D p);
    double perimeter();
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

double Circle::area()
{
    return 3.1416*radius*radius;
}
double Circle::perimeter()
{
    return 2*3.1416*radius;
}
int Circle::intersect(Circle rhs)
{
    if((rhs.radius+radius)>sqrt(pow(rhs.center.getX()-center.getX(),2)+pow(rhs.center.getY()-center.getY(),2)))
        return 1;
    else
        return 0;

}

int Circle::contains(Circle rhs)
{
    if(radius>sqrt(pow(rhs.center.getX()-center.getX(),2)+pow(rhs.center.getY()-center.getY(),2))+rhs.radius)
        return 1;
    else
        return 0;

}
int Circle::contains(Point2D p)
{
    if(pow(center.getX()-p.getX(),2)+pow(center.getY()-p.getY(),2)-pow(radius,2)<=0)
        return 1;
    else
        return 0;
}

void Circle::print()
{
    cout << "Center: ";
    center.print();
    cout << "Radius: " << radius;
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
    double area();
    int intersect(Rectangle rhs);
    int contains(Rectangle rhs);
    int inside(Circle c);
    double perimeter();
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
double Rectangle::area()
{
    return (tR.getX()-bL.getX())*(tR.getY()-bL.getY());
}
double Rectangle::perimeter()
{
    return 2*((tR.getX()-bL.getX())+(tR.getY()-bL.getY()));
}
int Rectangle::contains(Rectangle rhs)
{
    if((rhs.bL.getX()>bL.getX())&&(rhs.bL.getY()>bL.getY())&&(rhs.tR.getX()<tR.getX())&&(rhs.tR.getY()<tR.getY()))
        return 1;
    else
        return 0;
}
int Rectangle::inside(Circle c)
{
    if((sqrt((pow(c.getcenter().getX()-bL.getX(),2))+(pow(c.getcenter().getY()-bL.getY(),2)))<c.getradius())&&(sqrt((pow(c.getcenter().getX()-tR.getX(),2))+(pow(c.getcenter().getY()-tR.getY(),2)))<c.getradius()))
        return 1;
    else
        return 0;

}
int Rectangle:: intersect(Rectangle rhs)
{
    if((bL.getX()<rhs.tR.getX())||(bL.getY()<rhs.tR.getY())||(tR.getX()<rhs.bL.getX())||(tR.getY()<rhs.bL.getY()))
        return 0;
    else
        return 1;
}

int main(void)
{
    int a,b,r,px,py;
    Point2D c,p;
    Circle c1,c2,c3;
    cout<<"enter the center of circle 1: "<<endl;
    cin>>a>>b;
    cout<<"enter the radius of circle 1: "<<endl;
    cin>>r;
    c.setX(a);
    c.setY(b);
    c1.setcenter(c);
    c1.setradius(r);
    cout<<"area of circle 1: "<<c1.area()<<endl;
    cout<<"perimeter of circle 1: "<<c1.perimeter()<<endl;
    cout<<"enter the center of circle 2: "<<endl;
    cin>>a>>b;
    cout<<"enter the radius of circle 2: "<<endl;
    cin>>r;
    c.setX(a);
    c.setY(b);
    c2.setcenter(c);
    c2.setradius(r);
    cout<<"area of circle 2: "<<c2.area()<<endl;
    cout<<"perimeter of circle 2: "<<c2.perimeter()<<endl;
    if(c1.intersect(c2) && !(c1.contains(c2)))
    {
        cout<<"two circles intersect each other"<<endl;
    }
    else
    {
        cout<<"two circles don't intersect with each other"<<endl;
    }
    if(c1.contains(c2))
    {
        cout<<"circle 1 contains circle 2"<<endl;
    }
    else
    {
        cout<<"circle 1 does not contain circle 2"<<endl;
    }
    cout<<"enter the center of circle 3: "<<endl;
    cin>>a>>b;
    cout<<"enter the radius of circle 3: "<<endl;
    cin>>r;
    c.setX(a);
    c.setY(b);
    c3.setcenter(c);
    c3.setradius(r);
    cout<<"area of circle 3: "<<c3.area()<<endl;
    cout<<"perimeter of circle 3: "<<c3.perimeter()<<endl;
    cout<<"enter the point p: "<<endl;
    cin>>px>>py;
    p.setX(px);
    p.setY(py);
    if(c3.contains(p))
    {
        cout<<"circle 3 contains point p"<<endl;
    }
    else
    {
        cout<<"circle 3 does not contain point p"<<endl;
    }
    Rectangle r1,r2;
    Point2D bl,tr;
    Circle c4;
    int blx,bly,trx,tr_y;
    cout<<"enter the bottom left point of rectangle 1: "<<endl;
    cin>>blx>>bly;
    bl.setX(blx);
    bl.setY(bly);
    r1.setbL(bl);
    cout<<"enter the top right point of rectangle 1: "<<endl;
    cin>>trx>>tr_y;
    tr.setX(trx);
    tr.setY(tr_y);
    r1.settR(tr);
    cout<<"area of rectangle 1: "<<r1.area()<<endl;
    cout<<"perimeter of rectangle 1: "<<r1.perimeter()<<endl;
    cout<<"enter the bottom left point of rectangle 2: "<<endl;
    cin>>blx>>bly;
    bl.setX(blx);
    bl.setY(bly);
    r2.setbL(bl);
    cout<<"enter the top right point of rectangle 2: "<<endl;
    cin>>trx>>tr_y;
    tr.setX(trx);
    tr.setY(tr_y);
    r2.settR(tr);
    cout<<"area of rectangle 2: "<<r2.area()<<endl;
    cout<<"perimeter of rectangle 2: "<<r2.perimeter()<<endl;
    if(r1.intersect(r2))
    {
        cout<<"rectangle 1 intersects with rectangle 2"<<endl;
    }
    else
    {
        cout<<"rectangle 1 does not intersect with rectangle 2"<<endl;
    }
    if(r1.contains(r2))
    {
        cout<<"rectangle 1 contains rectangle 2"<<endl;
    }
    else
    {
        cout<<"rectangle 1 does not contain rectangle 2"<<endl;
    }
    cout<<"enter the center of circle 4: "<<endl;
    cin>>a>>b;
    cout<<"enter the radius of circle 4: "<<endl;
    cin>>r;
    c.setX(a);
    c.setY(b);
    c4.setcenter(c);
    c4.setradius(r);
    if(r1.inside(c4))
    {
        cout<<"rectangle 1 is inside circle 4"<<endl;
    }
    else
    {
        cout<<"rectangle 1 is not inside circle 4"<<endl;
    }
    return 0;
}

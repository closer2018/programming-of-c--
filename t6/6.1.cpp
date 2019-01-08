/*1.设计一个基类，从基类派生圆柱，设计成员函数输出它们的面积和体积；*/

#include <iostream>
using namespace std;
/*********************************************************************/
//点类
class Point{
    protected:
        double x_; double y_;
    public:
        Point() {}
        Point(int a,int b): x_(a), y_(b) {}
        double Getx() const {return x_;}
        double Gety() const {return y_;}
};
//圆类
class Circle:public Point{
    protected:
        double radius_;//半径
    public:
        Circle() {}
        Circle(double a, double b, double c):
            Point(a,b), radius_(c) {}
        double GetArea(Circle) const; //求面积
};
//圆柱类
class Cylinder:public Circle{
    protected:
        double high_;
    public:
        Cylinder(){}
        Cylinder(double a, double b, double c, double d):
            Circle(a,b,c),high_(d) {}
        double GetVolume(Cylinder) const; //求体积
};
//常量Pi
const double Pi = 3.14159265359;
/*********************************************************************/
int main()
{
    double x, y, high, r;

    cout<<"输入点的坐标:";
    cin>>x>>y;
    cout<<"输入半径和高:";
    cin>>r>>high;

    Cylinder obj(x,y,r,high);
    cout<<"面积是:"<<obj.GetArea(obj)<<endl;
    cout<<"体积是:"<<obj.GetVolume(obj)<<endl;

    return 0;
}
/*********************************************************************/
//函数定义
double Circle::GetArea(Circle a) const{//求面积
    return (2 * Pi * a.radius_ * a.radius_);
}

double Cylinder::GetVolume(Cylinder a) const{//求体积
    return (a.GetArea(a) * a.high_);
}


/*1.设计一个点类Point，再设计一个矩形类，矩形类使用Point类的两个坐标点
作为矩形对角顶点，并可以输出4个坐标值和面积。使用测试程序验证程序。*/
#include <iostream>
using namespace std;

class Point{
private:
    double x;
    double y;
public:
    Point(){x = 0; y = 0;};
    Point(double a,double b){
        x = a;y = b;
    }
    double getx(){return x;}
    double gety(){return y;}

};
class Rectangle{
private:
    Point a;Point b;
public:
    Rectangle(){};
    Rectangle(Point x,Point y){
        a = x;
        b = y;
    }
    void print(Point &,Point &);

};

int main()
{
    Point a(11,211),b(32,44);
    Rectangle rect(a,b);
    rect.print(a,b);

    return 0;
}

void Rectangle::print(Point &a,Point &b){
    Point c(a.getx(), b.gety()) , d(b.getx(), a.gety());
    cout<<"a坐标是: ("<<a.getx()<<"\t,"<<a.gety()<<")"<<endl;
    cout<<"b坐标是: ("<<b.getx()<<"\t,"<<b.gety()<<")"<<endl;
    cout<<"c坐标是: ("<<c.getx()<<"\t,"<<c.gety()<<")"<<endl;
    cout<<"d坐标是: ("<<d.getx()<<"\t,"<<d.gety()<<")"<<endl;

    double area = (a.getx() - b.getx()) * (a.gety() - b.gety()) * 2;
    area = (area >=  0? area:(-area));
    cout<<"面积是："<<area<<endl;
}

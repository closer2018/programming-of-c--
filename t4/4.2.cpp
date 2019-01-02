/*2.使用内联函数设计一个类，
用来表示直角坐标系中的任意一条直线并输出它的属性*/
#include <iostream>
#include <cmath>
using namespace std;

class Point{
private:
    double x;
    double y;
public:
    Point():x(0),y(0){}
    Point(double a,double b) : x(a),y(b){}
    double getx(){return x;}
    double gety(){return y;}

};
class Line{
private:
    Point a;Point b;double len;
public:
    Line(){};
    Line(Point x,Point y){
        a = x;
        b = y;
        len = sqrt(pow((a.getx()-b.getx()),2) + pow((a.gety()-b.gety()),2));
    }
    void print(Line &);
};

int main(){
    Point point1(0,5),point2(4,8);
    Line XY(point1,point2);
    XY.print(XY);

    return 0;
}

void Line::print(Line &XY){
    cout<<"a坐标是: ("<<XY.a.getx()<<"\t,"<<XY.b.gety()<<")"<<endl;
    cout<<"b坐标是: ("<<XY.b.getx()<<"\t,"<<XY.b.gety()<<")"<<endl;
    cout<<"长度是："<<XY.len<<endl;
}

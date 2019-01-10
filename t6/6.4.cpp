﻿/*4.基类是使用极坐标的点类，从它派生一个圆类，圆类用点类的左边作圆心，
圆周通过极坐标原点，圆类有输出圆心直角坐标、圆半径和面积的成员函数。
完成类的设计并验证之。*/

#include <iostream>
#include <cmath>
using namespace std;
/*************************************************************************/
const double PI = 3.1415926;
class Point {
protected:
	double x, y;
public:
	Point(double a, double b) :x(a), y(b) {}
};

class Circular :public Point {
protected:
	double r, area;
public:
	Circular(double a, double b) :Point(a, b) {
		r = sqrt(x*x + y * y);
		area = PI * r * r;
	}
	void PrintPoint() { cout << "坐标:(" << x << "," << y << ")" << endl; }
	void PrintRadius() { cout << "圆半径:" << r << endl; }
	void PrintArea() { cout << "圆面积:" << area << endl; }
};
/*************************************************************************/
int main()
{
	Circular a(4, 3);
	a.PrintPoint();
	a.PrintRadius();
	a.PrintArea();

	return 0;
}
/*************************************************************************/
/*1.取消设计实例中的Cow属性，练习使用模板实现包含的设计方法。*/

#include <iostream>
#include <cmath>
using namespace std;
/*******************************************************************/
template <class T>
class Point {
	T X, Y;
public:
	Point(T a = 0, T b = 0) :X(a), Y(b) {}
	Point(Point<T> &a) { X = a.X; Y = a.Y; }
	void Display() { cout << X << "," << Y << endl; }
	T Distance(Point<T> &a) {
		return sqrt((X - a.X)*(X - a.X) + (Y - a.Y)*(Y - a.Y));
	}
	T Getx() { return X; }
	T Gety() { return Y; }
};
template <class T>
class Line {
	Point<T> a, b;
public:
	Line(Point<T> &a1, Point<T> &a2) :a(a1), b(a2) {}
	void Display();
	Line(Line<T> &s) :a(s.a), b(s.b) {}
	T Distance();
};

/*******************************************************************/
int main()
{
	Point<double> a;
	Point<double> b(7.8, 9.8), c(34.5, 67.8);
	a = c;
	a.Display();
	b.Display();
	cout << "两点之距：" << a.Distance(b) << endl;
	Line<double> s(a, b);
	Line<double> s1(s);
	cout << "线段属性如下:" << endl;
	s1.Display();
	cout << "线段长度：" << s1.Distance() << endl;

	return 0;
}
/*******************************************************************/
template <class T>
void Line<T>::Display() {
	a.Display();
	b.Display();
}
template <class T>
T Line<T>::Distance() {
	T x = a.Getx() - b.Getx();
	T y = a.Gety() - b.Gety();
	return sqrt(x * x + y * y);
}
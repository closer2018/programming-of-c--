/*2.取消设计实例中的Cow属性，练习使用模板实现继承的设计方法。*/

#include <iostream>
#include <cmath>
using namespace std;
/*******************************************************************/

template <class T>
class Point {
protected:
	T X, Y;
public:
	Point(T a = 0, T b = 0) :X(a), Y(b) {}
	Point(Point<T> &a) { X = a.X; Y = a.Y; }
	virtual void Display() const { cout << "X=" << X << ", Y=" << Y << endl; }
	T Distance(Point<T> &a) const {
		return sqrt((X - a.X)*(X - a.X) + (Y - a.Y)*(Y - a.Y));
	}
	virtual T Area() { return 0; }
	T Getx() const { return X; }
	T Gety() const { return Y; }
};

template <class T>
class Line :public Point<T> {
protected:
	T X2, Y2;
public:
	Line(T a1, T a2, T a3, T a4) :Point<T>(a1, a2), X2(a3), Y2(a4) {}
	Line(Line<T> &s) :Point<T>(s.X, s.Y), X2(s.X2), Y2(s.Y2) {}
	void Display() const;
	T Distance();
	virtual T Area() { return 5 * Distance(); }
	double Getx2() const { return X2; }
	double Gety2() const { return Y2; }
	template <class T>
	friend void Disp(Line<T> &t) { cout << t; }
	template <class T>
	friend ostream &operator<<(ostream &, Line<T>);
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
	Line<double> s(7.8, 9.8, 34.5, 67.8);
	Disp(s);
	Line<double> s1(s);
	cout << "使用Display函数输出线段属性如下:" << endl;
	s1.Display();
	cout << "线段长度：" << s1.Distance() << endl;
	cout << "线段面积：" << s1.Area() << endl;
	cout << "基类对象的属性" << endl;
	a.Display();
	cout << "派生类的对象赋给基类对象" << endl;
	a = s;
	a.Display();
	cout << "面积:" << a.Area() << endl;
	cout << "派生类的对象赋给基类的指针" << endl;
	Point<double> *p = &s1;
	p->Display();
	cout << "面积:" << p->Area() << endl;
	cout << "基类对象引用派生类的对象" << endl;
	Point<double> &d = s1;
	d.Display();
	cout << "面积:" << d.Area() << endl;

	return 0;
}
/*******************************************************************/

template <class T>
void Line<T>::Display() const {
	cout << "X=" << this->X << ",Y=" << this->Y
		<< ",X2=" << X2 << ",Y2=" << Y2 << endl;
}

template <class T>
T Line<T>::Distance() {
	T x = this->X2 - this->X;
	T y = this->Y2 - this->Y;
	return sqrt(x * x + y * y);
}

template <class T>
ostream &operator<<(ostream &out, Line<T> obj) {
	out << "使重载<<输出线段属性如下：" << endl;
	out << obj.Getx() << "," << obj.Gety() << ","
		<< obj.Getx2() << "," << obj.Gety2() << endl;
	return out;
}
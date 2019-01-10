/*2.设计一个点的类模板，分别使用继承和包含的方法设计线段类模板，
要求演示构造函数和复制构造函数的设计方法，并使用主程序验证之。*/

#include <iostream>
using namespace std;
/*******************************************************************/
template <class T>
class Point {
protected:
	T x, y;
public:
	Point(T a, T b) :x(a), y(b) {}
	Point(const Point<T> &obj) { x = obj.x; y = obj.y; }
	void show() { cout << " (" << x << "," << y << ")"; }
};

template <class T>
class LineInherit : public Point<T> {//继承
protected:
	T x2, y2;
public:
	LineInherit(T a, T b, T c, T d) :Point<T>(a, b) { x2 = c; y2 = d; }
	LineInherit(const LineInherit<T> &obj) :Point<T>(obj.x, obj.y) {//继承的拷贝构造函数
		x2 = obj.x2;
		y2 = obj.y2;
	}
	void show() {
		Point<T>::show();
		cout << " (" << x2 << "," << y2 << ")" << endl;
	}
};

template <class T>
class LineInclude {//包含
private:
	Point<T> p1, p2;
public:
	LineInclude<T>(T a, T b, T c, T d) : p1(a, b), p2(c, d) {}
	LineInclude(const LineInclude<T> &obj) :p1(obj.p1), p2(obj.p2) {}
	void show() {
		p1.show();
		p2.show();
	}
};
/*******************************************************************/
int main()
{
	Point<double> a(1.5, 2.3);
	cout << "a点坐标";
	a.show();
	cout << endl;
	cout << endl;

	LineInherit<double> b(1.1, 2.2, 3.0, 4.4);
	cout << "b线坐标";
	b.show();
	cout << endl;

	LineInherit<double> b2(b);
	cout << "b2线坐标";
	b2.show();
	cout << endl;

	LineInclude<int> c(5, 6, 3, 4);
	cout << "c线坐标";
	c.show();
	cout << endl;

	LineInclude<int> c2(c);
	cout << "c2线坐标";
	c2.show();
	cout << endl;

	return 0;
}
/*******************************************************************/
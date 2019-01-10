/*2.设计一个点的类模板，分别使用继承和包含的方法设计线段类模板，
要求演示构造函数和复制构造函数的设计方法，并使用主程序验证之。*/

#include <iostream>
using namespace std;
/*******************************************************************/
template <class T>
class Point {
protected:
	T x_, y_;
public:
	Point(T a, T b) :x_(a), y_(b) {}
	Point(const Point<T> &obj) { x_ = obj.x_; y_ = obj.y_; }
	void show() { cout << " (" << x_ << "," << y_ << ")"; }
};

template <class T>
class LineInherit : public Point<T> {//继承
protected:
	T x2_, y2_;
public:
	LineInherit(T a, T b, T c, T d) :Point<T>(a, b) { x2_ = c; y2_ = d; }
	LineInherit(const LineInherit<T> &obj) :Point<T>(obj.x_, obj.y_) {//继承的拷贝构造函数
		x2_ = obj.x2_;
		y2_ = obj.y2_;
	}
	void show() {
		Point<T>::show();
		cout << " (" << x2_ << "," << y2_ << ")" << endl;
	}
};

template <class T>
class LineInclude {//包含
private:
	Point<T> p1_, p2_;
public:
	LineInclude<T>(T a, T b, T c, T d) : p1_(a, b), p2_(c, d) {}
	LineInclude(const LineInclude<T> &obj) :p1_(obj.p1_), p2_(obj.p2_) {}
	void show() {
		p1_.show();
		p2_.show();
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
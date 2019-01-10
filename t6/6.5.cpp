/*5.设计一个线段基类，当创建无参数对象时，才要求用户输入长度。
同样，其派生的直角三角形类也是在产生对象时要求输入两个直角边的长度。
直角三角形在派生矩形类，矩形类的参数也由键盘输入。设计这些类并测试他们的功能。*/

#include <iostream>
#include <cmath>
using namespace std;
/*************************************************************************/
class Line {
protected:
	double a_;
public:
	Line() {
		cout << "输入长度: " << endl;
		cin >> a_;
	}
	Line(double a) :a_(a) {}
	double GetSize() { return a_; }
};

class Triangle :public Line {
protected:
	double b_,c_;
public:
	Triangle() {
		cout << "输入长度: " << endl;
		cin >> b_;
		c_ = sqrt(b_*b_ + a_ * a_);
	}
	void PrintSize() {
		cout << "直角三角形，三条边长分别为： ";
		cout << "" << a_ << " " << b_ << " " << c_ << endl;
	}
};

class Rectangle :public Triangle {
protected:
	double d_;
public:
	Rectangle() {
		c_ = a_;	d_ = b_;
	}
	void PrintSize() {
		cout << "矩形的四条边长分别为： ";
		cout << " " << a_ << " " << b_ << " " << c_ <<
			" " << d_ << endl;
	}
};
/*************************************************************************/
int main()
{
	Line *l = new Line();
	cout << "线段长度为: " << l->GetSize() << endl;
	delete l;

	cout << "下面输入直角三角形边长。\n";
	Triangle *t = new Triangle();
	t->PrintSize();
	delete t;

	cout << "下面输入矩形边长。\n";
	Rectangle *r = new Rectangle();
	r->PrintSize();
	delete r;

	return 0;
}
/*************************************************************************/
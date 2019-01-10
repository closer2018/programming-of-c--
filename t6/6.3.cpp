/*3.定义一个线段类作为矩形的基类，基类有起点和终点坐标，有输出坐标和长度以及线段
和x轴的夹角的成员函数。矩形类用线段对象的两个坐标作为自己一条边的位置，它具
有另外一条边，能输出矩形的4个顶点坐标。给出类的定义并用程序验证它们的功能。*/

#include <iostream>
#include <cmath>
using namespace std;
/*******************************************************************************/
const double PI = acos(-1);

class Line {
protected:
	double startx_, starty_;
	double endx_, endy_;
public:
	Line() {}
	Line(double a, double b, double c, double d) :
		startx_(a), starty_(b), endx_(c), endy_(d) {}
	void PrintXY() const {
		cout << "起点坐标: (" << startx_ << " , " << starty_ << ")" << endl;
		cout << "终点坐标: (" << endx_ << " , " << endy_ << ")" << endl;
	}
	double Dy()const {
		return starty_ - endy_;
	}
	double Len() const {
		return sqrt(pow((startx_ - endx_), 2) + pow((this->Dy()), 2));
	}
	double Angle() const {
		return atan2(endy_ - starty_, endx_ - startx_) / PI * 180;
	}
	void PrintLenAndAngle() const {
		cout << "线段长度是:" << this->Len() << endl;
		cout << "线段和x轴的角度是:" << this->Angle() << endl;
	}
};
class Rectangle :public Line {
protected:
	double high;
public:
	Rectangle(Line &a, double h) :Line(a), high(h) {}
	void PrintPeak(Line &a) {
		cout << "坐标1: (" << startx_ << " , " << starty_ << ")" << endl;
		cout << "坐标2: (" << endx_ << " , " << endy_ << ")" << endl;
		cout << "坐标3: (" << endx_ - high * sin(a.Angle()) <<
			" , " << endy_ + high * cos(a.Angle()) << ")" << endl;
		cout << "坐标4: (" << startx_ - high * sin(a.Angle()) <<
			" , " << starty_ + high * cos(a.Angle()) << ")" << endl;
	}
};
/*******************************************************************************/
int main()
{
	Line a(0, 0, 2, 0);
	a.PrintXY();
	a.PrintLenAndAngle();

	Rectangle b(a, 2);
	b.PrintPeak(a);

	return 0;
}
/*******************************************************************************/


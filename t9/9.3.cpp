/*3.编写一个程序，要求输入三角形的3条边，然后判断是否合理，如果不合理，
给出信息并要求重新输入；如果合理，计算其面积并将结果存入文件中。。*/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
/*******************************************************************/
class Triangle {
	double a_, b_, c_;
public:
	Triangle() {
		cout << "请输入三条边长." << endl;
		cin >> a_ >> b_ >> c_;
		while (!Check()) {
			cout << "请输入正确的三条边长." << endl;
			cin >> a_ >> b_ >> c_;
		}
	}
	Triangle(double x, double y, double z) {
		a_ = x; b_ = y; c_ = z;
		while (!Check()) {
			cout << "请输入正确的三条边长." << endl;
			cin >> a_ >> b_ >> c_;
		}
	}
	bool Check() {
		if (a_ > 0 && b_ > 0 && c_ > 0 && (a_ + b_) > c_ &&
			(a_ + c_) > b_ && (b_ + c_) > a_) {
			return true;
		}
		else {
			return false;
		}
	}
	double Area() {
		double p = (a_ + b_ + c_) / 2;
		return sqrt(p*(p - a_)*(p - b_)*(p - c_));
	}
};
/*******************************************************************/
int main()
{
	Triangle a;
	double b = a.Area();
	ofstream myFile("myFile.txt");
	myFile << b;
	cout << "面积是:" << b << endl;
	myFile.close();

	return 0;
}
/*******************************************************************/
/*4.改写上题的程序，使程序反复计算，直到输入结束符为止。要求在停止计算之后，
询问要保存的文件名，然后将结果一次写入指定文件中。*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;
/*******************************************************************/
class Triangle {
	double a_, b_, c_;
public:
	Triangle() {}
	Triangle(double x, double y, double z) : a_(x), b_(y), c_(z) {}
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
	double Geta(double x) { a_ = x; return a_; }
	double Getb(double y) { b_ = y; return b_; }
	double Getc(double z) { c_ = z; return c_; }
	void Set(vector<double> &);
};
/*******************************************************************/
int main()
{
	vector <double> s;
	Triangle temp;
	temp.Set(s);
	while (cin.get() != '\n')continue;
	char name[20];
	cout << "输入要保存的文件名:";
	cin.getline(name, 20);
	ofstream myFile(name);
	for (size_t i = 0; i < s.size(); i++)
	{
		myFile << "第" << i + 1 << "个三角形面积是:" << s[i] << endl;
	}
	myFile.close();

	return 0;
}
/*******************************************************************/
void Triangle::Set(vector<double> &s) {
	double x = 1, y, z, area;
	while (x != 0) {
		Triangle a;
		cout << "请输入三条边长(0离开)." << endl;
		cin >> x;
		a.Geta(x);
		if (x == 0) break;
		cin >> y >> z;
		a.Getb(y);
		a.Getc(z);
		while (!a.Check()) {
			cout << "三条边不能构成三角形，请输入正确的三条边长(0离开)." << endl;
			cin >> x;
			if (x == 0) return;
			a.Geta(x);
			cin >> y >> z;
			a.Getb(y);
			a.Getc(z);
		}
		area = a.Area();
		s.push_back(area);
	}
}
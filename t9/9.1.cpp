/*1.利用流格式控制，进行成绩和名字的输出，要求名字左对齐，分数右对齐。*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*******************************************************************/
class Student {
private:
	string name_;
	double score_;
public:
	Student() { name_ = "\0"; score_ = 0; }
	Student(string a, double b) : name_(a), score_(b) {}
	void Set(vector <Student> &s) {
		for (size_t i = 0; i < s.size(); i++)
		{
			cout << "请输入姓名(不输入名字，直接回车跳出)";
			getline(cin, s[i].name_);
			if (s[i].name_ == "\0") break;
			cout << "请输入分数";
			cin >> s[i].score_;
			while (cin.get() != '\n')continue;
		}
	}
	void Print(vector <Student> &s) {
		cout.width(30);
		cout << left << "姓名" << right << "成绩" << endl;
		for (size_t i = 0; i < s.size(); i++)
		{
			cout.width(30);
			cout << left << s[i].name_ << right << s[i].score_ << endl;
		}
	}
};
/*******************************************************************/
int main()
{
	Student a;
	int n;
	cout << "输入几个学生信息？\n";
	cin >> n;
	while (cin.get() != '\n')continue;//去除回车

	vector <Student> b(n);
	a.Set(b);
	a.Print(b);

	return 0;
}
/*******************************************************************/
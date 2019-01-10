/*1.使用类模板演示复制兼容性规则。*/

#include <iostream>
#include <string>
using namespace std;
/*******************************************************************/
class Child {
protected:
	int age;
public:
	Child(int a) :age(a) {}
	void show() { cout << "年龄是:" << age << endl; }
};

template <typename T>
class Boy :public Child {
private:
	T sex;
public:
	Boy(int a, T s) :Child(a) { sex = s; }
	void show() {
		Child::show();
		cout << "性别是:" << sex << endl;
	}
};
/*******************************************************************/
int main()
{
	Child a(15);
	Boy <string>b(13, "男性");

	a.show();
	b.show();
	cout << '\n';

	a = b;
	a.show();
	cout << endl;

	Child & a1 = b;
	a1.show();
	cout << endl;

	Child * pa = &b;
	Boy<string> * pb = &b;
	pa->show();
	pb->show();
	cout << endl;

	return 0;
}
/*******************************************************************/
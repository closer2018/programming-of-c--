/*5.从文件TEST中读出字符并写到文件TEST1里，要求均附加错误检查。*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*******************************************************************/

/*******************************************************************/
int main()
{
	ifstream tx1("TEST.txt");
	ofstream tx2("TEST1.txt");
	if (!tx1) {
		cout << "打开文件失败！" << endl;
		return 0;
	}
	if (!tx2) {
		cout << "建立文件失败！" << endl;
		return 0;
	}
	string ch;
	while (1) {
		if (!tx1.eof()) {
			getline(tx1, ch);
			cout << ch << endl;
			tx2 << ch << endl;
		}
		else {
			tx1.close();
			return 0;
		}
	}
	return 0;
}
/*******************************************************************/
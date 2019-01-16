/*6.从键盘输入一个字符串，将其中的大写字母全部转换成小写字母，
然后存入到文件名为”text“的磁盘文件中保存。输入的字符串以”$“结束。*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*******************************************************************/
const int DIF = ('A' - 'a');
/*******************************************************************/
int main()
{
	ofstream text("text.txt");
	char ch;
	while ((cin >> ch) && ch != '$') {
		if (ch >= 'A'&& ch <= 'Z')
			ch = ch - DIF;
		text << ch;
		cout << ch;
	}

	text.close();

	return 0;
}
/*******************************************************************/
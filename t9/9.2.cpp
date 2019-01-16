/*2.编写一个产生文本文件的程序。*/

#include <iostream>
#include <fstream>
using namespace std;
/*******************************************************************/

/*******************************************************************/
int main()
{
	ofstream myFile("myFile.txt");
	const char p[] = { "hello world." };
	myFile << p;
	myFile.close();

	return 0;
}
/*******************************************************************/
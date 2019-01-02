/*2.已知一个string的对象str的内容为“We are here！”，使用多种方法输出“h”。*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    string str="We are here！";

    int i=str.find('h',0);
    cout<<"1 "<<str[i]<<endl;//str第i个元素

    string str2 = str.substr(i,1);//截取
    cout<<"2 "<<str2<<endl;

    char str3 = str[i];
    cout<<"3 "<<str3<<endl;

    char str4[1];
    copy(str.begin()+i, str.begin()+i+1, str4);//拷贝出来
    cout<<"4 "<<str4[0]<<endl;

    return 0;
}

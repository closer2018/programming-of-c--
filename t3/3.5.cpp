/*5.编写一个求字符串长度的函数strlen（），再用strlen（）函数编写一
个函数revers（s）的倒序递归程序，使字符串s逆序。*/
#include <iostream>
#include <string>
using namespace std;

long strlen(string );
void revers(string str);

int main()
{
    string str;

    getline(cin,str,'\n');
    revers(str);

    return 0;
}

long strlen(const string str)
{
    return (str.end() - str.begin()) / sizeof(char);
}

void revers(string str)
{
    if(str.empty())
        return;
    cout<<str.substr(strlen(str)-1,1);//截取最后一个字符输出
    str=str.substr(0,strlen(str)-1);//截取除最后一个的所有字符赋予str
    revers(str);//递归直到字符串为空
}


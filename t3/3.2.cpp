/*2.定义函数up(ch)，如字符变量ch是小写字母就转换成大写字母并通过up返回，
否则字符ch不改变。要求在短小而完全的程序中显示这个程序是怎样被调用的。*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

inline char up(char ch)
{
    return (ch >= 'a' && ch <= 'z')? (ch-32) : ch;
}

int main()
{
    char ch;

    cout<<"输入字母,#离开"<<endl;
    while( (cin>>ch) && ch != '#' )
    {
        cout<<up(ch);
        cout<<endl<<"输入字母,#离开"<<endl;
    }

    return 0;
}

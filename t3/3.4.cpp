/*4.编写有字符型参数C和整形参数N的函数，让他们显示出由字符C组成的三角形。
其方式为第1行有1个字符C，第2行有2个字符C ，等等。*/

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
void print(char ch, int n);

int main()
{
    char ch;
    int n;

    cout<<"输入字符和行数，我会打印它"<<endl;
    while(cin>>ch>>n && n != 0)
    {
        print(ch,n);
        cout<<"输入字符和行数(0 离开)"<<endl;
    }

    return 0;
}

void print(char ch, int n)
{
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= i; j++)
            cout<<ch;
        cout<<endl;
    }
}


/*3.编写主程序调用带实数r和整数n两个参数的函数并输出r的n次幂。*/

#include <iostream>
using namespace std;

double mypower(double r, int n);

int main()
{
    double r;
    int n;

    cout<<"输入底和幂(底不为0)."<<endl;
    while( (cin>>r>>n) && r != 0)
    {
        cout<<r<<"的"<<n<<"次幂是:"<<mypower(r,n)<<endl;
        cout<<"输入底和幂(底不为0)."<<endl;
    }

    return 0;
}

double mypower(double r, int n)
{
    double answer=1;

    if(n > 0)
    {
        for(int i=1;i<=n;i++)
            answer*=r;
    }
    else if(n < 0)
    {
        for(int i=0;i<-n;i++)
            answer*=(1/r);
    }
    else
        ;

    return answer;
}

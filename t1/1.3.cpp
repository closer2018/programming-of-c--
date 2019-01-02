//3.编写完整的程序，它读入15个float值，用指针把它们存放在一个存储快里，然后输出这些值和以及最小值
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    float * p;
    float sum;

    p=new float[15];
    cout<<"输入15个数:";
    for (int i=0; i < 15; i++)
    {
        cin>>p[i];
    }
    sort(p,p+15);
    for (int i = 0; i < 15; i++)
    {
        cout <<p[i]<<' ';
        sum +=p[i];
    }
    cout<<endl<<"和是:"<<sum<<endl;
    cout<<"最小值是:"<<p[0]<<endl;

    delete []p;

    return 0;
}

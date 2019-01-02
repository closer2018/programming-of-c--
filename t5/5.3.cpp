/*3.编写一个程序，该程序建立一个动态数组，为动态数组的元素赋值，
显示动态数组的值并删除动态数组。*/

#include <iostream>
using namespace std;
int main()
{
    int *p = new int[10];

    for (int i=0;i<10;i++)
    {
        *(p + i) = i;
        cout<<* (p + i)<<endl;
    }
    delete [] p;

    return 0;
}

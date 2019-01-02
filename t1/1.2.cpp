//2.编写一个int型变量分配100个整形空间的程序。
#include <iostream>
using namespace std;
int main()
{
    int *p;

    p=new int[100];

    delete []p;

    return 0;
}

/*8.重载上题中的函数模板，使他能够进行两个数组的求和。*/

#include <iostream>
using namespace std;

template <class T1>
T1 sum(T1 ar[],int n);
template <class T1,class T2>
T1 sum(T1 ar1[],int n1,T2 ar2[],int n2)
{
    return sum(ar1,n1)+sum(ar2,n2);
}

int main()
{
    double ar1[]={1.1,2,6.5,9,7};
    char ar2[]={'a','g','e'};

    cout<<sum(ar1,5,ar2,3);

    return 0;
}

template <class T1>
T1 sum(T1 ar[],int n)
{
    T1 tol=0;

    for(int i=0;i<n;i++)
        tol+=ar[i];

    return tol;
}

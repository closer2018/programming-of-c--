/*4.声明如下数组： float *p; p = new float[15]; cout<<

int a[] = {1 ,2 ,3, 4, 5, 6, 7, 8}；

先查找4的位置，讲数组a复制给数组b，然后将数组a的内容反转，再查找4的位置
，最后分别输出数组a和b的内容。*/
#include <iostream>
#include <algorithm>
//#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int a[]={1, 2, 3, 4, 5, 6, 7, 8}, b[8];

    *find(a, a+8, 4) == 4 ? cout<<"找到了"<<endl:
                            cout<<"没找到"<<endl;
    copy(a, a+8, b);
    reverse(a,a+8);
    *find(a, a+8, 4) == 4 ? cout<<"找到了"<<endl:
                            cout<<"没找到"<<endl;
    copy(a,a+8,ostream_iterator<int>(cout," "));
    cout<<endl;
    copy(b,b+8,ostream_iterator<int>(cout," "));
    cout<<endl;

    return 0;
}

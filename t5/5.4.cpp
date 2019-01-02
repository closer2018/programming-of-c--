/*4.定义一个Dog类，它用静态数据成员Dogs记录Dog的个体数目。
静态成员函数GetDogs用来存取Dogs。设计并测试这个类。*/

#include <iostream>
using namespace std;

class Dogs{
private:
    static int num;
public:
    Dogs(){}
    Dogs(int n){num = n;}
    static int GetDogs(Dogs &a,int n);
    int getn(){return num;}
};

int Dogs::num=0;

int main()
{
    Dogs a,b,c;
    cout<<"现在狗有"<<a.getn()<<"只"<<endl;
    b = 1;
    cout<<"现在狗有"<<a.getn()<<"只"<<endl;
    cout<<"现在狗有"<<b.GetDogs(a,2)<<"只"<<endl;
    cout<<"现在狗有"<<c.GetDogs(b,2)<<"只"<<endl;
    c = 2;
    cout<<"现在狗有"<<c.GetDogs(b,2)<<"只"<<endl;

    return 0;
}

int Dogs::GetDogs(Dogs &a,int n){
    a.num += n;
    return a.num;
}

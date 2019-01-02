/*1.编写一个求方程ax2 + bx + c = 0的根 的程序，用3个函数分别求当b2-4ac大于零
、等于零、和小于零时的方程的根。要求从主函数输入a,b,c的值并输出结果。*/
#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

void root_large(double &a,double &b,double &c);
void root_small(double &a,double &b,double &c);
void root_zero(double &a,double &b,double &c);

int main()
{
    double a,b,c;

    while(1){
        cout<<"输入一元二次方程的a,b,c(0退出)"<<endl;
        cin>>a;
        if(a == 0) break;
        cin>>b>>c;
        double TEMP = ((b) * (b)) - (4 * (a) * (c));
        if(TEMP > 0)
            root_large(a,b,c);
        else if(TEMP == 0)
            root_zero(a,b,c);
        else
            root_small(a,b,c);
    }

    return 0;
}

void root_large(double &a,double &b,double &c)
{
    double TEMP = ((b) * (b)) - (4 * (a) * (c));
    double answer1 = ((-b) + sqrt(TEMP)) / (2 * a);
    double answer2 = ((-b) - sqrt(TEMP)) / (2 * a);
    cout<<"这个方程的解是："<<answer1<<"\t"<<answer2<<endl;
}

void root_small(double &a,double &b,double &c)
{
    double TEMP = ((b) * (b)) - (4 * (a) * (c));
    double answer1 = (-b) / (2 * a);
    double answer2 = (sqrt(0 - TEMP)) / (2 * a);
    cout<<"这个方程的解x1是："<<answer1<<" + "<<answer2<<"i"<<endl;
    cout<<"这个方程的解x2是："<<answer1<<" - "<<answer2<<"i"<<endl;
}

void root_zero(double &a,double &b,double &c)
{
    double TEMP = ((b) * (b)) - (4 * (a) * (c));
    double answer1 = (-b) / (2 * a);
    double answer2 = answer1;
    cout<<"这个方程的解是："<<answer1<<"\t"<<answer2<<endl;
}

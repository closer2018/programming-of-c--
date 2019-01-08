/*3.定义一个线段类作为矩形的基类，基类有起点和终点坐标，有输出坐标和长度以及线段
和x轴的夹角的成员函数。矩形类用线段对象的两个坐标作为自己一条边的位置，它具
有另外一条边，能输出矩形的4个顶点坐标。给出类的定义并用程序验证它们的功能。*/

#include <iostream>
#include <cmath>
using namespace std;
/*******************************************************************/
const double PI = 3.14159265359;

class Line{
    protected:
        double startx_, starty_;
        double endx_, endy_;
    public:
        Line(){}
        Line(double a, double b, double c, double d) :
            startx_(a), starty_(b), endx_(c), endy_(d) {}
        void PrintXY() const{
            cout<<"起点坐标: ("<<startx_<<" , "<<starty_<<")"<<endl;
            cout<<"终点坐标: ("<<endx_<<" , "<<endy_<<")"<<endl;
            }
        void PrintAngle() const{
            double dx = startx_ - endx_;
            double dy = starty_ - endy_;
            double len = sqrt( pow((dx), 2) + pow((dy), 2));
            cout<<"线段长度是:"<<len<<endl;

            double angle = len > 0 ? round( asin(dy / len) / PI *180) : 0;
            //angle范围(-90,90)当终点在起点左边时，必须处理
            if(endx_ < startx_) {
                angle = 180 - angle;
                }
            cout<<"线段角度是:"<<-angle<<endl;
            }
};
/*******************************************************************/
int main()
{
    Line a(0,0,2,2);
    a.PrintAngle();

    return 0;
}
/*******************************************************************/

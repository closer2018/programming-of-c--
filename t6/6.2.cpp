/*下面是某公司经理、兼职人员、销售经理和销售员的工资计算方法，
设计合适的基类和派生类，实现这一工资管理任务。*/
#include <iostream>
using namespace std;
/*****************************************************************/
const double SMANPUSH = 0.04;
const double SMANAGERPUSH = 0.005;
const double TIMEPAY = 100.0;
const double FIXEDPAY_AGENCY = 8000.0;
const double FIXEDPAY_SALE = 5000.0;
/*****************************************************************/
class PartTimer{//兼职人员
    private:
        double worktime_;
    public:
        PartTimer() {}
        PartTimer(double a): worktime_(a) {}
        double GetPay() const{return worktime_ * TIMEPAY;}
};

class AgencyManager{//公司经理
    private:
        double fixedPay_;
    public:
        AgencyManager() {fixedPay_ = FIXEDPAY_AGENCY; }
        double GetPay() const{return fixedPay_;}
};

class Salesman{//销售员
    protected:
        double totalSales_;
    public:
        Salesman(){}
        Salesman(double a) {totalSales_ = a;}
        double GetPay() const{ return totalSales_ * SMANPUSH; }
};

class SaleManager:public Salesman{//销售经理
    private:
        double fixedPay_;
    public:
        SaleManager() {}
        SaleManager(double a): Salesman(a) { fixedPay_ = FIXEDPAY_SALE;}
        double GetPay() const { return ((totalSales_ * SMANAGERPUSH) + (fixedPay_));}
};

/*****************************************************************/
int main()
{
    double totalsales,worktime;

    cout<<"输入当月销售总额:";
    cin>>totalsales;
    cout<<"兼职人员工作时间:";
    cin>>worktime;

    PartTimer a(worktime);
    Salesman b(totalsales);
    AgencyManager c;
    SaleManager d(totalsales);

    cout<<"公司经理工资："<<c.GetPay()<<endl;
    cout<<"兼职人员工资："<<a.GetPay()<<endl;
    cout<<"销售经理工资："<<d.SaleManager::GetPay()<<endl;
    cout<<"销售人员工资："<<b.Salesman::GetPay()<<endl;

    return 0;
}
/*****************************************************************/

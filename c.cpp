 #include<iostream>
using namespace std;
struct Department{
    string name;
    double years_so_bh, doanh_so_tb, *doanh_so_bh;
    Department(string name, double q1, double q2, double q3, double q4):name(name),doanh_so_bh(new double[4]){
        doanh_so_bh[0] =q1;
        doanh_so_bh[1] =q2;
        doanh_so_bh[2] =q3;
        doanh_so_bh[3] =q4;
        years_so_bh=q1+q2+q3+q4;
        doanh_so_tb=years_so_bh/4;
    }
    friend ostream& operator<<(ostream &os,Department &d){
        os<<"Ten bo phan: "<<d.name<<endl;
        os<<"Doanh so ban hang trong 4 quy: "<<endl;
        os<<"  Quy 1: "<<d.doanh_so_bh[0]<<endl;
        os<<"  Quy 2: "<<d.doanh_so_bh[1]<<endl;
        os<<"  Quy 3: "<<d.doanh_so_bh[2]<<endl;
        os<<"  Quy 4: "<<d.doanh_so_bh[3]<<endl;
        os<<"Tong doanh so hang nam: "<<d.years_so_bh<<endl;
        os<<"Doanh so ban hang trung binh quy: "<<d.doanh_so_tb<<endl;
        return os;
    }
};
int main(){
    system("cls");
    Department 
        d("Dong",100,200,300,400),
        t("Tay",500,600,700,800),
        n("Nam",900,200,600,400),
        b("Bac",300,700,400,800);
        cout<<d<<endl;
        cout<<t<<endl;
        cout<<n<<endl;
        cout<<b<<endl;
    return 0;
}
#include <iostream>
using namespace std;
class Employee{
  private:
    string name;
    string maSo;
    int ngayThue;
  public:
      Employee(string name, string maSo, int ngayThue ){
          this->name = name;
          this->maSo = maSo;
          setngayThue(ngayThue);
      }
      void setName(string name){this->name = name;}
      string getName(){return this->name;}
      void setMaSo(string maSo){this->maSo = maSo;}
      string getMaSo(){return this->maSo;}
      void setngayThue(int ngayThue){this->ngayThue=ngayThue;}
      int getngayThue(){return this->ngayThue;}
};

class ProductionWorker : public Employee{
    private:
        int caLam,soNgay;
        float luong,mucLuongtheogio;
        int check(int cl,float mucltg){
            float mltg;
            if(cl==1){mltg=mucltg;}
            else if(cl==2){mltg=1.5*mucltg;}
            return mltg;
        }
        void salary(){luong=soNgay*caLam*mucLuongtheogio;}
    public:
        ProductionWorker(string name,string maSo,int soNgay,int cl,float mltg ):Employee(name,maSo,soNgay){
            this->caLam=cl;
            this->soNgay=soNgay;
            this->mucLuongtheogio=check(caLam,mltg);

            salary();
        }
        float getLuong(){return luong;}
};
int main()
{  ProductionWorker n1("teo","A14567",14,2,5);
    cout<<n1.getLuong();
    return 0;
}

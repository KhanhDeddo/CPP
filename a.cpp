#include <iostream>
using namespace std;
class Employee{
  private:
    string name,code_number;
    int ngay_thue;
  public:
      Employee(string name, string code_number, int ngay_thue ){
          this->name = name;
          this->code_number = code_number;
          this->ngay_thue = ngay_thue;
      }
      void setName(string name){this->name = name;}
      void setCodeNumber(string code_number){this->code_number = code_number;}
      void setNgayThue(int ngay_thue){this->ngay_thue=ngay_thue;}
      string getName(){return this->name;}
      string getCodeNumber(){return this->code_number;}
      int getNgayThue(){return this->ngay_thue;}
};
class ProductionWorker : public Employee{
    private:
        int ca_lam,so_ngay_lam;
        float luong,luong_theo_gio;
        void salary(){
            luong=so_ngay_lam*ca_lam*luong_theo_gio;
        }
        int check(int cl,float ltg){
            float luong_theo_gio;
            if(cl==1){
                luong_theo_gio=ltg;
            }
            else if(cl==2){
                luong_theo_gio=1.5*ltg;
            }
            return luong_theo_gio;
        }
    public:
        ProductionWorker(string name,string code_number,int ngay_thue,int so_ngay_lam,int ca_lam,float luong_theo_gio)
        :Employee(name,code_number,ngay_thue){
            this->ca_lam=ca_lam;
            this->so_ngay_lam=so_ngay_lam;
            this->luong_theo_gio=check(ca_lam,luong_theo_gio);
            salary();
        }
        void setCaLam(int ca_lam){
            this->ca_lam=ca_lam;
            this->luong_theo_gio=check(ca_lam,luong_theo_gio);
            salary();
        }
        void setLuongTheoGio(float luong_theo_gio){
            this->luong_theo_gio=check(ca_lam,luong_theo_gio);
            salary();
        }
        void setSoNgayLam(int so_ngay_lam){
            this->so_ngay_lam=so_ngay_lam;
            salary();
        }
        int getCaLam()const{return ca_lam;}
        int getSoNgayLam()const{return so_ngay_lam;}
        float getLuongTheoGio()const{return luong_theo_gio;}
        float getLuong()const{return luong;}
        friend ostream& operator<<(ostream &out,ProductionWorker &ps){
            out<<"Thong tin nhan vien:"<<endl;
            out<<"Ten: "<<ps.getName()<<endl;
            out<<"Ma nhan vien: "<<ps.getCodeNumber()<<endl;
            out<<"Ngay thue: "<<ps.getNgayThue()<<endl;
            out<<"So ngay lam: "<<ps.getSoNgayLam()<<endl;
            out<<"Ca lam: "<<ps.getCaLam()<<endl;
            out<<"Luong theo gio: "<<ps.getLuongTheoGio()<<endl;
            out<<"Luong theo thang: "<<ps.getLuong()<<endl;
            return out;
        }
};
int main(){  
    //ProductionWorker p1("Ten","Mã nhan vien","Ngay thue","So ngay lam","Ca làm 1 hoăc 2","Lương theo giờ");
    ProductionWorker p1("Tao","A45844",1,26,2,5);
    cout<<p1;
    return 0;
}

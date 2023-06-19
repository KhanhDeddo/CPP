#include<iostream>
using namespace std;
class PersionData{
    private:
        string last_name,first_name,adress,city,code_buu_dien,phone_number;
    public:
        void setLastName(string last_name){
            this->last_name=last_name;
        }
        void setFirstName(string first_name){
            this->first_name=first_name;
        }
        void setAdress(string adress){
            this->adress=adress;
        }
        void setCity(string city){
            this->city=city;
        }
        void setCodeBuuDien(string code_buu_dien){
            this->code_buu_dien=code_buu_dien;
        }
        void setPhoneNumber(string phone_number){
            this->phone_number=phone_number;
        }
        string getLastName(){return last_name;}
        string getFirstName(){return first_name;}
        string getAdress(){return adress;}
        string getCity(){return city;}
        string getCodeBuuDien(){return code_buu_dien;}
        string getPhoneNumber(){return phone_number;}
};
class CustomerData:public PersionData{
    private:
        string mail[10]={
            "haha01.com", "haha02.com", "haha03.com", "haha04.com", "haha05.com",
             "haha06.com", "haha07.com", "haha08.com", "haha09.com", "haha10.com",
        };
        string id;
        bool check;
        void Check(string m){
            check=false;
            for(int i=0;i<10;i++){
                if(m==mail[i]){check=true;}
            }
        }
    public:
        CustomerData(string last_name,string first_name,string adress,string city,string code_buu_dien,string phone_number,string id,string mail){
            setLastName(last_name);
            setFirstName(first_name);
            setAdress(adress);
            setCity(city);
            setCodeBuuDien(code_buu_dien);
            setPhoneNumber(phone_number);
            this->id=id;
            Check(mail);
        }
        void setId(string id){
            this->id=id;
        }
        string getId(){return id;}
        bool getCheck(){return check;}
        friend ostream &operator<<(ostream &out, CustomerData &c){
            out<<"Duu lieu khach hang:"<<endl;
            out<<"Ho: "<<c.getLastName() <<endl;
            out<<"Ten: "<<c.getFirstName()<<endl;
            out<<"Dia chi: "<<c.getAdress()<<endl;
            out<<"City: "<<c.getCity()<<endl;
            out<<"Ma buu dien: "<<c.getCodeBuuDien()<<endl;
            out<<"So dien thoai: "<<c.getPhoneNumber()<<endl;
            out<<"Id: "<<c.getId()<<endl;
            out<<"Check: "<<c.getCheck()<<endl;
            return out;
        }
};
class PreferredCustomer:public CustomerData{
    private:
        double diem_tich_luy, chiet_khau;
        void checkDiemTichLuy(double diem_tich_luy){
            if(diem_tich_luy>=2000){chiet_khau=0.1;}
            else if(diem_tich_luy>=1500){chiet_khau=0.07;}
            else if(diem_tich_luy>=1000){chiet_khau=0.06;}
            else if(diem_tich_luy>=500){chiet_khau=0.05;}
        }
    public:
        PreferredCustomer(string last_name,string first_name,string adress,string city,string code_buu_dien,string phone_number,string id,string mail,double diem_tich_luy)
        :CustomerData(last_name,first_name,adress,city,code_buu_dien,phone_number,id,mail){
            this->diem_tich_luy=diem_tich_luy;
            checkDiemTichLuy(diem_tich_luy);
        }
        void setDiemTichLuy(double diem_tich_luy){this->diem_tich_luy=diem_tich_luy;}
        double getDiemTichLuy(){return diem_tich_luy;}
        double getChietKhau(){return chiet_khau;}
        friend ostream &operator<<(ostream &out, PreferredCustomer &c){
            out<<"Duu lieu khach hang:"<<endl;
            out<<"Ho: "<<c.getLastName() <<endl;
            out<<"Ten: "<<c.getFirstName()<<endl;
            out<<"Dia chi: "<<c.getAdress()<<endl;
            out<<"City: "<<c.getCity()<<endl;
            out<<"Ma buu dien: "<<c.getCodeBuuDien()<<endl;
            out<<"So dien thoai: "<<c.getPhoneNumber()<<endl;
            out<<"Id: "<<c.getId()<<endl;
            out<<"Check: "<<c.getCheck()<<endl;
            out<<"Diem tich luy: "<<c.getDiemTichLuy()<<endl;
            out<<"Diem chiet khau: "<<c.getChietKhau()<<endl;
            return out;
        }
};
int main(){
    CustomerData c("Demon","Lucy","120 VN","HN","a45844","012345","001","haha01.com");
    PreferredCustomer p("Demon2","Lucy2","1220 VN","HN2","a45844","0123452","002","haha00.com",5000);
    cout<<c<<endl;
    cout<<p<<endl;
    return 0;
}
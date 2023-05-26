#include<bits/stdc++.h>
using namespace std;
class PersionInfor{
    private:
        string name,phone,adress;
        int age;
    public:
        PersionInfor():name(""), age(0), phone(""), adress(""){}
        PersionInfor(string name, int age):name(name), age(age), phone(""), adress(""){}
        PersionInfor(string name, int age, string phone, string adress){setInfor(name,age,phone,adress);}
        void setInfor(string newName, int newAge, string newPhone, string newAdress){
            name = newName;
            age = newAge;
            phone = newPhone;
            adress = newAdress;
        }
        void printInfor(){
            cout<<name<<setw(16)<<age<<setw(20)<<phone<<setw(22)<<adress<<endl;
            
        }
};

int main(){
    PersionInfor a[3]={
        PersionInfor(),
        PersionInfor("Khanh",19),
        PersionInfor("Khanh",19,"0123456789","Ha Noi")
    };
    cout<<"Ten"<<setw(20)<<"Tuoi"<<setw(20)<<"So dien thoai"<<setw(20)<<"Dia chi"<<endl;
    for(int i=0; i<3; i++){
        a[i].printInfor();
    }
    return 0;
}
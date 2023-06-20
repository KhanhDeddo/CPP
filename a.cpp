#include<iostream>
using namespace std;
struct Books{
    string name,nsx;
    double nxb;
    Books(string name,string nsx ,double nxb):name(name),nsx(nsx),nxb(nxb){}
    friend ostream& operator<<(ostream &os,Books &b){
        os<<"Ten tac gia: "<<b.name<<endl;
        os<<"Nha xuat ban:"<<b.nsx<<endl;
        os<<"Ngay suat ban: "<<b.nxb<<endl;
        return os;
    }
};
int main(){
    Books b("Taos","VN",2022);
    cout<<b;
    return 0;
}

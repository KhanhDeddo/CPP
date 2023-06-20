#include<iostream>
using namespace std;
struct MoveData{
    string title,dao_dien;
    double nph,time;
    MoveData(string title ,string dao_dien, double nph ,double time)
    :title(title),dao_dien(dao_dien),nph(nph),time(time){}
    friend ostream& operator<<(ostream &os,MoveData &b){
        os<<"Ten phim: "<<b.title<<endl;
        os<<"Ten dao dien: "<<b.dao_dien<<endl;
        os<<"Ngay phat hanh: "<<b.nph<<endl;
        os<<"Time: "<<b.time<<"phut"<<endl;
        return os;
    }
};
class Qly{
    private:
        MoveData *p;
        int size;
    public:
         Qly(int size=10):size(size),p(new MoveData[size]){};
        


};
int main(){
    system("cls");
    MoveData m2("John Wick","Chad Stahelski",2014,101);
    return 0;
}

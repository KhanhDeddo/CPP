#include<bits/stdc++.h>
using namespace std;
class Account{
    private:
        static int idNum;
        double id,money;
    public:
        Account(int id, double money){
            setInFor(id,money);
            idNum++;
        }
        Account(Account &ps){
            this->id=ps.id;
            this->money=ps.money;
            idNum++;
        }
        void setInFor(int id, double money){
            this->id=id;
            this->money=money;
        }
        static int getIdNum(){
            return idNum;
        }
        int getId(){
            return id;
        }
        double getMoney(){
            return money;
        }
        void PrintInFor(){
            cout<<"Ma tai khoan: "<<id<<" So tien trong tai khoan: "<<money<<endl;
        }

};
int Account::idNum=0;
int main(){
    Account a1(111,20000), a2(a1);
    cout<<"Tong so tai khoan la: "<<Account::getIdNum()<<endl;
    a1.PrintInFor();
    a2.PrintInFor();
    return 0;
}
#include<iostream>
using namespace std;
void luong(int salary);
void createArray(int a[],int n);
void findMax1Max2(int a[],int n);
bool checkPrime(int n);

int main(){
    int select;
    cout<<"0.shutdown\n";
    cout<<"1.task1\n";
    cout<<"2.task1\n";
    cout<<"3.task1\n";
    select=10;
    while(select){
        cout<<"\nchon bai: \n";
        cin>>select;
        switch (select){
            case 1:{
                int money;
                cout<<"nhap luong nhan vien: ";
                cin>>money;
                luong(money);
                break;
            }
            case 2:{
                int a[10000],n;
                cout<<"nhap do lon cua mang: ";
                cin>>n;
                createArray(a,n);
                findMax1Max2(a,n);
                break;
            }
            case 3:{
                int a;
                cout<<"nhap n: ";
                cin>>a;
                if(checkPrime(a)){
                    cout<<"N la so nguyen to.";}
                else{
                    cout<<"N khong phai la so nguyen to.";}
            }
        }
    }
    return 0;
}
//task1
void luong(int money){
    int salary,thue;
    if(money>15000000){
        thue=money*0.3;
        salary=money-thue;
        cout<<"thue: "<<thue<<endl;
        cout<<"luong rong: "<<salary<<endl;
    }
    else if(money<=15000000 and money>=7000000){
        thue=money*0.2;
        salary=money-thue;
        cout<<"thue: "<<thue<<endl;
        cout<<"luong rong: "<<salary<<endl;
    }
    else if(money<7000000){
        thue=money*0.1;
        salary=money-thue;
        cout<<"thue: "<<thue<<endl;
        cout<<"luong rong: "<<salary<<endl;
    }
}
//task2
void createArray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<"Nhap phan tu["<<i<<"]: "<<endl;
        cin>>a[i];
    }
}
void findMax1Max2(int a[],int n){
    for(int i=0;i<n-1;i++){
        int imin=i;
        for(int j=i+1;j<n;j++){
            if(a[imin]>a[j]){
                int stemp=a[imin];
                a[imin]=a[j];
                a[j]=stemp;
            }
        }
    }
    cout<<"Phan tu lon nhat: "<<a[n-1]<<endl;
    cout<<"Phan tu lon thu 2: "<<a[n-2]<<endl;

}
//task3
bool checkPrime(int n){
    int count=0;
    for(int i=2;i<n;i++){
        if(n%i==0){
            count+=1;
        }
    }
    if (count || n<2) return false;
    else return true;
    
}
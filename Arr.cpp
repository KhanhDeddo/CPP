#include<iostream>
using namespace std;
void Arr(int a[],int count,int n);
int maxA(int a[],int n);
void minA(int a[],int count,int n,int &min);
int main(){
    int n=5,a[n],count=0,min=a[0], max=a[0]; 
    for(int i=0;i<n;i++){
        cout<<"nhap["<<i<<"] ";
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
    }
    Arr(a,count,n);
    cout<<endl;
    for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
    }
    cout<<"\nmax: "<<max;
    cout<<"\nmin: "<<min;
    return 0;
}
void Arr(int a[],int count,int n){
    if(count>=n){}
    else{
        int temp=a[count];
        a[count]=a[n-1];
        a[n-1]=temp;
        Arr(a,count+1,n-1);
    }
}
int maxA(int a[],int n){
    int temp=maxA(a,n-1);
    if(temp>a[n-1]) return a[n-1];
    return temp;

}
void minA(int a[],int count,int n,int &min){
    if(count>=n-1){}
    else{
        if(min>a[count+1]){min=a[count+1];}
        minA(a,count+1,n,min);
    }
}

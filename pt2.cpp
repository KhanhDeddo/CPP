#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	float a,b,c,deta;
	cout<<"nhap a=";
	cin>>a;
	cout<<"nhap b=";
	cin>>b;
	cout<<"nhap c=";
	cin>>c;
if (a==0) 
    if (b==0) cout<<"Phuong trinh vo nghiem"<<endl;
    else if (b== 0&& c==0) cout<<"Phuong trinh vo so nghiem"<<endl;
    else cout <<"x="<< -c/b<<endl;
    
else
{
    deta=b*b-4*a*c;
    if (deta<0) cout<<"Phuong trinh vo nghiem"<<endl;
    else if (deta==0)cout <<"X="<<-b/2*a<<endl;
    else
    {
    cout<<"X1="<<(-b+sqrt(deta))/2*a<<endl;
    cout<<"X2="<<(-b-sqrt(deta))/2*a<<endl;
    }
}
}
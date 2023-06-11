# include <iostream>
using namespace std;
class Cat{
    private:
        string name = " ";
        int number,age,weight;
        int sumW=0;
    public:
        Cat(){}
        Cat(string name, int age, int weight): name(name), age(age), weight(weight){}
        ~Cat(){}
    friend istream &operator>>(istream &in,Cat &c){
        cout<<"nhap ten: ";in>>c.name;
        cout<<"nhap tuoi: ";in>>c.age;
        cout<<"nhap can nang: ";in>>c.weight;
        return in;
    }
    friend ostream &operator<<(ostream &out,Cat &c){
        cout<<"ten: ";out<<c.name<<endl;
        cout<<"tuoi: ";out<<c.age<<endl;
        cout<<"can nang: ";out<<c.weight<<endl;
        cout<<"tong can nang: ";out<<c.sumW<<endl;
        return out;
    }
};
int main(){
    system("cls");
    string name;
    int n,age,weight;
    cout<<"nhap sluong meo: ";
    cin>>n;
    Cat Cat[n]{},c;
    for(int i=0;i<n;i++){
        system("cls");
        cout<<"nhap thong tin meo thu "<<i+1<<endl;
        cin>>Cat[i];
    }
    system("cls");
    cout<<"so sluong con meo: "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<Cat[i]<<endl;
    }
    return 0;
}
# include <iostream>
using namespace std;
class Dog{
    private:
        string name;
        int age;
    public:
        Dog(){}
        Dog(string n, int a): name(n), age(a){}
        operator string(){return this->name;}
        operator int(){return this->age;}
        friend ostream &operator<<(ostream &out,Dog &c){
            cout<<"ten: ";out<<c.name<<endl;
            cout<<"tuoi: ";out<<c.age<<endl;
            return out;
        }
};
class Cat{
    private:
        string name;
        int age;
    public:
        Cat(){}
        Cat(string n, int a): name(n), age(a){}
        operator string(){return this->name;}
        operator int(){return this->age;}
        operator Dog(){return Dog(this->name,this->age+1);}
        friend ostream &operator<<(ostream &out,Cat &c){
            cout<<"ten: ";out<<c.name<<endl;
            cout<<"tuoi: ";out<<c.age<<endl;
            return out;
        }
};

int main(){
    system("cls");
    Cat c1("Tom",2);
    Dog d;
    int a;
    d=c1;
    a=c1;
    cout<<d;
    cout<<a;
    return 0;
}
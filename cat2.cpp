# include <iostream>
using namespace std;
class Cat{
    protected:
        string name;
        int age,weight;
    public:
        Cat(){}
        Cat(string n, int a,int w): name(n), age(a), weight(w){}
        string meow(){
            return "meow meow...";
        }
        void setName(string name){this->name=name;}
        void setAge(int age){this->age=age;}
        void setWeight(int weight){this->weight=weight;}
        string getName(){return name;}
        int getAge(){return age;}
        int getWeight(){return weight;}
};
class ScottishFolh:public Cat{
    private:
        string hair_color,ears,sit_style;
    public:
        friend istream &operator>>(istream &in,ScottishFolh &c){
            cout<<"nhap ten: ";in>>c.name;
            cout<<"nhap tuoi: ";in>>c.age;
            cout<<"nhap can nang: ";in>>c.weight;
            cout<<"nhap mau long: ";in>>c.hair_color;
            cout<<"nhap kieu tai: ";in>>c.ears;
            cout<<"nhap kieu ngoi: ";in>>c.sit_style;
            return in;
        }
        friend ostream &operator<<(ostream &out,ScottishFolh &c){
            cout<<"ten: ";out<<c.getName()<<endl;
            cout<<"tuoi: ";out<<c.getAge()<<endl;
            cout<<"can nang: ";out<<c.getWeight()<<endl;
            cout<<"mau long: ";out<<c.hair_color<<endl;
            cout<<"kieu tai: ";out<<c.ears<<endl;
            cout<<"kieu ngoi: ";out<<c.sit_style<<endl;
            cout<<"tieng keu: ";out<<c.meow()<<endl;
            out<<c.doBuddhaPose();
            return out;
        }
        string doBuddhaPose(){
            return "Purrr, I am doing a Buddha Pose!";
        }
};
int main(){
    ScottishFolh c;
    cin>>c;
    system("cls");
    cout<<c;
    return 0;
}
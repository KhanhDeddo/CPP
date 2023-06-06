# include <iostream>
using namespace std;
class Cat{
    private:
        static int count;
        string name = " ";
        int age,weight;
    public:
        Cat(){count += 1;}
        Cat(string name): name(name){count += 1;}
        Cat(string name, int age): name(name), age(age){count += 1;}
        Cat(string name, int age, int weight): name(name), age(age), weight(weight){count += 1;}
        ~Cat(){}
        const Cat& operator=(const Cat&r);
        Cat operator+(const Cat &that){
            Cat c;
            c.name=this->name+" "+that.name;
            c.age=this->age+that.age;
            c.weight=this->weight+that.weight;
            return c;
        }
        Cat operator+(int w){
            Cat c;
            c.name=this->name+" con";
            c.age=this->age;
            c.weight=this->weight+w;
            return c;
        }
        string getName(){return name;}
        int getAge(){return age;}
        int getWeight(){return weight;}
        int getCount(){return count;}
};
int Cat::count = 0;
int main(){
    system("cls");
    Cat c1("Tom",1,2),c2("Bibi",2,3);
    Cat c3=c1;
    cout <<"So con meo dc tao: "<<c1.getCount()<<endl;
    cout<<c1.getName()<<" "<<c1.getAge()<<" "<<(c1).getWeight()<<endl;
    cout<<c2.getName()<<" "<<c2.getAge()<<" "<<(c2).getWeight()<<endl;
    cout<<(c1+c2).getName()<<" "<<(c1+c2).getAge()<<" "<<(c1+c2).getWeight()<<endl;
    cout<<(c1+10).getName()<<" "<<(c1+10).getAge()<<" "<<(c1+10).getWeight()<<endl;
    cout<<c3.getName()<<" "<<c3.getAge()<<" "<<(c3).getWeight()<<endl;
    return 0;
}

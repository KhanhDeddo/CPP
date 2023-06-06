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
        Cat operator+(const Cat &that){
            this->weight+=that.weight;
            return *this;
        }
        string getName(){return name;}
        int getAge(){return age;}
        int getWeight(){return weight;}
        int getCount(){return count;}
};
int Cat::count = 0;
int main(){
    system("cls");
    Cat c1("tom",2,2),c2("bibi",4,5);
    cout <<"So con meo dc tao: "<<c1.getCount()<<endl;
    cout<<c1.getName()<<" "<<c1.getAge()<<" "<<(c1).getWeight()<<endl;
    cout<<c2.getName()<<" "<<c2.getAge()<<" "<<(c2).getWeight()<<endl;
    cout<<(c1+c2).getName()<<" "<<(c1+c2).getAge()<<" "<<(c1+c2).getWeight()<<endl;
    return 0;
}
#include<iostream>
using namespace std;
class Animal{
    private:
        string name;
    public:
        Animal(string name="Maika") : name(name){}
        virtual void speak(){cout<<"I am "<<name<<endl;}
        void setName(string name){this->name=name;}
        string getName(){return this->name;}
};
class Cat : public Animal{
    public:
        void speak(){cout<<"Meow, I am "<<getName()<<endl;}

};
class Dog : public Animal{
    public:
        void speak(){cout<<"Woff,woff, I am "<<getName()<<endl;}

};class Duck : public Animal{
    public:
        void speak(){cout<<"Quack,quack, I am "<<getName()<<endl;}

};
int main(){
    system("cls");
    Dog myDog;myDog.speak();
    Cat myCat;myCat.speak();
    Duck myDuck;myDuck.speak();

    Animal* dog = new Dog;
    Animal* cat = new Cat;
    Animal* duck = new Duck;
    dog->speak();
    cat->speak();
    duck->speak();
    
    return 0;
}
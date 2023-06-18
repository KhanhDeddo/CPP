#include<iostream>
using namespace std;
class Ship{
    private:
        string name;
        int year;
    public:
        Ship(string name, int year) : name(name), year(year){}
        void setName(string name) { this->name = name;}
        void setYear(int year) { this->year = year;}
        string getName() const { return name; }
        int getYear() const { return year; }
        virtual void print(){
            cout<<"Name of ship: "<<name<<endl;
            cout<<"Year: "<<year<<endl;
        }
};
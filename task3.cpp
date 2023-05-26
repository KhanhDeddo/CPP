#include<bits/stdc++.h>
using namespace std;
class Employee{
    private:
        double idNumber;
        string name;
        string department;
        string position;
    public:
        Employee():name(""), idNumber(0),  department(""), position(""){}
        Employee(string newName, double newId, string newDpm, string newPst):name(newName), idNumber(newId), department(newDpm), position(newPst){}
        void setIdNumber(double newId){
            idNumber = newId;
        }
        void setName(string newName){
            name = newName;
        }
        void setDepartment(string newDpm){
            department = newDpm;
        }
        void setPosition(string newPst){
            position = newPst;
        }
        double getId(){
            return idNumber ;
        }
        string getName(){
            return name;
        }
        string geDepartment(){
            return department;
        }
        string getPosition(){
            return position;
        }        
        void printInfor(){
            cout<<name<<setw(16)<<idNumber<<setw(22)<<department<<setw(18)<<position<<endl;
        }
};
int main(){
    Employee a[3]={
        Employee("Khanh1",45544,"Programer","Dev"),
        Employee("Khanh2",45544,"Programer","Dev"),
        Employee() 
    };
    cout<<"Name"<<setw(20)<<"ID Number"<<setw(20)<<"Department"<<setw(20)<<"Position"<<endl;
    for(int i=0; i<3; i++){
        a[i].printInfor();
    }
    return 0;
}
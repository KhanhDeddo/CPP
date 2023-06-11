#include<iostream>
using namespace std;
class Shape{
    private:
        int area;
    public:
        void setArea(int area){this->area=area;}
        int getArea(){return this->area;}
};
class Circle:public Shape{
    private:
        double radius;
    public:
        void setRadius(int radius){
            this->radius=radius;
            setArea(radius*radius*3.14);
        }
        double getRadius(){return this->radius;}
};

int main(){
    Shape a;
    Circle c;
    a.setArea(19);
    c.setRadius(10);
    system("cls");
    cout<<"Shape: "<<a.getArea()<<endl;
    cout<<"Circle: "<<c.getArea()<<endl;
    return 0;
}
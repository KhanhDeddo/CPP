#include<iostream>
#include<math.h>
using namespace std;
class Shape{
    private:
        double area;
    public:
        void setArea(double area){this->area=area;}
        double getArea(){return area;}
};
class Circle: public Shape{
    private:
        double radius;
    public:
        Circle(){}
        Circle(double radius){
            this->radius=radius;
            setArea(radius*radius*3.14);
        }
        ~Circle(){}
        void setRadius(double radius){
            this->radius=radius;
            setArea(radius*radius*3.14);
        }
        double getRadius(){return radius;}
};
class Hexagon:public Circle{
    private:
        double a;
    public:
        Hexagon(){}
        Hexagon(double a){
            this->a=a;
            setArea((3*sqrt(3)*a*a)/2);
        }
        ~Hexagon(){}
        void setA(double a){
            this->a=a;
            setArea((3*sqrt(3)*a*a)/2);
        }
        double getA(){return a;}


};
int main(){
    Shape s;s.setArea(10);cout<<s.getArea()<<endl;
    Circle c;c.setRadius(10);cout<<c.getArea()<<endl;
    Hexagon h;h.setA(10);cout<<h.getArea()<<endl;
    return 0;
}
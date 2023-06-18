#include<iostream>
using namespace std;
class Shape{
    private:
        double area;
    public:
        Shape(){}
        Shape(int area):area(area){}
        void setArea() {area=calcArea();}
        double getArea() const { return this->area; }
        virtual double calcArea()=0;
};
class Circle : public Shape{
    private:
        int centerX, centerY, radius;
    public:
        Circle(int centerX,int centerY,int radius):centerX(centerX),centerY(centerY),radius(radius){calcArea();}
        void setRadius(double radius) {
            this->radius=radius;
            Shape::setArea();
        }
        int getCenterX() const { return centerX; }
        int getCenterY() const { return centerY; }
        int getRadius() const { return radius; }
        double calcArea(){
            return 3.14*radius*radius;
        }
};
int main() {
    Circle c(1,2,3);
    cout << c.calcArea() << endl;
    c.setRadius(5);
    cout << c.calcArea() << endl;
    cout<<c.getArea()<<endl;
    return 0;
}
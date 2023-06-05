#include<bits/stdc++.h>
using namespace std;
class DayOfYear{
    private:
        int Months[12]={31,28,31,30,31,30,31,31,30,31,30,31}, month=0, day, number;
        string MonthInE[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    public:
        DayOfYear(int number){
            this->number=number;
        }
        void PrintDate(){
                day=number;
                while(day-Months[month]>0){
                    day-=Months[month];
                    month+=1;
                }
                cout<<"Ngay "<<number<<" se la "<<MonthInE[month]<<" "<<day<<endl;
            }
};
int main(){
    DayOfYear day1(2),day2(32),day3(365);
    day1.PrintDate();
    day2.PrintDate();
    day3.PrintDate();
    return 0;
}
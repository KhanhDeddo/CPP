#include<bits/stdc++.h>
using namespace std;
class Numbers{
    private:
        int number;
        string hundred = "hundred";
        string thousand = " thousand";
        string lessThan10[10]={
            "zero","one","two","three","four","five",
            "six","seven","eight","nine"
        };
        string a[9]={
            "ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
        };
    public:
        Numbers(int number){this->number=number;}
        string intToString(){
            if(number<10){
                return lessThan10[number]
            }
            while(number%10!=0){
                while(number%10!=0){

            };
        }


};
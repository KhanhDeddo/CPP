#include<iostream>
using namespace std;
class Numbers{
    private:
        int number,temp,count=0;
        string str;
        string hundred = "hundred";
        string thousand = " thousand";
        string lessThan19[20]={
            "zero","one","two","three","four","five",
            "six","seven","eight","nine","ten",
            "eleven","twelve","thirteen","fourteen","fifteen",
            "sixteen","seventeen","eighteen","nineteen"
        };
        string a[10]={"","",
            "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
        };
    public:
        Numbers(int number){this->number=number;}
        string intToString(){
            if(number<19){return lessThan19[number];}
            while(number!=0){
                count+=1;
                if(count==1 && number%10!=0){
                  str=lessThan19[number%10];
                }
                else if(count==2 && number%10!=0){
                  str=a[number%10]+" "+str;
                }
                number/=10;
            }
          return str;
        }
};
int main(){
  Numbers a(96);
  cout<<a.intToString();
  return 0;
}

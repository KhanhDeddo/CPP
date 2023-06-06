#include<iostream>
using namespace std;
class Numbers{
    private:
        int number,count=0;
        string str;
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
                else if(count==3 && number%10!=0){
                  str=lessThan19[number%10]+" hundred "+str;
                }
                else if(count==4){
                  if(number<20){
                    return lessThan19[number]+" thousand "+str; 
                  }
                  else if(number%10==0){
                    str="thousand "+str;
                  }
                  else if(number%10!=0){
                    str=lessThan19[number%10]+" thousand "+str;
                  }
                }
                else if(count==5 && number%10!=0){
                  str=a[number%10]+" "+str;
                }
                else if(count==6 && number%10!=0){
                  str=lessThan19[number%10]+" hundred "+str;
                }
                number/=10;
            }
          return str;
        }
};
int main(){
  system("cls");
  Numbers a(120456);
  cout<<a.intToString();
  return 0;
}

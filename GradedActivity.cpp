#include<iostream>
using namespace std;
class GradedActivity{
    private:
        double score;
    public:
        GradedActivity(){}
        GradedActivity(double score){
            this->score = score;
            strScore();
        }
        void setScore(double score) {
            this->score = score;
            strScore();
        }
        int getScore() const { return score; }
        string strScore(){
            string str_score;
            if(0<=score && score<=60){str_score="F";}
            else if(60<=score && score<=70){str_score="D";}
            else if(70<=score && score<=80){str_score="C";}
            else if(80<=score && score<=90){str_score="B";}
            else if(90<=score && score<=100){str_score="A";}
            return str_score;
        }
        friend ostream& operator<<(ostream& os, GradedActivity &g){
            os<<"Score"<<endl;
            os<<"Diem theo he so: "<<g.getScore()<<endl;
            os<<"Diem theo he chu: "<<g.strScore()<<endl;
            return os;
        }
};
class FinalExam: public GradedActivity{
    private:
        int sum,sumF;
    public:
        FinalExam(int sum, int sumF){
            SetInfor(sum,sumF);
        }
        void SetInfor(int sum, int sumF){
            this->sum = sum;
            this->sumF = sumF;
            setScore(100-(sumF*100/sum));
        }
        int getSum()const{return sum;}
        int getSumFalse()const{return sumF;}
};
class CurvedActivity:public GradedActivity{
    private:
        double rawScore, rate;
        void setScore(){
            GradedActivity::setScore(rawScore*rate);
        }
    public:
        CurvedActivity(double raw=0, double rate=0){
            rawScore=raw;
            this->rate=rate;
            setScore();
        }
        void setRawScore(double s){
            rawScore=s;
            setScore();
        }
        void setRate(double r){
            rate=r;
            setScore();
        }
        double getRawScore() const {return rawScore;}
        double getRate() const {return rate;}

};
class PassFailedActivity:public GradedActivity{
    private:
        double min_pass;
    public:
        PassFailedActivity(){}
        PassFailedActivity(double score=0, double mp=0){
            GradedActivity::setScore(score);
            min_pass=mp;
        }
        void setMinPass(double min_pass) {this->min_pass=min_pass;}
        double getMinPass() const {return min_pass;}
        string strScore() const {
            string str_score;
            if(getScore()>=min_pass){str_score="Pass";}
            else{str_score="Fail";}
            return str_score;
        }

};
class FailFaileExam:public PassFailedActivity{
    private:
        int sum,sumF;
    public:
        FailFaileExam(int sum = 0, int sumF=0 ,double min_pass = 70):PassFailedActivity(100.0-(sumF*100.0/sum), min_pass){
            this->sum = sum;
            this->sumF = sumF;
        }
        void SetInfor(int sum, int sumF,double min_pass){
            this->sum = sum;
            this->sumF = sumF;
            PassFailedActivity(100-(sumF*100/sum),min_pass);
           
        }
        int getSum()const{return sum;}
        int getSumFalse()const{return sumF;}

};
int main(){
    system("cls");
    FinalExam g(40,15);
    cout<<g<<endl;
    FailFaileExam a(40,12);
    cout<<a.getScore()<<endl;
    cout<<a.strScore()<<endl;
    return 0;
}
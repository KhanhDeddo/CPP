#include<iostream>
using namespace std;
class GradedActivity{
    private:
        int score;
    public:
        GradedActivity(){}
        GradedActivity(int score){
            this->score = score;
            strScore();
        }
        void setScore(int score) {
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
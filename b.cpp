#include <iostream>
using namespace std;
class GradedActivity{
    private:
        double score; // To hold the numeric score
    public:
        GradedActivity(double s=0.0){score = s;}
        void setScore(double s){score = s; }
        double getScore() const{return score; }
        char getLetterGrade() const{
            char letterGrade;
            if (score > 89)letterGrade = 'A';
            else if (score > 79)letterGrade = 'B';
            else if (score > 69)letterGrade = 'C';
            else if (score > 59)letterGrade = 'D';
            else letterGrade = 'F';
            return letterGrade;
        }
};
class Essay:public GradedActivity{
    private:
        int ngu_phap,chinh_ta,do_dai,noi_dung;
        void setScore(){
            GradedActivity::setScore(ngu_phap+chinh_ta+do_dai+noi_dung);
        }
    public:
        Essay(int ngu_phap,int chinh_ta,int do_dai,int noi_dung){
            this->ngu_phap=ngu_phap;
            this->chinh_ta=chinh_ta;
            this->do_dai=do_dai;
            this->noi_dung=noi_dung;
            setScore();
        }
};
int main(){
    Essay e(30,20,20,30);
    cout<<e.getScore();
    return 0;
}
//Ngữ pháp: tối đa 30 điểm
//Chính tả: tối đa 20 điểm
//Độ dài: tối đa 20 điểm
//Nội dung: tối đa 30 điểm

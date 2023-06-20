#include <iostream>
#include <fstream>
using namespace std;

int main () {
   double diem;
   double out_diem;
   ofstream outfile;
   outfile.open("Diemso.txt");
   cout << "Ghi du lieu vao file" << endl;
   cout << "Nhap diem cua ban: ";
   cin>>diem;
   outfile.close();
  
   ifstream infile;
   infile.open("Diemso.txt");
   cout << "Diem cua ban: "<< endl;
   infile<<out_diem;
   cout <<out_diem<< endl;
   infile.close();
   return 0;
}
#include <iostream>
using namespace std;
int main (){
  int num =2;
  int*ptr=&num;
  cout<<"Address of num->"<<&num<<endl;
  cout<<"Address stored in num ->"<<ptr<<endl;
  cout<<"Value of num ->"<<num <<endl;
  cout<<"Value of num using pointer->"<<*ptr<<endl;
  return 0;

}

#include <iostream>
using namespace std;
class student{
  public:
  int rollnumber;
  private:
  int age;
  public:
  student(int a, int r){
      cout<<"this: "<<this<<endl;
      cout<<"Constructor 3 is called: "<<endl;
      rollnumber = r;
      age = a;
  }
  void display(){
      cout<<age<<" "<<rollnumber<<endl;
  }
};

int main()
{
    cout<<"Hello World"<<endl;
    student s1(24,1002);
    cout<<"Adress of memory location of s1: "<<&s1<<endl;
    s1.display();
    return 0;
}
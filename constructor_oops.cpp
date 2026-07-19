#include<iostream>
using namespace std;
class student{
    public:
    int rollnumber;
    private:
    int age;
    public:
    //default constructor
    student(){
        cout<<"Default constructor is called! "<<endl;
    }
    //parameterized constructor
    student(int r){
        rollnumber = r;
        cout<<"parameterized constructor is called! "<<endl;
    }
    //parameterized constructor 2!
    student(int a, int r){
        cout<<"constructor 2 is called: "<<endl;
        age = a;
        rollnumber = r;
    } 
    void display(){
        cout<<age<<" "<<rollnumber<<endl;
    }
};
int main(){
    student s1;
    s1.display();
    student*s2 = new student;
    s2->display();
    cout<<"now parameterized constructor is called! "<<endl;
    student s3(10);
    s3.display();
    student* s4 = new student(101);
    s4 -> display();
    student s5(20,10002);
    s5.display();
    student*s6 = new student(24,2000);
    s6 -> display();
    return 0;
}
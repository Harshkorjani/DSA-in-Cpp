#include<iostream>
using namespace std;
class student{
    public:
    int rollnumber;
    private:
    int age;
    public:
    void display(){
        cout<<age<<" "<<rollnumber<<endl;
    }
    int setAge(int a){
        age = a;
        return age;
    }
};
int main(){
    student s1;
    student* s2 = new student;
    s1.rollnumber = 123;
    s2 -> rollnumber = 124;
    s1.setAge(20);
    s2->setAge(24);
    (*s2).setAge(25);
    s1.display();
    s2 -> display();
    (*s2).display();
    return 0;
}

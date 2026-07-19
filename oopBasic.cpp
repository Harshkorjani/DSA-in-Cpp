#include<iostream>
using namespace std;
class student{
    public:
    int age;
    int rollnumber;
};
int main(){
    //creating object statically
    student s1;
    //creating object dynamically
    student* s2 = new student;
    s1.age = 23;
    s1.rollnumber = 121;

    //(*s2).age = 25;
    //(*s2).rollnumber = 123;
    //both the format are exactly same;
    s2 -> age = 25;
    s2->rollnumber = 123;
    cout<<s1.age<<endl;
    cout<<s1.rollnumber<<endl;
    cout<<s2->age<<endl;
    cout<<s2->rollnumber<<endl;
    return 0;
}

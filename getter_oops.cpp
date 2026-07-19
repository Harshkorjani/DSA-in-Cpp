#include<iostream>
using namespace std;
class student{
    public:
    int rollnumber;
    private:
    int age;
    public:
    void display(){
        cout<<rollnumber<<" "<<age<<endl;
    }
    int getAge(){
        return age;
    }
};
int main(){
    student s1;
    student*s2 = new student;
    cout<<"s1 age: "<<s1.getAge()<<endl;
    s1.display();
    s2 -> rollnumber = 123;
    s2 -> display();
    cout<<"s2 age:"<<s2 -> getAge()<<endl;

    return 0;
}

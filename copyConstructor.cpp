#include <iostream>
using namespace std;
class student{
    public:
    int rollnumber;
    private:
    int age;
    public:
    student(int a, int r){
        cout<<"parametrized constructo is called: "<<endl;
        age = a;
        rollnumber = r;
    }
    void display(){
        cout<<age<<" "<<rollnumber<<endl;
    }
};

int main()
{
    cout<<"Hello World"<<endl;
    student s1(10,1001);
    cout<<"S1: ";
    s1.display();
    
    student s2(s1);
    cout<<"S2: ";
    s2.display();
    
    return 0;
}
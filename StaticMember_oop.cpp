#include<iostream>
using namespace std;
class student {
    static int totalstudents;
    public:
    int rollnumber;
    student(){
        totalstudents++;
    }
    static int getTotalstudent(){
        return totalstudents;
    }
};
int student::totalstudents = 0;
int main(){
    student s1;
    student s2,s3,s4,s5;
    //cout<<student::totalstudents<<endl;
    cout<<student::getTotalstudent()<<endl;
}

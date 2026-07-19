#include<iostream>
using namespace std;
class fraction{
    public:
    int numerator;
    int denominator;

    fraction(int numerator , int denominator){
           this->numerator = numerator;
           this->denominator = denominator;
    }
    //post - increment
    fraction operator++(int){
        fraction fNew(numerator,denominator);
        numerator = numerator + denominator;
        return fNew;
    }
    //pre - increment
    fraction& operator++(){
        numerator = numerator + denominator;
        return *this;
    }
    void print () const{
        cout<<numerator <<"/"<<denominator<<endl;
    }
};
int main(){
    fraction f1(10,2);
    fraction f3 = ++f1;
    f3.print();
    f1.print();
    
    fraction f4(12,2);
    fraction f5 = f4++;
    f4.print();
    f5.print();
    return 0;
}

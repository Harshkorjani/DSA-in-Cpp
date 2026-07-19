#include<iostream>
using namespace std;
void foo(char *a){
    if(*a && *a !='\0'){
        foo(a+1);
        putchar(*a);
    }
}
int main(){
    char a[8] = {'A','B','C','D','E','F','G','H'};

    for(int i = 0; i<8; i++){
        cout<<a[i];
    }
    cout<<endl;
    foo(a);
}
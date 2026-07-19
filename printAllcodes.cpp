#include<iostream>
#include<string>
using namespace std;
int cToi(char c){
    int ans = c - '0';
    return ans;
}
char iToc(int n){
    char ans = 'a' + n - 1;
    return ans;
}
void printAllcodes(string input,string output){
    if(input.size() == 0){
        cout<<output<<endl;
        return;
    }
    char input1 = iToc(cToi(input[0]));
    printAllcodes(input.substr(1), output + input1);
    if(input.size()>1){
        int temp = cToi(input[0])*10 + cToi(input[1]);
        if(temp>=10 && temp<27){
            char input2 = iToc(temp);
            printAllcodes(input.substr(2), output + input2);
        }
    }
}
int main(){
    string input;
    cin>>input;
    string output;
    printAllcodes(input,output);
    return 0;
}

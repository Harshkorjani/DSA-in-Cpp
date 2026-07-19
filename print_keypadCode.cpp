#include<iostream>
#include<string>
using namespace std;

void helper(int num, string output){
    string input;
    if(num == 0){
        cout<<output<<endl;
        return;
    }
    int r = num%10;
    switch(r){
        case 2: input = "abc";
            break;
        case 3: input = "def";
            break;
        case 4: input = "ghi";
            break;
        case 5: input = "jkl";
            break;
        case 6: input = "mno";
            break;
        case 7: input = "pqrs";
            break;
        case 8: input = "tuv";
            break;
        case 9: input = "wxyz";
            break;    
    }
    int len = input.length();
    if(len == 3){
        helper(num/10, input[0] + output);
        helper(num/10, input[1] + output);
        helper(num/10, input[2] + output);

    }
    else{
        helper(num/10, input[0] + output);
        helper(num/10, input[1] + output);
        helper(num/10, input[2] + output);
        helper(num/10, input[3] + output);
    }

}

void printKeypad(int num){
    string output;
    helper(num, output);
}
int main(){
    int num;
    cin>>num;
    printKeypad(num);
    return 0;
}
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int keypad(int num, string output[]){
    string input;
    if(num == 0){
        output[0] = "";
    }

     int n = num%10;
     int count = keypad(num/10,output);
     switch(n){
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

     int ans_size = count*(input.size());
     string temp[ans_size];
     int k = 0;
     for(int i; i<count; i++) {
        for(int j = 0; j<input.size(); j++){
            temp[k] = output[i] + input[j];
        }
     }

     for(int i = 0; i<ans_size; i++){
        output[i] = temp[i];
     }
     return count*input.size();

}

int main(){
    int n;
    cin>>n;
    string* output = new string[1000];
    int store = keypad(n,output);

    for(int i = 0; i<store; i++){
        cout<<output[i]<<endl;
    }
}
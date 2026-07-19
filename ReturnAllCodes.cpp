#include<iostream>
#include<string.h>
using namespace std;
    int cToi(char c){
        int ans = c - '0';
        return ans;
    }
    char iToc(int i){
        char ans = 'a' + i - 1;
        return ans;
    }
int getCodes(string input, string output[10000]){
    if(input.size() == 0){
        output[0] = "";
        return 1;
    }
    string output1[1000];
    string output2[1000];
    char input1 = iToc(cToi(input[0]));
    char input2 = '\0';
    int size2 = 0;
    int size1 = getCodes(input.substr(1), output1);
    if(input.size()>1){
        int temp = cToi(input[0])*10 + cToi(input[1]);
        if(temp>=10 && temp<27){
            input2 = iToc(temp);
            size2 = getCodes(input.substr(2), output2);
        }
    }
    int k = 0; 
    for(int i = 0; i<size1; i++){
        output[i] = input1 + output1[i];
        k++;
    }
    for(int i = 0; i<size2; i++){
        output[i + size1] = input2 + output2[i];
        k++;
    }
    return k;
}
int main(){
    string input;
    cin>>input;
    string output[10000];
    int ans = getCodes(input,output);
    for(int i = 0; i<ans; i++){
        cout<<output[i]<<endl;
    }
    cout<<endl;
    return 0;
}
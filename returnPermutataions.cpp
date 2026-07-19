#include<iostream>
#include<string>
using namespace std;
int returnPermutations(string input, string output[]){
    if(input[0] == '\0'){
        output[0] = "";
        return 1;
    }
    int k = 0;
    for(int i = 0; i<input.size(); i++){
        string output1[9999];
        int size = returnPermutations(input.substr(0,i)+input.substr(i + 1),output1);
        for(int j = 0; j<size; j++){
            output[k++] = input[i] + output1[j];
        }
    }

    return k;
}
int main(){
    string input;
    cin>>input;
    string output[10000];
    int ans = returnPermutations(input,output);
    for(int i = 0; i<ans; i++){
        cout<<output[i]<<endl;
    }
    cout<<ans;
    return 0;
}

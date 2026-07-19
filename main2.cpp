#include<iostream>
using namespace std;

void remove_character( char input[], char c){
   int i = 0;
   for(int j = 0; input[j] != '\0';){
      if(input[j] == c){
        j++;
      }
      else{
        input[i] = input[j];
        i++;
        j++;
      }
   }
   input[i] = '\0';
}
  

int main(){

   char input[100];
   cin>>input;
   
   int count = 0;
   for(int i = 0; input[i] != '\0';i++){
      count++;
   }
   int len = count;
   cout<<"Length of the string is: "<<len<<endl;
   
   
   char c;
   cout<<"Enter the character to remove: ";
   cin>>c;
   
   
   remove_character(input, c);
   
   cout<<input<<endl;   
}
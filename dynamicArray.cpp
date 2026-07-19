#include<iostream>
using namespace std;
class dynamicArray{
    int *data;
    int capacity;
    int nextIndex;
    public:
     dynamicArray(){
        data = new int[5];
        capacity = 5;
        nextIndex = 0;
     }
     dynamicArray(dynamicArray const &d){
        this->data = new int[d.capacity];
        for(int i = 0; i<d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
     }
     void operator=(dynamicArray const &d){
        this->data = new int[d.capacity];
        for(int i = 0; i<d.nextIndex; i++){
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
     }

     void add(int element){
        if(nextIndex == capacity){
            int *newdata = new int[2*capacity];
            for(int i = 0; i<capacity; i++){
                newdata[i] = data[i];
            }
            delete [] data;
            data = newdata;
            capacity *= 2;
        }
        data[nextIndex] = element;
        nextIndex++;
     }
     int get(int i) const{
        if (i<nextIndex){
            return data[i];
        }
        else{
            return -1;
        }
     }
     void add(int i, int element){
        if(i<nextIndex){
            data[i] = element;
        }
        else if(i ==  nextIndex){
            add(element);
        }
        else{
            return;
        }
     }
     void print() const{
        for(int i = 0; i<nextIndex; i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
     }
};
int main(){
    dynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    dynamicArray d2(d1);
    dynamicArray d3;
    d3 = d1;
    d1.add(0,100);
    d1.print();
    d2.print();
    d3.print();

    return 0;
}

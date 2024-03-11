#include<iostream>

using namespace std;

class Stack{
    int top;
    int *arr[];
    int stacksize;
    

    Stack():Stack(5){}

    Stack(int size):top(-1),stacksize(size),arr(arr[size]){
        
        cout<<"Stack Created\n";

    }
}
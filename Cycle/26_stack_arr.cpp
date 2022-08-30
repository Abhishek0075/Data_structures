#include<iostream>
using namespace std;
class stack{
    int max;
    int* arr;
    int top;
public: 
    stack(int n){
        int* arr=new int[n];
        max=n;
        top=0;
    }
    void push(int num){
        if(top==max){
            cout<<"OVERFLOW";
            return;
        }
        arr[top+1]=num;
        top=top+1;
        return;
    }
    int pop(void){
        int item=arr[top-1];
        top-=1;
        return item;
    }
    void printStack(void){
        for(int i=1;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(void){
    int no_element,ele,item,popper;
    cout<<"Enter the length of the stack : ";
    cin>>no_element;
    stack stk(no_element);
    cout<<"Enter the number of elements to be pushed : ";
    cin>>ele;
    for(int i=0;i<ele;i++){
        cout<<"Enter the element to be pushed : ";
        cin>>item;
        stk.push(item);
    }
    cout<<"Stack after pushing :-\n";
    stk.printStack();
    cout<<"Stack after popping :-\n";
    // popper=stk.pop();
    // cout<<"Element popped : "<<popper<<endl;
    stk.printStack();
    
    return 0;
}
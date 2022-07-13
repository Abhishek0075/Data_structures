#include<iostream>
using namespace std;

void insertion_sort(int arr[],int no_element){
    int ptr,temp;
    for(int i=0;i<no_element;i++){
        temp[i]=arr[i];
        ptr=i-1;
        while(temp<arr[i]){
            arr[ptr+1]=arr[ptr];
            ptr=ptr-1;
        }
        arr[ptr+1]=temp;
    }
}
int main(){
    
    return 0;
}
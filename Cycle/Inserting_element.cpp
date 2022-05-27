#include<iostream>
using namespace std;
void insert(int arr[],int element_no,int insert_position,int item){
    int new_no=element_no-1;
    while(new_no==insert_position){
        arr[new_no]=arr[new_no+1];
        new_no=new_no-1;
    }
    arr[insert_position]=item;
    element_no=element_no+1;
    for(int i=0;i<element_no;i++){
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int data[10]={10,3,6,7,9,77,8,11,23,4};
    cout<<"Before function : "<<endl;
    for(int i=0;i<10;i++){
        cout<<data[i]<<" ";
    }
    
    cout<<endl<<"After function : "<<endl;
    insert(data,10,8,17);
    return 0;
}
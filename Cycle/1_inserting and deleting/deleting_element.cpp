#include<iostream>
using namespace std;
int* delete_element(int arr[],int no_element,int del_pos){
    while(del_pos<=no_element){
        arr[del_pos-1]=arr[del_pos];
        del_pos=del_pos+1;
    }
    no_element=no_element-1;
    return arr;
}
void display_array(int arr[],int no_element){
    for(int i=0;i<no_element;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int num_element,pos;
    cout<<"Enter the number of elements : ";
    cin>>num_element;
    int data[num_element];
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<num_element;i++){
        cout<<" >> ";
        cin>>data[i];
    }
    cout<<"Before deletion : ";
    display_array(data,num_element);
    cout<<"Enter the position to be deleted : ";
    cin>>pos;
    int *new_arr;
    cout<<"After deletion : ";
    new_arr=delete_element(data,num_element,pos);
    display_array(new_arr,num_element-1);
    return 0;
}

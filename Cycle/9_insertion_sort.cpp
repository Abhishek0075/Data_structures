#include<iostream>
using namespace std;
void insertion_sort(int arr[],int no_element){
    arr[0]=-999;
    int temp,ptr;
    for(int k=2;k<no_element;k++){
        temp=arr[k]; 
        ptr=k-1;
        while(temp<arr[ptr]){
            arr[ptr+1]=arr[ptr];
            ptr=ptr-1;
        }
        arr[ptr+1]=temp;
    }
    for(int i=1;i<no_element;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int no_elements;
    cout<<"Enter the number of elements in the array : ";
    cin>>no_elements;
    int mod_elements=no_elements+1;
    int data[mod_elements];
    cout<<"Enter the elements in the array "<<endl;
    for(int i=1;i<mod_elements;i++){
        cin>>data[i];
    }
    cout<<"Before insertion sort : "<<endl;
    for(int i=1;i<no_elements+1;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<"After insertion sort : "<<endl;
    insertion_sort(data,mod_elements);
    cout<<endl;    
    return 0;
}
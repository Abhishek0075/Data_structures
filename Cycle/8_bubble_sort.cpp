#include<iostream>
using namespace std;
void bubble_sort(int arr[],int no_element){
    int temp,ele=no_element;
    while(no_element>1){
        for(int i=0;i<no_element-1;i++){
            if(arr[i+1]<arr[i]){
                temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
            }
        }
        no_element=no_element-1;
    }
    for(int i=0;i<ele;i++){
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int no_element;
    cout<<"Enter the number of elements in the array : ";
    cin>>no_element;
    int array[no_element];
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<no_element;i++){
        cin>>array[i];
    }
    cout<<endl;
    cout<<"Before bubble sort : "<<endl;
    for(int i=0;i<no_element;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"After bubble sort : "<<endl;
    bubble_sort(array,no_element);
    cout<<endl;
    return 0; 
}
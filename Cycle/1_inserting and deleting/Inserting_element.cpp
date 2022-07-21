#include<iostream>
using namespace std;
void insert(int arr[],int element_no,int insert_position,int item){
    int new_no=element_no-1;
    while(new_no>=insert_position){
        arr[new_no+1]=arr[new_no];
        new_no=new_no-1;
    }
    arr[insert_position]=item;
    element_no=element_no+1;
    for(int i=0;i<element_no;i++){
        cout<<arr[i]<<" ";
    }
    
}
int main(){
    int no_element,pos,new_ele;
    cout<<"Enter the number of elements in the array : ";
    cin>>no_element;
    int data[no_element];
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<no_element;i++){
        cout<<" >> ";
        cin>>data[i];
    }
    cout<<"The entered array : "<<endl;
    for(int i=0;i<no_element;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the position to which the element is to be inserted : ";
    cin>>pos;
    cout<<"Enter the element to be inserted : ";
    cin>>new_ele;
    cout<<endl<<"After insertion : "<<endl;
    insert(data,no_element,pos,new_ele);
    return 0;
}
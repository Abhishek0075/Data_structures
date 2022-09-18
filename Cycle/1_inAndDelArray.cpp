#include<iostream>
using namespace std;
void display_array(int arr[],int no_element){
    for(int i=0;i<no_element;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void delete_element(int arr[],int no_element,int del_pos){
    while(del_pos<=no_element){
        arr[del_pos-1]=arr[del_pos];
        del_pos=del_pos+1;
    }
    no_element=no_element-1;
    display_array(arr,no_element);
}
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
    int num_element,pos,selector=1,new_ele;
    cout<<"Enter the number of elements : ";
    cin>>num_element;
    int data[num_element];
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<num_element;i++){
        cout<<" >> ";
        cin>>data[i];
    }
    while(selector>0 and selector<3){
        cout<<endl;
        cout<<"\n1 for inserting\n2 for deleting\nOther keys to EXIT\n";
        cout<<"Enter your input : ";
        cin>>selector;
        if(selector==1){
            cout<<"The entered array : "<<endl;
            for(int i=0;i<num_element;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
            cout<<"Enter the position to which the element is to be inserted : ";
            cin>>pos;
            cout<<"Enter the element to be inserted : ";
            cin>>new_ele;
            cout<<endl<<"After insertion : "<<endl;
            insert(data,num_element,pos,new_ele);
        }else if(selector==2){
            cout<<"Before deletion : ";
            display_array(data,num_element);
            cout<<"Enter the position to be deleted : ";
            cin>>pos;
            cout<<"After deletion : ";
            delete_element(data,num_element,pos);
        }
    }
    return 0;
}

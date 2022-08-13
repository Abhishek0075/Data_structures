#include<iostream>
using namespace std;
class node{
public:
    int info;
    node* back;
    node* forw;
    node(){
        info=0;
        back=NULL;
        forw=NULL;
    }
    node(int num){
        info=num;
        back=NULL;
        forw=NULL;
    }
};
class linked_list{
    node* start;
    node* end;
    node* header;
public:
    linked_list(int arr[],int num){
        header=NULL;
        start=NULL;
        end=NULL;
        for(int i=0;i<num;i++){
            insert_node(arr[i]);
        }
    }
    void insert_node(int value){
        node* new_node=new node(value);
        if(header==NULL){
            header=new_node;
            start=header;
            return;
        }
        node* ptr=header;
        while (ptr->forw!=NULL){
            ptr=ptr->forw;
        }
        ptr->forw=new_node;
        new_node->back=ptr;
        end=new_node;
    }
    void search(int item){
        node* ptr=start;
        int count=1;
        while(ptr!=NULL){
            if(ptr->info==item){
                cout<<ptr->info<<" found at "<<count<<endl;
                return;
            }
            count+=1;
            ptr=ptr->forw;
        }
        cout<<"Item not found !!";
    }
};
int main(){
    int element,search_key;
    cout<<"Enter the number of nodes in linked list : ";
    cin>>element;
    int arr[element];
    cout<<"Enter the element of the linked list : "<<endl;
    for(int i=0;i<element;i++){
        cout<<">> ";
        cin>>arr[i];
    }
    linked_list list(arr,element);
    cout<<"Enter the number to be searched : ";
    cin>>search_key;
    list.search(search_key);
    return 0;
}
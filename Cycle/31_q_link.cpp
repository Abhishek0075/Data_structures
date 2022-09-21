#include<iostream>
using namespace std;
class node{
public:
    int info;
    node* link;
    node(){
        info=0;
        link=NULL;
    }
    node(int value){
        info=value;
        link=NULL;
    }
    int get_info(void){
        return info;
    }
};
class linked_list{
    node* front=NULL;
    node* rear=NULL;
public:
    linked_list(){}
    linked_list(int arr[],int no_element){
        for(int i=0;i<no_element;i++){
            push(arr[i]);
        }
    }
    void push(int value){
        node* new_node=new node(value);
        if(new_node==NULL){
            cout<<"Over Flow"<<endl;
            return;
        }
        if(rear==NULL){
            front=new_node;
            rear=new_node;
            return;
        }
        rear->link=new_node;
        rear=new_node;
    }
    void pop(int &item){
        if(front==NULL){
            cout<<"UNDER FLOW"<<endl;
            return ;
        }
        node* temp=front;
        item=front->info;
        front=front->link;
        temp->link=NULL;
        delete temp;
        return;
    }
    void display(void){
        node* ptr=front;
        while(ptr!=NULL){
            cout<<ptr->info<<endl;
            ptr=ptr->link;
        }
    }
};
int main(){
    int insert_info,no_nodes,search_key;
    cout<<"Enter the number of nodes to be created : "<<endl;
    cin>>no_nodes;
    int a[no_nodes];
    cout<<"Enter the number to be inserted in the list : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>a[i];
    }
    cout<<"Queue after pushing the given elements :- "<<endl;
    linked_list list(a,no_nodes);
    list.display();
    cout<<"Queue after popping  :- "<<endl;
    int popper;
    list.pop(popper);
    list.display();
    cout<<"Element popped : "<<popper<<endl;
    return 0;
}
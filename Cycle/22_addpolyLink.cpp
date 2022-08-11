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
    node* start=NULL;
public:
    linked_list(){}
    linked_list(int arr[],int no_element){
        for(int i=0;i<no_element;i++){
            insert_node(arr[i]);
        }
    }
    void insert_node(int value){
        node* new_node=new node(value);
        if(new_node==NULL){
            cout<<"Over Flow"<<endl;
            return;
        }
        if(start==NULL){
            start=new_node;
            return;
        }
        node* ptr=start;
        while (ptr->link!=NULL){
            ptr=ptr->link;
        }
        ptr->link=new_node;
    }
    
    void add_poly(linked_list list){
        node* ptr1=start;
        node* ptr2=list.start;
        while(ptr1!=NULL and ptr2!=NULL){
            ptr1->info=ptr1->info+ptr2->info;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
    }
    
    void print_link(void){
        node* ptr=start;
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            ptr=ptr->link;
        }
    }
};
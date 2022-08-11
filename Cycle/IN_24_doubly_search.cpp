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
    node* header=new node();
public:
    linked_list(){
        start=header;
        end=header;
    }
    void insert_node(int value){
        node* new_node=new node(value);
        if(header->forw==NULL and header->back==NULL){
            header=new_node;
            return;
        }
        node* ptr=header;
        while (ptr->forw!=NULL){
            ptr=ptr->forw;
        }
        ptr->forw=new_node;
        new_node->back=ptr;
    }

};
int main(){
    linked_list list;
    int arr[7]={9,54,22,11,10,76,5};
    
    
    
    return 0;
}
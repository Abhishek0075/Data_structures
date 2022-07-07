#include<iostream>
using namespace std;
class node{
public:
    node* leftSide;
    node* rightSide;
    node* parent;
    int info;
    node(){
        leftSide=NULL;
        rightSide=NULL;
        parent=NULL;
        info=0;
    }
    node(int num){
        leftSide=NULL;
        rightSide=NULL;
        parent=NULL;
        info=num;
    }
};
class tree{
    node* start;
public:
    tree(){
        start=NULL;
    }
    void insert_node(int num){
        node* new_node=new node(num);
        if(new_node==NULL){
            cout<<"Over Flow"<<endl;
            return;
        }
        if(start==NULL){
            start=new_node;
            return;
        }
        node* ptr=start;
        while(ptr->rightSide!=NULL or ptr->leftSide!=NULL){
            if(new_node->info<ptr->info){
                ptr=ptr->leftSide;
            }else{
                ptr=ptr->rightSide;
            }
        }
        if(ptr->leftSide==NULL){
            ptr->leftSide=new_node;
        }
        if(ptr->rightSide==NULL){
            ptr->rightSide=new_node;
        }
        new_node->rightSide=NULL;
        new_node->leftSide=NULL;
    }
};
int main(){

    return 0;
}
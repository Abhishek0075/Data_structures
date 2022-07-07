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
    node* start=NULL;
public:
    tree(){}
    void insert_node(int num){
        int count;
        node* newNode=new node(num);
        if(newNode==NULL){
            cout<<"Over Flow"<<endl;
            return;
        }
        if(start==NULL){
            start=newNode;
            return;
        }
        node* ptr=start;
        while(ptr->leftSide!=NULL and ptr->rightSide!=NULL){
            newNode->parent=ptr;
            if(newNode->info<ptr->info){
                ptr=ptr->leftSide;
            }else{
                ptr=ptr->rightSide;
            }
        }
        if(newNode->info<ptr->info){
            ptr->leftSide=newNode;
        }else{
            ptr->rightSide=newNode;
        }
        newNode->parent=ptr->parent;
        newNode->rightSide=NULL;
        newNode->leftSide=NULL;
    }
};
int main(){
    tree t;
    t.insert_node(10);
    t.insert_node(9);
    t.insert_node(31);
    t.insert_node(30);
    t.insert_node(8);
    t.insert_node(50);
    return 0;
}
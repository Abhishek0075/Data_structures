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
    node(int VALUE){
        info=VALUE;
        link=NULL;
    }
};
class linked_list{
    node* start=NULL;
public:
    linked_list(){}
    linked_list(int ARR[],int NO_ELEMENT){
        for(int i=0;i<NO_ELEMENT;i++){
            insert_node(ARR[i]);
        }
    }
    void insert_node(int VALUE){
        node* new_node=new node(VALUE);
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
        new_node->link=NULL;
    }
    void find(int ITEM,node*& LOC,node*& LOCP){
        node* save;
        node* ptr;
        if(start==NULL){
            LOC=NULL,LOCP=NULL;
            return;
        }
        if(start->info==ITEM){
            LOC=start;
            LOCP=NULL;
            return;
        }
        save=start;
        ptr=start->link;
        while(ptr!=NULL){
            if(ptr->info==ITEM){
                LOC=ptr;
                LOCP=save;
                return;
            }
            save=ptr;
            ptr=ptr->link;
        }
        LOC=NULL;
        return;
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
    linked_list list(a,no_nodes);
    node* node1=new node();
    node* node2=new node();
    cout<<"Enter the number to be searched in the list : "<<endl;
    cin>>search_key;
    list.find(search_key,node1,node2);
    return 0;
}

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
    void search_list(int item){
        int count=1;
        while(start!=NULL){
            if(start->info==item){
                cout<<"ITEM FOUND at the position from the start : "<<count<<endl;
                return;
            }
            start=start->link;
            count+=1;
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
    linked_list list(a,no_nodes);
    cout<<"Enter the number to be searched in the list : "<<endl;
    cin>>search_key;
    list.search_list(search_key);
    return 0;
}
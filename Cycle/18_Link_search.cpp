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
    node* start;
public:
    linked_list(){
        start=NULL;
    }
    void insert_node(int value){
        node* new_node=new node(value);
        cout<<"Constructed";
        if(start==NULL){
            start=new_node;
            cout<<"Entered start"<<endl;

        }
        cout<<"Hai";
        node* ptr=start;
        while (ptr->link!=NULL){
            ptr=ptr->link;
            cout<<"Entered link "<<endl;

        }
        ptr->link=new_node;
        new_node->link=NULL;
    }
    void search_list(int item){
        int count=1;
        while(start!=NULL){
            if(start->info==item){
                cout<<"ITEM FOUND at : "<<count<<endl;
                return;
            }
            start=start->link;
            count+=1;
            cout<<"HAi at search list" <<endl;
        }
    }
};
int main(){
    linked_list list;
    
    list.insert_node(12);
    list.insert_node(13);
    list.search_list(13);
    return 0;
}
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
    node* get_link(void){
        return link;
    }
};
class linked_list{
    node* start=NULL;
public:
    linked_list(){}
    linked_list(int arr[],int no_element){
        for(int i=0;i<no_element;i++){
            create_node(arr[i]);
        }
    }

    void create_node(int value){
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
        new_node->link=NULL;
    }

    node* find(int item){//Finds an item and gives location and     
        node* ptr=start->link;//by calling insert we add element to that loc
        node* save=start;
        if(start==NULL){
            return NULL;
        }
        if(start->info>=item){
            return start;
        }
        while(ptr!=NULL){
            if((ptr)->info>=item)
            {
                return save;
            }else{
                save=ptr;
                ptr=ptr->link;
            }
        }
        return save;
    }
    void insert(int item){
        node* new_node=new node(item);
        node* loc=find(item);
        if(loc==NULL){
            new_node->link=start;
            start=new_node;
            return;
        }else if(loc==start){
            new_node->link=start;
            start=new_node;
        }else{
            new_node->link=loc->link;
            loc->link=new_node;
            return;
        }
    }
    
    void print_linkList(){
        node* ptr=start;
        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->link;
        }
        cout<<endl;
    }
};

int main(void){
    int no_nodes,num_insert;
    cout<<"Enter the number of nodes to be created : ";
    cin>>no_nodes;
    int list_arr[no_nodes];
    cout<<"Enter the node values in the list(Ascending order) : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>list_arr[i];
    }
    linked_list list(list_arr,no_nodes);
    cout<<"The list before inserting : "<<endl;
    list.print_linkList();
    cout<<"Enter the number to be inserted : ";
    cin>>num_insert;
    list.insert(num_insert);
    cout<<"The list after inserting : "<<endl;
    list.print_linkList();
    return 0;
}
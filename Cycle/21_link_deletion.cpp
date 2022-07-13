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
        // cout<<"Constructed";
        if(start==NULL){
            start=new_node;
            return;
            // cout<<"Entered start"<<endl;

        }
        // cout<<"Hai";
        node* ptr=start;
        while (ptr->link!=NULL){
            ptr=ptr->link;
            // cout<<"Entered link "<<endl;

        }
        ptr->link=new_node;
        new_node->link=NULL;
    }
    void find(int ITEM,node*& loc,node*& locp){
        node* save;
        node* ptr;
        if(start==NULL){
            loc=NULL,locp=NULL;
            return;
        }
        if(start->info==ITEM){
            loc=start;
            locp=NULL;
            return;
        }
        save=start;
        ptr=start->link;
        while(ptr!=NULL){
            if(ptr->info==ITEM){
                loc=ptr;
                locp=save;
                return;
            }
            save=ptr;
            ptr=ptr->link;
        }
        loc=NULL;
        return;
    }
    void deletion(int ITEM){
        node* loc=new node();
        node* locp=new node();
        find(ITEM,loc,locp);
        if(loc==NULL){
            cout<<ITEM<<" not in the list";
            return;
        }
        if(locp==NULL){
            start=start->link;
        }else{
            locp->link=loc->link;
        }
    }
};
int main(){
    int insert_info,no_nodes,delete_key;
    cout<<"Enter the number of nodes to be created : "<<endl;
    cin>>no_nodes;
    int a[no_nodes];
    cout<<"Enter the number to be inserted in the list : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>a[i];
    }
    linked_list list(a,no_nodes);
    
    cout<<"Enter the number to be searched in the list : "<<endl;
    cin>>delete_key;
    list.deletion(delete_key);
    return 0;
}
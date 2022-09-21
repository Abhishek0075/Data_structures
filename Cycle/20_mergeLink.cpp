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
    friend void merge(linked_list list1,linked_list list2);
};
void merge(linked_list list1,linked_list list2){
        linked_list* new_list=new linked_list();
        node* temp1 = list1.start;
        node* temp2 = list2.start;
        while(temp1 != NULL and temp2 != NULL){
            if (temp1->info > temp2->info){
                new_list->insert_node(temp2->info);
                temp2 = temp2->link;
            }else{
                new_list->insert_node(temp1->info);
                temp1 = temp1->link;
            }
        }
        while(temp1 != NULL){
            new_list->insert_node(temp1->info);
            temp1 = temp1->link;
        }
        while(temp2 != NULL){
            new_list->insert_node(temp2->info);
            temp2 = temp2->link;
        }
        cout<<"The merged linked list : ";
        node* ptr=new_list->start;
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            ptr=ptr->link;
        }
        cout<<endl;
    }
int main(){
    int no_nodes;
    cout<<"FIRST LINKED LIST : "<<endl;
    cout<<"Enter the number of nodes to be created : "<<endl;
    cin>>no_nodes;
    int a[no_nodes];
    cout<<"Enter the number to be inserted in the list : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>a[i];
    }
    linked_list list1(a,no_nodes);
    cout<<"SECOND LINKED LIST : "<<endl;
    int no_nodes1;
    cout<<"Enter the number of nodes to be created : "<<endl;
    cin>>no_nodes1;
    int b[no_nodes1];
    cout<<"Enter the number to be inserted in the list : "<<endl;
    for(int i=0;i<no_nodes1;i++){
        cin>>b[i];
    }
    linked_list list2(b,no_nodes1);
    merge(list1,list2);
    return 0;
}
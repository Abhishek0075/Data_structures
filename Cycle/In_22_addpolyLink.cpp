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
    }
    
    void add_poly(linked_list list){
        linked_list* new_list=new linked_list();
        node* ptr1=start;
        node* ptr2=list.start;
        int temp;
        while(ptr1!=NULL and ptr2!=NULL){
            temp=ptr1->info+ptr2->info;
            new_list->create_node(temp);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        if(ptr1!=NULL){
            new_list->create_node(ptr1->info);
            ptr1=ptr1->link;
        }else{
            new_list->create_node(ptr2->info);
            ptr2=ptr2->link;
        }

        new_list->print_poly();
    }
    
    void print_poly(void){
        node* ptr=start;
        while(ptr!=NULL){
            cout<<"("<<ptr->info<<")";
            if(ptr->link==NULL){
                cout<<"x^"<<ptr->info<<endl;
            }else{
                cout<<"x^"<<ptr->info<<"+";
            }
            ptr=ptr->link;
        }
    }
};
int main(void){
    int arr1[7]={23,11,6,7,18,19,100};
    int arr2[5]={12,4,3,10,87};
    linked_list list1(arr1,7);
    linked_list list2(arr2,5);
    list1.add_poly(list2);
    return 0;
}
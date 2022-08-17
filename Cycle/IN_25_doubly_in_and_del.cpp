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
    node* header;
public:
    linked_list(int arr[],int num){
        header=NULL;
        start=NULL;
        end=NULL;
        for(int i=0;i<num;i++){
            create_node(arr[i]);
        }
    }
    void create_node(int value){
        node* new_node=new node(value);
        if(header==NULL){
            header=new_node;
            start=header;
            return;
        }
        node* ptr=header;
        while (ptr->forw!=NULL){
            ptr=ptr->forw;
        }
        ptr->forw=new_node;
        new_node->back=ptr;
        end=new_node;
    }
    node* find(int item){//Finds an item and gives location and by calling insert we add element to that loc
        node* ptr=start;
        node* save;
        if(start==NULL){
            return NULL;
        }
        while(ptr->forw!=NULL){
            if((ptr)->info>=item)
            {
                return save;
            }else{
                save=ptr;
                ptr=ptr->forw;
            }
        }
        return ptr;
    }
    void insert(int item){
        node* new_node=new node(item);
        node* loc=find(item);
        if(loc==NULL){
                new_node->forw=start;
                start=new_node;
                return;
        }else{
            new_node->forw=loc->forw;
            new_node->back=loc;
            loc->forw=new_node;
            return;
        }
    }
};
int main(){
    int element,inserter;
    cout<<"Enter the number of nodes in linked list : ";
    cin>>element;
    int arr[element];
    cout<<"Enter the element of the linked list : "<<endl;
    for(int i=0;i<element;i++){
        cout<<">> ";
        cin>>arr[i];
    }
    linked_list list(arr,element);
    cout<<"Enter the number to be inserted : ";
    cin>>inserter;
    list.insert(inserter);
    return 0;
}
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
    node* start=NULL;
    node* end=NULL;
public:
    linked_list(int arr[],int num){
        for(int i=0;i<num;i++){
            create_node(arr[i]);
        }
    }
    void create_node(int value){
        node* new_node=new node(value);
        if(start==NULL){
            start=new_node;
            end=new_node;
            return;
        }
        node* ptr=start;
        while (ptr->forw!=NULL){
            ptr=ptr->forw;
        }
        ptr->forw=new_node;
        new_node->back=ptr;
        end=new_node;
    }
    node* insertFind(int item){//Finds an item and gives location and by calling insert we add element to that loc
        node* ptr=start;
        while(ptr->forw!=NULL){
            if((ptr)->info>=item)
            {
                return ptr;
            }else{
                ptr=ptr->forw;
            }
        }
        return NULL;
    }
    void insert(int item){
        node* new_node=new node(item);
        node* loc=insertFind(item);
        if(loc==start){
            start=new_node;
            new_node->forw=loc;
            new_node->back=NULL;
            loc->back=new_node;
        }else if(loc==NULL){
                new_node->forw=NULL;
                new_node->back=end;
                end=new_node;
                return;
        }else{
            new_node->forw=loc;
            new_node->back=loc->back;
            (loc->back)->forw=new_node;
            return;
        }
    }
    void print_list(void){
        node* ptr=start;
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            ptr=ptr->forw;
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
    list.print_list();
    return 0;
}
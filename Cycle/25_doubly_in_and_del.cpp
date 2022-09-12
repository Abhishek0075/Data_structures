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
    node* Find(int item){//Finds an item and gives location and by calling insert we add element to that loc
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
        node* loc=Find(item);
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
    node* delFind(int item){
        node* ptr=start;
        while(ptr!=NULL){
            if(ptr->info==item){
                return ptr;
            }
            ptr=ptr->forw;
        }
        return NULL;
    }
    void del(int item){
        node* loc=delFind(item);
        if(loc==NULL){
            cout<<"Item not in the list\n";
            return;
        }else if(loc==start){
            (loc->forw)->back=NULL;
            start=loc->forw;
        }else if(loc==end){
            (loc->back)->forw=NULL;
            end=loc->back;
        }else{
            (loc->forw)->back=loc->back;
            (loc->back)->forw=loc->forw;
        }
    }
    void print_forw(void){
        node* ptr=start;
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            ptr=ptr->forw;
        }
    }
    void print_back(void){
        node* ptr=start;
        while(ptr->forw!=NULL){
            ptr=ptr->forw;
        }
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            ptr=ptr->back;
        } 
    }
};
int main(void){
    int element,selector=1,actor;
    cout<<"Enter the number of nodes in linked list : ";
    cin>>element;
    int arr[element];
    cout<<"Enter the element of the linked list : "<<endl;
    for(int i=0;i<element;i++){
        cout<<">> ";
        cin>>arr[i];
    }
    linked_list list(arr,element);
    while (selector>=1 and selector<=2){
        cout<<"\n\nEnter 1 for inserting \nEnter 2 for deleting\nEnter 3 for exiting\n >>> ";
        cin>>selector;
        if(selector==1){
            cout<<"Enter the number to be inserted : ";
            cin>>actor;
            list.insert(actor);
            cout<<"Printing forward : ";
            list.print_forw();
            cout<<endl;
            cout<<"Printing backwards : ";
            list.print_back();
        }else if(selector==2){
            cout<<"Enter the number to be deleted : ";
            cin>>actor;
            list.del(actor);
            cout<<"Printing forward : ";
            list.print_forw();
            cout<<endl;
            cout<<"Printing backwards : ";
            list.print_back();
        }
    }    
    return 0;
}
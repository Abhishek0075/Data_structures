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
class stack{
    node* top=NULL;
public:
    stack(){}
    stack(int arr[],int no_element){
        for(int i=0;i<no_element;i++){
            push(arr[i]);
        }
    }
    
    void push(int num){
        node* new_item=new node(num);
        if(new_item==NULL){
            cout<<"OVERFLOW"<<endl;
            return;
        }
        new_item->info=num;
        new_item->link=top;
        top=new_item;
    }
    int pop(void){
        node* popped;
        int popped_info;
        popped=top;
        popped_info=top->info;
        top=top->link;
        delete popped;
        return popped_info;
    }
    void print_stack(void){
        node* ptr=top;
        while(ptr!=NULL){
            cout<<ptr->info<<endl;
            ptr=ptr->link;
        }
        cout<<endl;
    }
};
int main(){
    int insert_info,no_nodes,search_key;
    cout<<"Enter the length of the stack : ";
    cin>>no_nodes;
    int a[no_nodes];
    cout<<"Enter the number to be pushed into the stack : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>a[i];
    }
    stack stk(a,no_nodes);
    stk.print_stack();
    cout<<"Stack after pushing :- "<<endl;
    stk.print_stack();
    int result=stk.pop();
    cout<<"Stack after popping :- "<<endl;
    stk.print_stack();
    return 0;
}
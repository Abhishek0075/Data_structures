#include<iostream>
using namespace std;
class node{
public:
    int info;
    node* leftSide;
    node* rightSide;
    node* parent;
    
    node(){
        leftSide=NULL;
        rightSide=NULL;
        parent=NULL;
        info=0;
    }
    node(int num){
        leftSide=NULL;
        rightSide=NULL;
        parent=NULL;
        info=num;
    }
};
class tree{
    node* start;
public:
    tree(){
        start=NULL;
    }
    tree(int arr[],int no_element){
        for(int i=0;i<no_element;i++){
            insert_node(arr[i]);
        }
    }
    void insert_node(int num){
        int count;
        node* newNode=new node(num);
        if(newNode==NULL){
            cout<<"Over Flow"<<endl;
            return;
        }
        if(start==NULL){
            start=newNode;
            return;
        }
        node* ptr=start;
        while(ptr->leftSide!=NULL and ptr->rightSide!=NULL){
            newNode->parent=ptr;
            if(newNode->info<ptr->info){
                ptr=ptr->leftSide;
            }else{
                ptr=ptr->rightSide;
            }
        }
        if(newNode->info<ptr->info){
            ptr->leftSide=newNode;
        }else{
            ptr->rightSide=newNode;
        }
        newNode->parent=ptr;
        newNode->rightSide=NULL;
        newNode->leftSide=NULL;
    }
    void search(int num){
        node* ptr=start;
        while(ptr!=NULL){
            cout<<ptr->info<<" ";
            if(ptr->info < num){
                ptr=ptr->rightSide;
            }else if(ptr->info > num){
                ptr=ptr->leftSide;
            }else{
                return;
            }
        }
        cout<<"\nNumber "<<num<<" not found in the tree : "<<endl;
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
    tree t(a,no_nodes);
    cout<<"Enter the number to be searched in the list : "<<endl;
    cin>>search_key;
    t.search(search_key);
    // tree t;
    // t.insert_node(10);
    // t.insert_node(9);
    // t.insert_node(31);
    // t.insert_node(30);
    // t.insert_node(8);
    // t.insert_node(50);
    // t.search(1);
    return 0;
}
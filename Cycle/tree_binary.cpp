#include<iostream>
using namespace std;
class node{
public:
    int info;
    node* leftSide;
    node* rightSide;
    
    node(){
        leftSide=NULL;
        rightSide=NULL;
        info=0;
    }
    node(int num){
        leftSide=NULL;
        rightSide=NULL;
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
        node* save;
        int count;
        node* newNode=new node(num);
        if(newNode==NULL){
            cout<<"Over Flow"<<endl;
            return;
        }
        if(start==NULL){
            start=newNode;
            return;
        }else{

            node* ptr=start;
            while(ptr!=NULL){
                save=ptr;
                if(newNode->info<=ptr->info){
                    ptr=ptr->leftSide;
                    count=1;
                }else{
                    ptr=ptr->rightSide;
                    count=0;
                }
            }
            if(count==1){
                save->leftSide=newNode;
            }else{
                save->rightSide=newNode;
            }
        }
    }
    // void search(int num){
    //     node* ptr=start;
    //     while(ptr!=NULL){
    //         cout<<ptr->info<<" ";
    //         if(ptr->info < num){
    //             ptr=ptr->rightSide;
    //         }else if(ptr->info > num){
    //             ptr=ptr->leftSide;
    //         }else{
    //             return;
    //         }
    //     }
    //     cout<<"\nNumber "<<num<<" not found in the tree : "<<endl;
    // }
    void preorder(void){
        
    }
};
int main(){
    int insert_info,no_nodes,inserter;
    cout<<"Enter the number of nodes to be created : "<<endl;
    cin>>no_nodes;
    int a[no_nodes];
    cout<<"Enter the number to be inserted in the list : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>a[i];
    }
    tree t(a,no_nodes);
    cout<<"Enter the number to be inserted in the list : "<<endl;
    cin>>inserter;
    t.insert_node(inserter);
    return 0;
}
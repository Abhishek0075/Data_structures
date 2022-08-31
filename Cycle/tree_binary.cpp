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
    node* start=NULL;
public:
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

    void preorder(node* root){
        if (root == NULL){
            return;
        }
        cout<<root->info<<" ";
        preorder(root->leftSide);
        preorder(root->rightSide);
    }

    void printTraversals(void){
        cout<<"Preorder traversal :- \n";
        preorder(start);
        cout<<"\nInorder traversal :- \n";
        inorder(start);
        cout<<"\nPostorder traversal :- \n";
        postorder(start);
        
    }

    void postorder(node* root){
        if (root == NULL){
            return;
        }
        postorder(root->leftSide);
        postorder(root->rightSide);
        cout<<root->info<<" ";
    }

    void inorder(node* node){
        if (node == NULL){
            return;
        }
        inorder(node->leftSide);
        cout<<node->info<<" ";
        inorder(node->rightSide);
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
    // cout<<"Enter the number to be inserted in the list : "<<endl;
    // cin>>inserter;
    // t.insert_node(inserter);
    t.printTraversals();
    return 0;
}
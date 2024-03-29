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
    node* find(int item,node*& save){
        node* ptr=start;
        while(ptr!=NULL){
            if(ptr->info==item){
                return ptr;
            }else{
                save=ptr;
                if(ptr->info<item){
                    ptr=ptr->rightSide;
                }else{
                    ptr=ptr->leftSide;
                }
            }
        }
        return NULL;
    }

    void deletion(int item){
        node* save;
        node* temp;
        node* address_deletion=find(item,save);
        if(address_deletion==NULL){
            cout<<"Entered value is not a node in the tree";
            return;
        }
        if(address_deletion->leftSide==NULL and address_deletion->rightSide==NULL){
            if(save->leftSide==address_deletion){
                save->leftSide=NULL;
                delete address_deletion;
                return;
            }else{
                save->rightSide=NULL;
                delete address_deletion;
                return;
            }
        }else{
            if(address_deletion->leftSide==NULL){
                if(save->leftSide==address_deletion){
                    save->leftSide=address_deletion->rightSide;
                    delete address_deletion;
                }else{
                    save->rightSide=address_deletion->rightSide;
                    delete address_deletion;
                }
            }else if(address_deletion->rightSide==NULL){
                if(save->leftSide==address_deletion){
                    save->leftSide=address_deletion->leftSide;
                    delete address_deletion;
                    return;
                }else{
                    save->rightSide=address_deletion->leftSide;
                    delete address_deletion;
                    return;
                }
            }else{
                //For 2 children ones
                node* ptr=address_deletion;
                node* beforePtr;
                while(ptr!=NULL and ptr->leftSide!=NULL){
                    beforePtr=ptr;
                    ptr=ptr->leftSide;
                }
                if(ptr->leftSide==NULL and ptr->rightSide!=NULL){
                    address_deletion=ptr->rightSide;
                    temp=ptr->rightSide;
                    ptr->rightSide=NULL;
                    delete temp;
                    return;
                }else{
                    address_deletion->info=(beforePtr->rightSide)->info;
                    temp=beforePtr->rightSide;
                    beforePtr->rightSide=NULL;
                    delete temp;
                    return;
                }
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
    void inorder(node* node){
        if (node == NULL){
            return;
        }
        inorder(node->leftSide);
        cout<<node->info<<" ";
        inorder(node->rightSide);
    }
    void postorder(node* root){
        if (root == NULL){
            return;
        }
        postorder(root->leftSide);
        postorder(root->rightSide);
        cout<<root->info<<" ";
    }
    void printTraversals(void){
        cout<<"Preorder traversal :- \n";
        preorder(start);
        cout<<"\nInorder traversal :- \n";
        inorder(start);
        cout<<"\nPostorder traversal :- \n";
        postorder(start);
    }
};
int main(){
    int insert_info,no_nodes,inserter,d,selector=1;
    cout<<"Enter the number of nodes to be created : "<<endl;
    cin>>no_nodes;
    int a[no_nodes];
    cout<<"Enter the number to be inserted in the list : "<<endl;
    for(int i=0;i<no_nodes;i++){
        cin>>a[i];
    }
    tree t(a,no_nodes);
    while(selector>0 and selector<3){
        cout<<"\n-----OPTIONS-----";
        cout<<"\n1 to insert \n2 to delete\nOther keys to EXIT\n";
        cout<<"Enter your input : ";
        cin>>selector;
        if(selector==1){
            cout<<"Enter the number to be inserted in the list : "<<endl;
            cin>>inserter;
            t.insert_node(inserter);
            cout<<"After insertion : "<<endl;
            t.printTraversals();
        }else if(selector==2){
            cout<<"\nEnter the number to be deleted from the tree : ";
            cin>>d;
            t.deletion(d);
            cout<<"After deletion : "<<endl;
            t.printTraversals();
        }
    }
    return 0;
}
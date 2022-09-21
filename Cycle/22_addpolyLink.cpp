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
        for(int i=0;i<=no_element;i++){
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
        while(ptr1!=NULL){
            new_list->create_node(ptr1->info);
            ptr1=ptr1->link;
        }
        while(ptr2!=NULL){
            new_list->create_node(ptr2->info);
            ptr2=ptr2->link;
        }
        cout<<"The sum of polnomials : ";
        new_list->print_poly();
    }
    void print_poly(void){
        node* ptr=start;
        int i=0;
        while(ptr!=NULL){
            cout<<" ("<<ptr->info<<")";
            if(ptr->link==NULL){
                cout<<"x^"<<i<<endl;
            }else{
                cout<<"x^"<<i<<" +";
            }
            i+=1;
            ptr=ptr->link;
        }
    }
};
int main(void){
    int no_element1;
    cout<<"==========First polynomial=========="<<endl;
    cout<<"Enter order of the first polynomial : ";
    cin>>no_element1;
    int poly1[no_element1];
    cout<<"Order = "<<no_element1<<endl;
    for (int i=0;i<=no_element1;i++){
        cout<<"Enter the co-efficent of x^"<<i<<" : ";
        cin>>poly1[i];
    }
    int no_element2;
    cout<<"==========Second polynomial=========="<<endl;
    
    cout<<"Enter order of the second polynomial : ";
    cin>>no_element2;
    int poly2[no_element2];
    cout<<"Order = "<<no_element2<<endl;
    for (int i=0;i<=no_element2;i++){
        cout<<"Enter the co-efficent of x^"<<i<<" : ";
        cin>>poly2[i];
    }
    linked_list list1(poly1,no_element1);
    linked_list list2(poly2,no_element2);
    list1.add_poly(list2);
    return 0;
}
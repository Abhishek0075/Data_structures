#include<iostream>
using namespace std;
class node{
    int item;
public:
    node(){
        item=10;
    }
    node(const node& n1)
    {
        item = n1.item;
    }
    node(int num){
        item=num;
    }

    void print(){
        cout<<"number : "<<item;
    }
};
void test(node& place,int i){
    node* dup=new node(i);
    place=*dup;
}
int main(){
    node n=node();
    n.print();
    test(n,88);
    cout<<endl;
    n.print();
    return 0;
}
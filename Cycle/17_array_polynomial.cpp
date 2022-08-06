#include<iostream>
using namespace std;
void add_polynomial(int arr1[],int order1,int arr2[],int order2){
    for(int i=0;i<order1;i++){
        if(i==order2){
            break;
        }
        arr1[i]=arr1[i]+arr2[i];
    }
    for(int i=order1-1;i>=0;i--){
        cout<<"("<<arr1[i]<<")";
        if(i==0){
            cout<<"x^"<<i<<endl;
        }else{
            cout<<"x^"<<i<<"+";
        }
        
        
    }
}
int main(){
    int no_element1=4;
    cout<<"==========First polynomial=========="<<endl;
    cout<<"Order = "<<no_element1<<endl;
    cout<<"Enter order of the first polynomial : ";
    cin>>no_element1;
    int poly1[no_element1];
    for (int i=0;i<no_element1;i++){
        cout<<"Enter the co-efficent of x^"<<i<<" : ";
        cin>>poly1[i];
    }
    int no_element2=2;
    cout<<"==========Second polynomial=========="<<endl;
    cout<<"Order = "<<no_element2<<endl;
    cout<<"Enter order of the second polynomial : ";
    cin>>no_element2;
    int poly2[no_element2];
    for (int i=0;i<no_element2;i++){
        cout<<"Enter the co-efficent of x^"<<i<<" : ";
        cin>>poly2[i];
    }
    if(no_element1>no_element2){
        add_polynomial(poly1,no_element1,poly2,no_element2);
    }else{
        add_polynomial(poly2,no_element2,poly1,no_element1);
    }
    return 0;
}
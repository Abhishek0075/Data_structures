#include<iostream>
using namespace std;
int  main(){
    int b[3]={10,11,12};
    int *a=b;
    a[1]=111;
    for(int i=0;i<3;i++){
        cout<<a[i]<<" ";    
    } 
    cout<<endl;
    for(int i=0;i<3;i++){
        cout<<b[i]<<" ";    
    } 
    return 0;
}
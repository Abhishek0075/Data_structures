#include<iostream>
using namespace std;
int  main(){
    int a[5]={10,6,7,8,9};
    int *b=a;
    for(int i=0;i<5;i++){
        cout<<(b[i]);
    }
    return 0;
}
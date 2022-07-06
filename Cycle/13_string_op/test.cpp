#include<iostream>
using namespace std;
void hai(int arr[]){
    arr[3]=100;
}
int main(){
    int a[5]={12,2,4,5,6};
    hai(a);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
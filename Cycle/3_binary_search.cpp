#include<iostream>
using namespace std;
int binary_search(int arr[],int low_bound,int up_bound,int item){
    int beg=low_bound,end=up_bound;
    int mid=(beg+end)/2;
    int loc;
    int i=0;
    while(arr[mid]!=item and beg<end){
        if(item>arr[mid]){
            beg=mid+1;
        }else{
            end=mid-1;
        }
        mid=(beg+end)/2;
    }
    if(arr[mid]==item){
        loc=mid+1;
    }else{
        loc=-1;
    }
    return loc;
}
int main(){
    int key,element;
    cout<<"Enter number of elements in the array : ";
    cin>>element;
    int array[element];
    cout<<"Enter the elements of the array :- \n";
    for(int i=0;i<element;i++){
        cin>>array[i];
    }
    cout<<"Array : "<<endl;
    for(int i=0;i<element;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the number to be searched : ";
    cin>>key;
    if(binary_search(array,2,element,key)==-1){
        cout<<"The element "<<key<<" is not present in the array \n";
    }else{
        cout<<"The position of the searched element "<<key<<" : "<<binary_search(array,0,12,key);
    }
    return 0; 
} 
#include<iostream>
using namespace std;
int ternary_search(int arr[],int no_element,int key){
    int beg=0,end=no_element-1;
    int mid1,mid2;

    while (beg<=end){
        mid1=((end-beg)/3)+beg;
        mid2=2*((end-beg)/3)+beg;
    
        if(key==arr[mid1]){
            return mid1;
        }
        else if(key==arr[mid2]){
            return mid2;
        }
        else if(key<arr[mid1]){
            end=mid1-1;
        }
        else if(key>arr[mid2]){
            beg=mid2+1;
        }
        else if (key<arr[mid2] and key>arr[mid1]){
            beg=mid1+1;
            end=mid2-1;
        } 
    }
    return -1;    
}
int main(){
    int element_no,search_num,ternary;
    cout<<"Enter the number of elements in the array : ";
    cin>>element_no;
    int arr[element_no];
    cout<<"Enter the elements of the array \n";
    for(int i=0;i<element_no;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number to be searched in the array : ";
    cin>>search_num;

    ternary=ternary_search(arr,element_no,search_num);
    if(ternary!=-1){
        cout<<search_num<<" is at " <<ternary+1<< "th position"  <<endl;
    }else{
        cout<<search_num<<" is not a part of the array\n";
    }
    
    return 0;
}
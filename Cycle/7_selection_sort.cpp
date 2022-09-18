#include<iostream>
using namespace std;
void selection_sort(int arr[],int no_element){
    int temp;
    for(int i=0;i<no_element-1;i++){
        for(int j=i+1;j<no_element;j++){
            if (arr[i]>arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    cout<<"After sorting : ";
    for(int i=0;i<no_element;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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
    cout<<"Before sorting : ";
    for(int i=0;i<element_no;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selection_sort(arr,element_no);
    return 0; 
}
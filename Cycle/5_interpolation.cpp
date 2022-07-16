#include<iostream>
using namespace std;
void interpolation_search(int data[],int n,int item){
    int beg=0;
    int end=n-1;
    int pos;
    while (beg<=end and item>=data[beg] and item<=data[end]){
        pos=beg+((item-data[beg])/(data[end]-data[beg]))*(end-beg);
        if(item==data[pos]){
            cout<<"The location of "<<item<<" : " <<pos+1<<endl;
            return;
        }else if(item>data[pos]){
            beg=pos+1;      
        }else{
            end=pos-1;
        }
    }
    cout<<"!!! Element "<<item<<" not found !!!"<<endl;
}
int main(){
    int element_no,search_num;
    cout<<"Enter the number of elements in the array : ";
    cin>>element_no;
    int arr[element_no];
    cout<<"Enter the elements of the array \n";
    for(int i=0;i<element_no;i++){
        cin>>arr[i];
    }
    cout<<"Enter the number to be searched in the array : ";
    cin>>search_num;
    interpolation_search(arr,element_no,search_num);
    return 0;
}

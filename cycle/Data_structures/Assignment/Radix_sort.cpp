#include<iostream>
using namespace std;
void radix_sort(int arr[],int no_element){
    int temp1,temp2,reminder1,reminder2,divider=1,exchanger,count=0,max=1,place=0;
    for(int i=0;i<no_element;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    while(max>0){
        max=max/10;
        place+=1;
    }
    while(count<place){
        for(int i=0;i<no_element-1;i++){
            for(int j=i+1;j<no_element;j++){
                temp1=arr[i];
                temp2=arr[j];
                for(int i=1;i<=count;i++){
                    temp1=temp1/10;         
                    temp2=temp2/10;
                }
                reminder1=temp1%10;         
                reminder2=temp2%10;
                if(reminder1>reminder2){
                    exchanger=arr[i];
                    arr[i]=arr[j];
                    arr[j]=exchanger;
                }
            }
        }
        count+=1;
        for(int i=0;i<no_element;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    
}
int main(){
    int arr[8]={1,10,34,56,78,56,122,34};
    radix_sort(arr,8);
    return 0;
}
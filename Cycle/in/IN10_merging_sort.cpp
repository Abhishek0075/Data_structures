#include<iostream>
using namespace std;

void merge(int arr1[],int element1,int lb1,int arr2[],int element2,int lb2,int final[],int lbFINAL){
    int upper1=lb1+element1,upper2=lb2+element2;
    while(lb1<upper1 and lb2<upper2){
        if (arr1[lb1]<arr2[lb2]){
            final[lbFINAL]=arr1[lb1];
            lb1+=1;
            lbFINAL+=1;
        }else{
            final[lbFINAL]=arr2[lb2];
            lb2+=1;
            lbFINAL+=1;
        }
    }
    if(lb1>=upper1){
        for(int i=0;i<upper2-lb2;i++){
            final[lbFINAL+i]=arr2[lb2+i];
            lbFINAL+=1;
        }
    }else{
        for(int i=0;i<upper1-lb1;i++){
            final[lbFINAL+i]=arr1[lb1+i];
            lbFINAL+=1;
        }
    }
    cout<<endl;
    for(int j=0;j<10;j++){
        cout<<final[j]<<" ";
    }
    cout<<endl;
}
void merge_pass(int arr1[],int arr1_element,int g_limit,int arr2[]){
    int no_group=arr1_element/(2*g_limit);
    int elements_grouped=2*g_limit*no_group;
    int reminder=arr1_element-elements_grouped;
    int lower_bound;
    for(int j=0;j<no_group;j++){
        lower_bound=2*g_limit*j;
        merge(arr1,g_limit,lower_bound,arr1,g_limit,g_limit+lower_bound,arr2,lower_bound);
    }

    //Mistakes in here
    if(reminder<g_limit){
        for(int i=1;i<reminder;i++){
            arr2[elements_grouped+i]=arr1[i];
        }
    }else{
        elements_grouped+=1;
        merge(arr1,g_limit,elements_grouped+1,arr1,reminder-g_limit,g_limit+elements_grouped+1,arr2,elements_grouped+1);
    }
}
void merge_sort(int arr[],int no_element){
    int g_limit=1;
    int *new_arr=new int [no_element];
    while(g_limit<no_element){
        merge_pass(arr,no_element,g_limit,new_arr);
        merge_pass(new_arr,no_element,2*g_limit,arr);
        g_limit=4*g_limit;
    }
    for(int i=0;i<no_element;i++){
        cout<<new_arr[i]<<" ";
    }
}
int main(){
    int arr[7]={34,12,15,100,89,76,9};
    // int elements;
    // cout<<"Enter the number of elements in the array : ";
    // cin>>elements;
    // int arr[elements];
    // cout<<"Enter the elements in the array : \n";
    // for(int i=0;i<elements;i++){
    //     cin>>arr[i];
    // }
    cout<<"The array : ";
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    merge_sort(arr,7);
    return 0;
}
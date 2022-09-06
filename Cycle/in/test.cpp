#include<iostream>
using namespace std;

void merge(int *arr1,int element1,int lb1,int *arr2,int element2,int lb2,int *final,int lbFINAL){
    int upper1=lb1+element1,upper2=lb2+element2;
    while(lb1<upper1 and lb2<upper2){
        cout<<"arr1["<<lb1<<"] = "<<arr1[lb1]<<endl;
        cout<<"arr2["<<lb2<<"] = "<<arr2[lb2]<<endl<<endl;
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
        }
    }else{
        for(int i=0;i<upper1-lb1;i++){
            final[lbFINAL+i]=arr1[lb1+i];
        }
    }
}
void merge_pass(int arr1[],int arr1_element,int g_limit,int arr2[]){
    int no_group=arr1_element/(2*g_limit);
    int elements_grouped=2*g_limit*no_group;
    int reminder=arr1_element-elements_grouped;
    int lower_bound;
    for(int j=0;j<no_group;j++){
        lower_bound=2*g_limit*(j-1);
        merge(arr1,g_limit,lower_bound,arr1,g_limit,g_limit+lower_bound,arr2,lower_bound);
    }
    if(reminder<g_limit){
        for(int i=1;i<reminder;i++){
            arr2[elements_grouped+i]=arr1[i];
        }
    }else{
        merge(arr1,g_limit,elements_grouped+1,arr1,reminder-g_limit,g_limit+elements_grouped+1,arr2,elements_grouped+1);
    }
}


int main(){
    int arr1[6]={23,1,4,54,10,32};
    int arr2[5]={32,11,67,100,6};
    int arr[11];
    merge(arr1,6,0,arr2,5,0,arr,0);
    cout<<"Array after merge : ";
    for(int i=0;i<11;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
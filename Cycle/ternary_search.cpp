#include<iostream>
using namespace std;
int ternary_search(int arr[],int no_element,int key){
    int beg=0,end=no_element-1;
    int mid1,mid2,temp;
    cout<<"no elements :  "<<no_element<<"======================="<<endl;

    while (beg<=end){
        mid1=((end-beg)/3)+beg;
        mid2=2*mid1;
        cout<<"mid1 : "<<mid1<<"\nmid2 : "<<mid2<<endl;
        
        cout<<"arr["<<mid1<<"] : "<<arr[mid1]<<"\narr["<<mid2<<"] : "<<arr[mid2]<<endl;

        //If the mid2 exceeds more the number of elements
        temp=mid2;
        if(mid2>no_element){
            temp=no_element-1;
        }
        
        cout<<"temp : "<<temp<<endl;
        cout<<"arr["<<temp<<"] : "<<arr[temp]<<endl;
        if(key==arr[mid1]){
            return mid1;
        }
         else if(key==arr[temp]){
            return mid2;
        }
         else if(key<arr[mid1]){
            end=mid1-1;
        }
         else if(key>arr[temp]){
            beg=mid2+1;
        }
         else if (key<arr[temp] and key>arr[mid1]){
            beg=mid1+1;
            end=mid2-1;
        } 
        
        cout<<"beg : "<<beg<<"\nend : "<<end<<endl<<endl;      
    }
    return -1;    
}
int main(){
    int key,ternary;
    int array[12]={11,22,30,33,40,44,55,60,66,80,87,99};
    cout<<"Array : "<<endl;
    for(int i=0;i<12;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter the number to be searched : ";
    cin>>key;
    ternary=ternary_search(array,12,key);
    if(ternary!=-1){
        cout<<key<<" is at " <<ternary+1<< "th position"  <<endl;
    }else{
        cout<<key<<" is not a part of the array\n";
    }
    
    return 0;
}
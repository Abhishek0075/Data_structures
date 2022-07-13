#include<iostream>
using namespace std;
int fibonacci_search(int data[],int n,int item){
    int fb1=0,fb2=1;
    int fb,offset,i,loc;
    n=n-1;
    fb=fb1+fb2;
    offset=-1;
    while(fb<n){
        fb1=fb2;
        fb2=fb;
        fb=fb2+fb1;
    }
    while(fb>1){
        i=offset+fb1;
        if(data[i]<item){
            fb=fb2;
            fb2=fb1;
            fb1=fb-fb2;
            offset=i;
        }else if(data[i]>item){
            fb=fb1;
            fb2=fb2-fb1;
            fb1=fb-fb2;
        }else{
            loc=i;
            return loc;
        }
    }
    if(fb2=1 and data[offset+1]==item){
        loc=offset+1;
        return loc;
    }
    return -1;
    
}
int main(){
    int arr[11]={10,22,35,40,45,50,80,82,90,100,235};
    int num;
    cout<<"Enter the number to be searched : ";
    cin>>num;
    if(fibonacci_search(arr,11,num)!=-1){
        cout<<"The position of entered number is : ";
        cout<<fibonacci_search(arr,11,num)+1<<endl;
    }else{
        cout<<"!! The entered number is not resent in the array !!"<<endl;
    }
    
    return 0;
}
#include<iostream>
using namespace std;
void fibonacci_search(int data[],int n,int item){
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
            break;
        }
        if(fb2=1 and data[offset+1]==item){
        loc=offset+1;
        break;
        }
    }
    cout<<"The location of "<<item<<" : " <<loc+1<<endl;
}
int main(){
    int arr[11]={10,22,35,40,45,50,80,82,90,100,235};
    int num;
    cout<<"Enter the number to be searched : ";
    cin>>num;
    fibonacci_search(arr,11,num);
    return 0;
}
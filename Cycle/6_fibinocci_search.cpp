#include<iostream>
using namespace std;
void fibonacci_search(int data[],int n,int item){
    int fb1=0,fb2=1;
    int fb,offset,i;
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
            cout<<"Element found at "<<i+1<<endl;
            return;
        }
    }
    if(fb2=1 and data[offset+1]==item){
        cout<<"Element found at "<<offset+1<<endl;
        return;
    }
    cout<<"Element not found\n";
    return;
    
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
    fibonacci_search(arr,element_no,search_num);
    return 0;
}

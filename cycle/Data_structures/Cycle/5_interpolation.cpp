#include<iostream>
using namespace std;
void interpolation_search(int data[],int n,int item){
    int beg=0;
    int end=n-1;
    int pos;
    int loc;
    while (beg<=end and item>=data[beg] and item<=data[end]){
        pos=beg+((item-data[beg])/(data[end]-data[beg]))*(end-beg);
        if(item==data[pos]){
            loc=pos;
            break;
        }else if(item>data[pos]){
            beg=pos+1;      
        }else{
            end=pos-1;
        }
        loc=-1;
    }
    cout<<"The location of "<<item<<" : " <<loc<<endl;
}
int main(){
    int num;
    int arr[18]={10,13,26,28,50,56,98,127,159,356,480,567,689,699,780,850,956,995};
    cout<<"Enter the number to be searched in the array : ";
    cin>>num;
    interpolation_search(arr,18,num);
    return 0;
}
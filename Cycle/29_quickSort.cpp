#include <iostream>
using namespace std;

int quick(int *data,int begin,int end){
    int pivot = data[begin];
    int lowerBound = begin;
    int upperBound = end;
    int temp;
    while(lowerBound<upperBound){
        while(data[lowerBound]<=pivot){
            lowerBound++;
        }
        while(data[upperBound]>pivot){
            upperBound--;
        }
        if(lowerBound<upperBound){
            temp = data[lowerBound];
            data[lowerBound]=data[upperBound];
            data[upperBound]=temp;
        }
    }
    temp = data[begin];
    data[begin] = data[upperBound];
    data[upperBound] = temp;
    return upperBound;
}

void quickSort(int *data,int begin,int end){
    int loc;
    if(begin<end){
        loc = quick(data,begin,end);
        quickSort(data,begin,loc-1);
        quickSort(data,loc+1,end);
    }
}



void printArray(int* data,int length){
	for (int i=0; i<length;i++) {
		cout<<data[i]<<" ";
	}
}

int main(){
    int length;
    cout<<"Enter the number of elements in the array : ";
    cin>>length;
	int arr[length];
    cout<<"Enter the elements of the array :-\n";
    for(int i=0;i<length;i++){
        cin>>arr[i];
    }
    cout<<"Array before quick sorting : ";
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Array after quick sorting : ";
    quickSort(arr,0,length-1);
    printArray(arr,length);
}
#include<iostream>
using namespace std;

void linear_search_iterative(int arr[],int no_element,int key){
	int position=-1;
	for(int i=0;i<=no_element;i++){
		if(arr[i]==key){
			position=i;
			break;
		}
	}
	if(position==-1){
		cout<<key<<" not in the array"<<endl;
	}else{
		cout<<key<<" found at "<<(position+1)<<"th postion"<<endl;
	}
}


int main(){
	int key,no_element;
	cout<<"Enter the number of elements in the array : ";
	cin>>no_element;
	int a[no_element];
	cout<<"Enter the elements of the array ";
	for(int i=0;i<no_element;i++){
		cin>>a[i];
	}
	cout<<"The array = ";
	for(int i=0;i<no_element;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter the key to be searched "<<endl;
	cin>>key;
	cout<<"Result : "<<endl;
	linear_search_iterative(a,key);
	return 0;
}


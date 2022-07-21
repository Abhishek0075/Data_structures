#include<iostream>
using namespace std;
void substring_extraction(char string[],int position,int sub_len){ 
    char sub_string[sub_len+1];
    int count=0;
    while(count<sub_len){
        sub_string[count]=string[position+count-1];
        count=count+1;
    }
    
    for(int i=0;i<count;i++){
        cout<<sub_string[i];
    }
}
int main(){
    int letters,positon,length;
    cout<<"Enter the number of letters in the main string : ";
    cin>>letters;
    char string[letters];
    cout<<"Input the string : ";
    cin>>string;
    cout<<"Enter the length of the substring to be extracted : ";
    cin>>length;
    cout<<"Enter the position from which substring to be extracted : ";
    cin>>positon;
    substring_extraction(string,positon,length);
    cout<<endl;
    return 0;
}
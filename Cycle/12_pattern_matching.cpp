#include<iostream>
using namespace std;
int pattern_matching(char text[],int text_no,char pattern[],int pat_no){
    int k=0,max=text_no-pat_no+1;
    int INDEX,l;
    while(k<=max){
        for(l=0;l<pat_no;l++){
            // cout<<"pattern["<<l<<"] = "<<pattern[l]<<endl;
            // cout<<"text["<<k+l<<"] = "<<text[k+l]<<endl<<endl;
            if(pattern[l]!=text[k+l]){
                break;
            }else{
                INDEX=k;
            }
        }
        if(l==pat_no){
            return INDEX+1;
        }
        k=k+1;
    }
    return -1;
}
int main(){
    int let,positon,patlet;
    cout<<"Enter the number of letters in the main string : ";
    cin>>let;
    char string[let];
    cout<<"Input the string : ";
    cin>>string;
    cout<<"Enter the length of the pattern to be matched : ";
    cin>>patlet;
    char pattern[patlet];
    cout<<"Input the pattern : ";
    cin>>pattern;
    cout<<endl<<pattern_matching(string,let,pattern,patlet);
    return 0;
}
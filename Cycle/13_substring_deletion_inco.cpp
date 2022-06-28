#include<iostream>
using namespace std;
int pattern_matching(char text[],int text_no,char pattern[],int pat_no){
    int k=0,max=text_no-pat_no+1;
    int INDEX,l;
    while(k<=max){
        for(l=0;l<pat_no;l++){
            cout<<"pattern["<<l<<"] = "<<pattern[l]<<endl;
            cout<<"text["<<k+l<<"] = "<<text[k+l]<<endl<<endl;
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
void sub_delete(char text[],int text_no,char pattern[],int pat_no){
    int index=pattern_matching(char text[],int text_no,char pattern[],int pat_no);
    int helper;
    if (index==-1){
        cout<<"There is no string like this in the main text "<<endl;
    }else{
        
    }

}
int main(){

    return 0;
}
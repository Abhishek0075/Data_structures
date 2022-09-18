#include<iostream>
#include<cstring>
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
void sub_delete(char text[],int text_no,char pattern[],int pat_no){
    int index=pattern_matching(text,text_no,pattern,pat_no);
    int final=text_no-pat_no;
    int times=1;
    int remaining=index+pat_no-1;
    int helper=text_no-(index+pat_no)+1;
    if (index==-1){
        cout<<"There is no string like this in the main text "<<endl;
    }else{
        while(times<=helper){
            // cout<<"text["<<remaining<<"] : "<<text[remaining]<<"--------->"<<"text["<<index-1<<"] : "<<text[index-1]<<endl;
            text[index-1]=text[remaining];
            index+=1;
            remaining+=1;
            times+=1;
        }
        cout<<"The text after deletion : ";
        for(int i=0;i<final;i++){
            cout<<text[i];
        }
    }
    cout<<endl;
}
void insert_substring(char text[],int text_no,char substring[],int sub_no,int position){
    int move_limiter=text_no+sub_no-1;
    int text_max=move_limiter;
    int count=0;
    int times=0;
    int spacer=text_no-position;
    while(times<spacer){
        text[text_max]=text[text_no-1];
        text_no-=1;
        text_max-=1;
        times+=1;
    }    
    while(count<sub_no){
        text[position]=substring[count];
        position=position+1;
        count=count+1;
    }
    for(int i=0;i<=move_limiter;i++){
        cout<<text[i];
    }
    cout<<endl;
}
void replacement(char text[],int text_no,char substring[],int sub_no,char replacer[],int replace_no){
    int index=pattern_matching(text,text_no,substring,sub_no)-1;
    sub_delete(text,text_no,substring,sub_no);
    cout<<"After replacement : ";
    insert_substring(text,(text_no-sub_no),replacer,replace_no,index);
    
}
int main(){
    int let,positon,patlet,replet;
    cout<<"Enter the number of letters in the main string : ";
    cin>>let;
    char string[let];
    cout<<"Input the string : ";
    cin>>string;
    cout<<endl;
    cout<<"Enter the length of the pattern to be replaced : ";
    cin>>patlet;
    char pattern[patlet];
    cout<<"Input the substring to be replaced : ";
    cin>>pattern;
    cout<<endl;
    cout<<" Enter the length of substring using which we replace : ";
    cin>>replet;
    char replcr[replet];
    cout<<" Enter the substring using which we replace : ";
    cin>>replcr;
    cout<<endl;
    replacement(string,let,pattern,patlet,replcr,replet);
    return 0;
}

#include<iostream>
using namespace std;
class matrix{
    int **p;
    int row,col,num_values;
public:
    matrix(){}
    void input_matrix(void){
        cout<<"Enter the elements of the "<<row<<"*"<<col<<" matrix with "<<num_values<<" values : "<<endl;
        for(int i=1;i<num_values+1;i++){
            cout<<"Enter the row column and value in order : \n";
            for(int j=0;j<3;j++){
                cin>>p[i][j];
            }
        }
    }
    void display_matrix(void){
        for(int i=0;i<num_values+1;i++){
            for(int j=0;j<3;j++){
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    matrix(int r,int c,int num){
        row=r,col=c,num_values=num;
        p=new int *[num_values+1];
        for(int i=0;i<num_values+1;i++){
            p[i]=new int[3];
        }
        p[0][0]=row;
        p[0][1]=col;
        p[0][2]=num_values;
    }
    void add_sparse(matrix mtx){
        if(p[0][0]!=mtx.p[0][0] or p[0][1]!=mtx.p[0][1]){
            return;
        }
        int temp1=p[0][2];
        int temp2=mtx.p[0][2];
        int i=0,j=0;
        while(i<temp1 and j<temp2){
            
        }        
    }
};
int main(){

    return 0;
}
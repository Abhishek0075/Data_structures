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
    void transpose(matrix mtx){
        mtx.p[0][0]=p[0][1];
        mtx.p[0][1]=p[0][0];
        mtx.p[0][2]=p[0][2];
        int k=1;
        for(int i=0;i<col-1;i++){
            for(int j=1;j<num_values+1;j++){
                if(i==p[j][1]){
                    mtx.p[k][0]=j;
                    mtx.p[k][1]=p[j][0];
                    mtx.p[k][2]=p[j][2];
                    k+=1;
                }
            }
        }
    }
};
int main(){
    matrix m1(3,4,6);
    m1.input_matrix();
    cout<<"The matrix inputed : \n";
    m1.display_matrix();
    return 0;
}
#include<iostream>
using namespace std;
class matrix{
    int **p;
    int row,col,num_values;
public:
    matrix(){}
    void input_matrix(void){
        cout<<"Enter the elements of the "<<row<<"*"<<col<<" matrix with "<<num_values<<" values : "<<endl;
        cout<<"Enter the row column and value in order : \n";
        for(int i=1;i<num_values+1;i++){
            
            for(int j=0;j<3;j++){
                cin>>p[i][j];
            }
        }
    }
    void display_matrix(void){
        for(int i=0;i<p[0][2]+1;i++){
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
        matrix sum(row,col,(num_values+mtx.num_values+1));
        if(p[0][0]!=mtx.p[0][0] or p[0][1]!=mtx.p[0][1]){
            return;
        }
        int temp1=p[0][2];
        int temp2=mtx.p[0][2];
        int i=1,j=1,k=1;
        while(i<=temp1 and j<=temp2){
            if(p[i][0]<mtx.p[j][0]){
                sum.p[k][0]=p[i][0];
                sum.p[k][1]=p[i][1];
                sum.p[k][2]=p[i][2];
                i+=1;
                k+=1;
            }else if(p[i][0]>mtx.p[j][0]){
                sum.p[k][0]=mtx.p[j][0];
                sum.p[k][1]=mtx.p[j][1];
                sum.p[k][2]=mtx.p[j][2];
                j+=1;
                k+=1;
            }else if(p[i][1]>mtx.p[j][1]){
                sum.p[k][0]=mtx.p[j][0];
                sum.p[k][1]=mtx.p[j][1];
                sum.p[k][2]=mtx.p[j][2];
                j+=1;
                k+=1;
            }else if(p[i][1]<mtx.p[j][1]){
                sum.p[k][0]=p[i][0];
                sum.p[k][1]=p[i][1];
                sum.p[k][2]=p[i][2];
                i+=1;
                k+=1;
            }else{
                sum.p[k][0]=p[i][0];
                sum.p[k][1]=p[i][1];
                sum.p[k][2]=mtx.p[j][2]+p[i][2];
                i+=1;
                j+=1;
                k+=1;
            }
        }
        while(i<=temp1){
            sum.p[k][0]=p[i][0];
            sum.p[k][1]=p[i][1];
            sum.p[k][2]=p[i][2];
            i+=1;
            k+=1;
        }
        while(j<=temp1){
            sum.p[k][0]=p[j][0];
            sum.p[k][1]=p[j][1];
            sum.p[k][2]=p[j][2];
            j+=1;
            k+=1;
        }
        sum.p[0][2]=k-1;
        sum.display_matrix();       
    }
    void transpose(void){
        matrix mtx(col,row,num_values);
        int k=1;
        for(int i=0;i<col;i++){
            for(int j=1;j<num_values+1;j++){
                if(i==p[j][1]){
                    mtx.p[k][0]=p[j][1];
                    mtx.p[k][1]=p[j][0];
                    mtx.p[k][2]=p[j][2];
                    k+=1;
                }
            }
        }
        mtx.display_matrix();
    }
};
int main(){
    int r1,c1,r2,c2,non1,non2;
    cout<<"Enter the row of the matrix 1 : ";
    cin>>r1;
    cout<<"Enter the column of the matrix 1 : ";
    cin>>c1;
    cout<<"Enter the number of non zero numbers in matrix 1 : ";
    cin>>non1;
    cout<<"Enter the row of the matrix 2 : ";
    cin>>r2;
    cout<<"Enter the column of the matrix 2 : ";
    cin>>c2;
    cout<<"Enter the number of non zero numbers in matrix 2 : ";
    cin>>non2;
    matrix m1(r1,c1,non1),m2(r2,c2,non2);
    cout<<"m1 : \n";
    m1.input_matrix();
    cout<<endl;
    cout<<"m2 : \n";
    m2.input_matrix();
    cout<<"Transpose : "<<endl;
    cout<<"m1 : \n";
    m1.transpose();
    cout<<"m2 : \n";
    m2.transpose();
    if(c1==c2 or r1==r2){
        cout<<"Sum : \n";
        m1.add_sparse(m2);
    }else{
        cout<<"!! The dimensions doesn't satisfy matrix addition !! ";
    }
    return 0;
}
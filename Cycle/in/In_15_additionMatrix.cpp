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
        int i=0;
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
        int valueNo=mtx.row+row;
        matrix sum(row,col,valueNo);
        if(p[0][0]!=mtx.p[0][0] or p[0][1]!=mtx.p[0][1]){
            return;
        }
        int temp1=p[0][2];
        int temp2=mtx.p[0][2];
        int i=1,j=1,k=1;
        while(i<=temp1 and j<=temp2){
            if(p[i][0] < mtx.p[j][0]){
                sum.p[k][0] = p[i][0];
                sum.p[k][1] = p[i][1];
                sum.p[k][2] = p[i][2];
                k=k+1;
                i=i+1;
            }else if(mtx.p[j][0] < p[i][0]){
                sum.p[k][0] = mtx.p[j][0];
                sum.p[k][1] = mtx.p[j][1];
                sum.p[k][2] = mtx.p[j][2];
                k=k+1;
                j=j+1;
            }
            else if(mtx.p[j][1] < p[i][1]){
                sum.p[k][0] = mtx.p[j][0];
                sum.p[k][1] = mtx.p[j][1];
                sum.p[k][2] = mtx.p[j][2];
                k = k+1;
                j = j+1;
            }
            else if(p[i][1] < mtx.p[j][1]){
                sum.p[k][0] = p[i][0];
                sum.p[k][1] = p[i][1];
                sum.p[k][2] = p[i][2];
                k=k+1;
                i=i+1;
            }
            else{
                sum.p[k][0] = p[i][0];
                sum.p[k][1] = p[i][1];
                sum.p[k][2] = p[i][2] + mtx.p[j][2];
                k=k+1;
                i=i+1;
                j=j+1;
            }
            cout<<sum.p[k-1][0]<<" " <<sum.p[k-1][1]<<" ";
            cout<<"sum part" <<sum.p[k-1][2]<<endl<<endl;
        }
        while(i<=temp1){
            sum.p[k][0]=p[i][0];
            sum.p[k][1]=p[i][1];
            sum.p[k][2]=p[i][2];
            i++;
            k++;
        }
        while(j<=temp1){
            sum.p[k][0]=mtx.p[j][0];
            sum.p[k][1]=mtx.p[j][1];
            sum.p[k][2]=mtx.p[j][2];
            j++;
            k++;
        }
        sum.p[0][2]=k-1;
        cout<<endl;
        sum.display_matrix();       
    }
};
int main(){
    matrix m1(2,3,4),m2(2,3,5);
    cout<<"m1 : \n";
    m1.input_matrix();
    cout<<endl;
    cout<<"m2 : \n";
    m2.input_matrix();
    cout<<"Sum : \n";
    cout<<endl;
    m1.display_matrix();
    cout<<endl;
    m2.display_matrix();
    cout<<endl;
    m1.add_sparse(m2);
    return 0;
}
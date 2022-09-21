#include<iostream>
using namespace std;
class matrix{
    int **p;
    int row,col,num_values;
public:
    matrix(){}
    void input_matrix(void){
        cout<<"Enter the elements of the "<<row<<"x"<<col<<" matrix with "<<num_values<<" values : "<<endl;
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
    int row,col,num;
    cout<<"Enter the number of rows in the matrix : ";
    cin>>row;
    cout<<"Enter the number of columns in the matrix : ";
    cin>>col;
    cout<<"Enter the number of non-zero elements in the matrix : ";
    cin>>num;
    
    matrix m1(row,col,num);
    m1.input_matrix();
    cout<<"The matrix inputed : \n";
    m1.display_matrix();
    cout<<"The matrix after transposing : \n";
    m1.transpose();
    return 0;
}
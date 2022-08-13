#include<iostream>
using namespace std;
class matrix{
    int **p;
    int row,column;
    public:
    matrix(){}
    matrix(int d1){
        row=d1;
        column=d1;
        p=new int*[d1];
        for(int i=0;i<d1;i++){
            p[i]=new int[d1];
        }
    }
    void show_matrix(void){
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void magic_odd(){
        for(int i=0;i<column;i++){
            for(int j=0;j<column;j++){
                p[i][j]=999;
            }
        }
        int count=column*row;
        int x_coord=column/2,y_coord=column-1;
        p[x_coord][y_coord]=1;
        for(int i=2;i<=count;i++){
            x_coord=x_coord-1;
            y_coord=y_coord+1;
            if(x_coord==-1 and y_coord==column){
                x_coord=0;
                y_coord=column-2;
            }else{
                if(x_coord==-1){
                    x_coord=column-1;
                }
                if(y_coord==column){
                    y_coord=0;
                }
            }
            if((p[x_coord][y_coord])!=999){
                x_coord=x_coord+1;
                y_coord=y_coord-2;
            }
            p[x_coord][y_coord]=i;
        }
    }
};
int main(){
    matrix a(5);
    a.magic_odd();
    a.show_matrix();
    return 0;
}
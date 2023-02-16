#include<iostream>
using namespace std;

class Matrix
{
    private:
    int **a;
    int r,c;
    public:
    Matrix(int x,int y)
    {
        cout<<"Array initialized by constructor."<<endl;
        r = x;
        c = y;
        if((r>0)&&(c>0))
        {
            a = new int *[r];
            for (int i=0; i<r; i++)
            {
                a[i]= new int [c];
            }
        }
    }
    ~Matrix()
    {
        for (int i=0; i<r; i++)
            delete [] a[i];
        delete [] a;
        cout<<"Memory Released"<<endl;
    }
    void sum(Matrix a, Matrix b);
    void accept_elements();
    void display();
};

void Matrix::sum(Matrix x, Matrix y)
{
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            a[i][j]=x.a[i][j]+y.a[i][j];
        }
    }
}

void Matrix::accept_elements()
{
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cin>>a[i][j];
        }
    }
}
void Matrix::display()
{
    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl<<" ";
    }
}
int main()
{
    int r1,c1,r2,c2;
    cout<<"Enter the number of rows and columns of the first matrix : "<<endl;
    cin>>r1>>c1;
    Matrix ob1(r1,c1);
    cout<<"Enter the values of the first matrix: "<<endl;
    ob1.accept_elements();
    cout<<"Enter the number of rows and colums of the second matrix : "<<endl;
    cin>>r2>>c2;
    Matrix ob2(r2,c2);
    cout<<"Enter the values of the second matrix: "<<endl;
    ob2.accept_elements();
    Matrix ob3(r2,c2);
    if (r1 != r2 || c1 != c2)
    {
        cout<<"Matrices must have the same number of rows and columns."<<endl;
    }
    else
    {
        ob3.sum(ob1, ob2);
        cout<<"The sum of the two matrices is: "<<endl;
        ob3.display();
    }
    return 0;
}

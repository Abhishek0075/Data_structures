#include<iostream>
using namespace std;

void MERGE(int A[] , int Num_A , int LBA ,int B[] , int Num_B ,
                int LBB ,int *C , int LBC){
  int temp_A = LBA;
  int temp_B = LBB;
  int PTR = LBC;
  int UBA = LBA + Num_A - 1;
  int UBB = LBB + Num_B - 1;
  while (temp_A <= UBA && temp_B <= UBB){
    if( A[temp_A] < B[temp_B]){
      C[PTR] = A[temp_A];
      temp_A =temp_A + 1;
      PTR = PTR+1;
    }
    else{
      C[PTR] = B[temp_B];
      temp_B = temp_B + 1;
      PTR = PTR +1;

    }
  }
  if (temp_A > UBA){
    for (int i =0;i <= UBB - temp_B;i++){
        C[PTR + i ] = B[temp_B + i];
    }
  }else{
    for(int i=0 ;i <= UBA - temp_A; i++){
      C[PTR + i ] = A[temp_A + i];
    }
  }
}
void MERGEPASS( int *A , int Num_A , int Num_SubA , int *B){
  int Q = Num_A/(2*Num_SubA);
  int S = 2*Num_SubA*Q;
  int R = Num_A - S;
  int LB;
  for( int i=1;i<=Q;i++){
    LB = (2*i-2)*Num_SubA;
    MERGE(A , Num_SubA , LB , A , Num_SubA , LB+Num_SubA , B , LB);
  }
  if( R <= Num_SubA){
    for(int j =0 ; j< R ; j++){
           B[S+j] = A[S+j];
     }
   }
  else{
    MERGE(A, Num_SubA , S ,A, R-Num_SubA, Num_SubA + S, B ,S);
  }
}

void MERGESORT(int *A, int *B , int NumA){
  int L=1;
  while (L < NumA){
    MERGEPASS( A , NumA , L , B);
    MERGEPASS(B , NumA , (2*L) , A);
    L = 4*L;
  }
}
int main(){
    int element;
    cout<<"\nEnter the number of element : ";
    cin>>element;
    int list1[element];
    int list2[element];
    cout<<"Enter the elements : ";
    for(int i = 0;i<element;i++){
        cin>>list1[i];
    }
    cout<<"Before sorting : ";
    for(int i=0;i<element;i++){
        cout<<list1[i]<<" ";
    }
    cout<<endl;
    MERGESORT( list1 , list2 , element);

    cout<<"After sorting : ";
        for (int i = 0;i<element ; i++){
            cout<<list1[i]<<" ";
        }
        cout<<endl;

    return 0;
} 
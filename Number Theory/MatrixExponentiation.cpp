#include<bits/stdc++.h>
using namespace std;


void multiply(int A[2][2],int B[2][2]){
       int fvalue = A[0][0]*B[0][0]+A[0][1]*B[1][0];
       int svalue = A[0][0]*B[0][1]+A[0][1]*B[1][1];
       int tvalue = A[1][0]*B[0][0]+A[1][1]*B[1][0];
       int fovalue = A[1][0]*B[0][1]+A[1][1]*B[1][1];

       A[0][0] = fvalue;
       A[0][1] = svalue;
       A[1][0] = tvalue;
       A[1][1] = fovalue;
}

void power(int A[2][2],int n){
    if(n==0 || n==1)
      return;

     power(A,n/2);
  
     multiply(A,A);

     if(n%2!=0){
         int M[2][2] = {{1,1},{1,0}};
         multiply(A,M);
     } 
        
        
}

int fibbo(int n){
    int A[2][2] = {{1,1},{1,0}};
    if(n==0)
      return 0;
    if(n==1)
      return 1;

    power(A,n-1);

    return A[0][0];    

}

int main(){

int n;
cin>>n;

//Fibonachi number at nth position
cout<<fibbo(n)<<endl;

return 0;
}




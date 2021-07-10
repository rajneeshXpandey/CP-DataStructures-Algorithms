#include<bits/stdc++.h>
using namespace std;

void eulerPhi(int n){
    int arr[n+1];
  for(int i=1;i<=n;i++){
      arr[i]=i;
  }

  for(int i = 2;i<=n;i++){
      if(arr[i]==i){
          arr[i] = i-1;
          for(int j=2*i;j<=n;j+=i){
              arr[j] = (arr[j]*(i-1))/i; 
          }
      }
  }
for(int i=1;i<=n;i++)
    cout<<"Euler Totient for "<<i<<" is: "<<arr[i]<<endl;
}

int main(){

int n;
cin>>n;
  eulerPhi(n);
return 0;
}




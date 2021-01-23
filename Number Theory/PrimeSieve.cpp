#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

void PrimeSieve(int n){

     bool array[n+1];
     for(int i=0;i<=n;i++)
         {
             array[i]=true;
         }
     array[0]=false;
     array[1]=false;

      for(int i=2;i*i<=n;i++)
      {   
           if(array[i]==true){
            for(int j=i*i;j<=n;j+=i){
                  array[j]=false;
              }  
            }
      }
       for(int i=0;i<=n;i++)
         {
             if(array[i]==true)
                 cout<<i<<endl;
         }   
}

int main(){
//Reading and writing input.txt and output.txt   
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
//start code here
int n;
cin>>n;

PrimeSieve(n);

return 0;
}




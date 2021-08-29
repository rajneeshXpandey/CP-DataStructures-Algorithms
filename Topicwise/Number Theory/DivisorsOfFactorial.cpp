#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

#define MAX 500001

int count(int n,int r)
{
    int count = 0;
    while((n/r) > 0){
        count += n/r;
        r *= r; 
    }
       return count;
}
void NumOfDivisor(int n){

 bool array[MAX];
     for(int i=0;i<=MAX;i++)
         {
             array[i]=true;
         }
     array[0]=false;
     array[1]=false;

      for(int i=2;i*i<=MAX;i++)
      {   
           if(array[i]==true){
            for(int j=i*i;j<=MAX;j+=i){
                  array[j]=false;
              }  
            }
      }
  int answer = 1;
       for(int i=0;i<=n;i++)
         {
             if(array[i]==true)
                 {
                     int c = count(n,i);
                     answer *= (c+1);

                 }
         } 

      cout<<answer<<endl;   

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

NumOfDivisor(n);

return 0;
}

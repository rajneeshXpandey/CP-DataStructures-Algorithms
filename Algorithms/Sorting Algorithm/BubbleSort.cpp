#include<bits/stdc++.h>

using namespace std;

void BubbleSort(int a[],int n){
  for(int i=0;i<n-1;i++){
      //In every ith iteration last ith element 
      //get sorted.
      for(int j=0;j<n-1-i;j++){
          if(a[j]>a[j+1])
           swap(a[j],a[j+1]);
      }
  }

}


int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

int n;
cin>>n;
int array[n];

for(int i=0;i<n;i++)
    cin>>array[i];

BubbleSort(array,n);

for(int i=0;i<n;i++)
    cout<<array[i]<<" ";


return 0;

}




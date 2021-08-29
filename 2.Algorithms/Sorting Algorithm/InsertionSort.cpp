#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int a[], int n){
    for(int i=1;i<n;i++)
     {     int key=a[i];
           int j = i-1;
           while(a[j] > key && j>=0){
               a[j+1]=a[j];
               j--;
           }             
           a[j+1]=key;
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
int array[n];

for(int i=0;i<n;i++)
    cin>>array[i];
InsertionSort(array,n);
for(int i=0;i<n;i++)
    cout<<array[i]<<" ";
return 0;
}




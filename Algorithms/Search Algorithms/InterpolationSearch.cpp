#include<bits/stdc++.h>
using namespace std;

int InterpolationSearch(int arr[],int n,int k){
    int start =0;
    int end=n-1;
    while(start<=end){
        int pos = start + ((k-arr[start])*((end-start)/(arr[end]-arr[start])));
       if(arr[pos]==k)
          return pos;
        else if(k<arr[pos])
        end = pos-1;
        else if(k>arr[pos])
          start = pos+1;
    }
    return -1;
}

int main(){

int n;
cin>>n;
int array[n];

for(int i=0;i<n;i++)
    cin>>array[i];
int key;
cin>>key;
cout<<InterpolationSearch(array,n,key)<<endl;

return 0;
}




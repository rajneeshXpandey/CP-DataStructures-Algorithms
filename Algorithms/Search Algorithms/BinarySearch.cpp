#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n,int k){
   int start = 0,last = n-1;
   
    while(start<=last){
        int mid = (start+last)/2;
        if(k<arr[mid])
                last = mid-1;
        else if(k>arr[mid])
             start = mid+1;
         else
         {
            return mid;
         }
             
    }
    return -1;


}

int main(){

int n;
cin>>n;
int array[n];
//array must be in sorted order
for(int i=0;i<n;i++)
    cin>>array[i];

int key;
cin>>key;

cout<<binarySearch(array,n,key);

return 0;
}




#include<bits/stdc++.h>
using namespace std;


int partition(int arr[],int s,int l){

    int pivot = arr[l];
    int pIndex = s;
    for(int i=s;i<l;i++){
        if(arr[i]<pivot)
          {
              swap(arr[pIndex],arr[i]);
              pIndex++;
          }  
    }
    swap(arr[pIndex],arr[l]);

    return pIndex;

}




void QuickSort(int arr[],int s,int l){
      if(s<l){
           int pindex = partition(arr,s,l);

           QuickSort(arr,s,pindex-1);
           QuickSort(arr,pindex+1,l);
      }
      else return ;
}


int main(){

int n;
cin>>n;
int array[n];

for(int i=0;i<n;i++)
    cin>>array[i];

int start = 0;
int end = n-1;

QuickSort(array,start,end);

for(int i=0;i<n;i++)
    cout<<array[i]<<" ";

return 0;
}




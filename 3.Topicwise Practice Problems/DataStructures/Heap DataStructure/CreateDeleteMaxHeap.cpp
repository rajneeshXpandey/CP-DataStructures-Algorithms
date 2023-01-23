#include<bits/stdc++.h>
using namespace std;

void Heapify(int a[],int index,int size);

void BuildHeap(int a[],int size){
    for(int i=size/2;i>=0;i--)
         Heapify(a,i,size);
}

void Heapify(int a[],int index,int size){
    
    int left = (2*index) + 1;
    int right = left + 1;

    int max = index;

    if(left<=size && a[max]<a[left])
       max = left;
    if(right<=size && a[max]<a[right])
       max = right;

    if(index != max)
    {
        swap(a[max],a[index]);
        Heapify(a,max,size);
    }   
}

void DeleteMax(int a[],int size){
    int max = 0;
    swap(a[max],a[size]);
    cout<<"Max element is: "<<a[size]<<endl;
    size--;
    Heapify(a,max,size);
}

int main(){

int n;
cin>>n;
int array[n];

for(int i=0;i<n;i++)
    cin>>array[i];

BuildHeap(array,n-1);

for(int i=0;i<n;i++)
    cout<<array[i]<<" ";
cout<<endl;

 DeleteMax(array,n-1);

 for(int i=0;i<n-1;i++)
    cout<<array[i]<<" "; 
cout<<endl;

return 0;

}




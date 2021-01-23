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

    int min = index;

    if(left<=size && a[min]>a[left])
       min = left;
    if(right<=size && a[min]>a[right])
       min = right;

    if(index != min)
    {
        swap(a[min],a[index]);
        Heapify(a,min,size);
    }   
}

void DeleteMin(int a[],int size){
    int min = 0;
    swap(a[min],a[size]);
    cout<<"Min element is: "<<a[size]<<endl;
    size--;
    Heapify(a,min,size);
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

 DeleteMin(array,n-1);

 for(int i=0;i<n-1;i++)
    cout<<array[i]<<" "; 
cout<<endl;

return 0;

}




#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
// in ith sort first ith elements are already sorted
void SelectionSort(int a[],int n){
        for(int i=0;i<n;i++){
         int min_idn = i;
        for(int j=i+1;j<n;j++){
             if(a[min_idn] > a[j])
              min_idn = j;
              }
//Here we can't swap min with a[i]
//we need to modify array not min
        swap(a[min_idn],a[i]);
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
SelectionSort(array,n);
for(int i=0;i<n;i++)
    cout<<array[i]<<" ";
return 0;
}




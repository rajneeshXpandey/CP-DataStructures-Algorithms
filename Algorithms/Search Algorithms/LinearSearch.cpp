#include<bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[],int n,int k){
        for(int i=0;i<n;i++)
        {
            if(arr[i] == k)
                return i;
                
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

int indexFound = LinearSearch(array,n,key);

cout<<indexFound;

return 0;
}




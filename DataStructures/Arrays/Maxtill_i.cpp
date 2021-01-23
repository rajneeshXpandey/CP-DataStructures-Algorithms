#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)

int maxtillI(int a[],int n)
{
   int max = a[0];
   for (size_t i = 1; i < n; i++)
   {
       if(a[i]>max)
         max = a[i];
   }
   return max;
}

int main(){

int n;
cin>>n;
int array[n];

for(int i=0;i<n;i++)
    cin>>array[i];
cout<<maxtillI(array,n);
return 0;
}




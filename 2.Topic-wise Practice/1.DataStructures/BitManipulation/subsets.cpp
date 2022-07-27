#include<bits/stdc++.h>
using namespace std;

void subsets(int a[],int n)
{
    for(int i = 0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {//for ith number if jth bit is 1 or not
            if(i & 1<<j)
              cout<<a[j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
  int arr[4] = {1,2,3,4};
  subsets(arr,4);
return 0;
}




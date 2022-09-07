#include<bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
// number of sub arrays == (nC2 + n)

void subarraySum(int a[],int n)
{
    for (size_t i = 0; i < n; i++)
    {
        int sum = 0;
        for (size_t j = i; j < n; j++)
        {
           sum += a[j];
           cout << sum << " ";
        }
        
        
    }
    cout<<endl;
    
}
int main(){

int n;
cin>>n;
int array[n];

for(int i=0;i<n;i++)
    cin>>array[i];

  subarraySum(array,n);

return 0;
}




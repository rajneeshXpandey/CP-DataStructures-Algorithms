#include <bits/stdc++.h>

using namespace std;

int right(int n,int d)
{
return (n >> d)|(n << (INT_BITS - d)); 
}

int left(int n,int d)
{
       
  return (n << d)|(n >> (INT_BITS - d));
}


int main()
{
    
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
       cout<<left(n,d)<<endl;
       cout<<right(n,d)<<endl;       
    }
    return 0;
}
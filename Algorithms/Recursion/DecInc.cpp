#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

void dec(int n){
    if(n==0)
       {
       return ;
       }

      cout<<n<<" ";
      dec(n-1);
}

void inc(int n){
       if(n==0)
       {
         return ;
       }
       
       inc(n-1);
      cout<<n<<" ";
        
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  
        int n;
        cin>>n;
        dec(n);
        cout<<endl;
        inc(n);
    
    return 0;
}
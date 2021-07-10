#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)


using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        vector<ll> v(n);
        rep(i,n) cin>>v[i];
    
        sort(v.begin(),v.end());
         int count = 0;
        for (size_t i = 0; i < n-1; i++)
        {
            if(v[i+1]-v[i] <= d)
             {i++;
             count++;}
        }
       cout<<count<<endl; 
    }
   
}
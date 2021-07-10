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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        rep(i,n) cin>>v[i];

        int k = v[0];
    
    for(int i=1;i<n;i++)
    {  
       if(v[i]<=k)
         v[i]++;
         
      k = v[i];
        
    }

    set<int> s;
    rep(i,n) s.insert(v[i]);
      
      cout<<s.size()<<endl;
    }
    return 0;
}
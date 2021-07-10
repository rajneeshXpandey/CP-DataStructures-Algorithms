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
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        rep(i,n) cin>>v[i];

        int count = 0;
        for(int i = 0;i<n;i++)
        {
            int x = v[i]+k;

            if(x%7==0)
              count++;
        }

        cout<<count<<endl;
    
    }
    return 0;
}
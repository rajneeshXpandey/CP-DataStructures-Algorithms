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

        set<int> s;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                s.insert(v[j]-v[i]);
            }
              
        }

        cout<<s.size()<<endl;
    
    }
    return 0;
}
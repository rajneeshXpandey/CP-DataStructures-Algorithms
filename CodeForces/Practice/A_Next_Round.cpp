#include <bits/stdc++.h>

#define rep(i,n) for(int i=1;i<=(n);++i)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        rep(i,n) cin>>v[i];

        int score = v[k];
        int ans = 0;
        int i=1;
             while (v[i]>0 and v[i] >= score and i<=n)
              {
                 ans++;
                i++;
              }
    
        cout << ans << endl;
    }
    return 0;
}
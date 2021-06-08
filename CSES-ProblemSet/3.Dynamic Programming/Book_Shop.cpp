#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)


// *********************** Code Begins ************************ //


// ALWAYS USE *DP* OF VECTOR NOT ARRAY


void solve()
{  
    int n,x;
    cin>>n>>x;
    int val[n];
    forn(i,n)
     cin>>val[i];
    int page[n];
    forn(i,n)
     cin>>page[i];

    vector<vector<int> > dp(n+1,vector<int>(x+1));

    forn(i,n+1)
    {
        forn(j, x + 1)
        {
            if(i==0 or j==0)
               dp[i][j] = 0;
            else{
                if(val[i-1]<=j)
                   dp[i][j] = max(page[i-1]+dp[i-1][j-val[i-1]],dp[i-1][j]);
                 else
                   dp[i][j] = dp[i - 1][j];
              }
        }
    }
    cout << dp[n][x];
 }

signed main()
{
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
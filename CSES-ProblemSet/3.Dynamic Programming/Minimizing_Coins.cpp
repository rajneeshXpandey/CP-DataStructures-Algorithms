
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
                          // maxheap for pair<int,int>
#define mod 1000000007   //1e9+7

// *********************** Code Begins ************************ //


void solve()
{  
    int n,x;
    cin>>n>>x;
    vector<int> coin(n);
    forn(i,n)
      cin>>coin[i];
    vector<vector<int>> dp(n+1, vector<int>(x+1));
    for (int j = 1; j < x + 1; j++)
    {
        dp[0][j] = INT_MAX - 1;
    }
    for (int i = 1; i < n + 1; i++)
        for (int j = 1; j < x + 1; j++)
        {
            if (coin[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i][j - coin[i - 1]] + 1, dp[i - 1][j]);
            }
        }

    if (dp[n][x] >= INT_MAX - 1)
        cout << "-1" << endl;
    else
        cout << dp[n][x] << endl;
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
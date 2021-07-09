#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = a; i <= (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n-1)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define mod 1000000007
#define int long long

// *********************** Code Begins ************************ //


void solve()
{
    int n, m;
    cin >> n >> m;
    int arr[n];
    forn(i, n)
            cin>>arr[i];
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    // very important :  m>=1
    forn(i, n)
        {
            //base case
            if (i == 0)
            {
                if (arr[i] == 0)
                    rep(j, 1, m)
                        dp[i][j] = 1;
                else
                    dp[i][arr[i]] = 1;

                continue;
            }

            if (arr[i] != 0)
            {
                dp[i][arr[i]] = (dp[i - 1][arr[i] - 1] % mod + dp[i - 1][arr[i]] % mod + (((arr[i] + 1) <= m) ? dp[i - 1][arr[i] + 1] % mod : 0));
            }
            else
            {
                rep(j, 1, m)
                    dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod + (((j + 1) <= m) ? dp[i - 1][j + 1] % mod : 0));
            }
        }
    int ans = 0;

    forn(i, m + 1)
        ans = (ans % mod + dp[n - 1][i] % mod) % mod;

    cout<< ans%mod;
}

signed main()
{

    int tt = 1;
    for (int i = 1; i <= tt; i++)
    {
        // cout<<"Case #"<< i <<": ";
        solve();
    }
}
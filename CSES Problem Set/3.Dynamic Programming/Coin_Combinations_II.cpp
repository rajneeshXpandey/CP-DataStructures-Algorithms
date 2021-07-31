
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
#define mod 1000000007

// *********************** Code Begins ************************ //

// Method 2
//here while calling the prev to prev ways got repeated so instead of doing for particular 
// target we can calculate the possible target using particular coin

void solve()
{
    int n, x;
    cin >> n >> x;
    int coin[n];
    forn(i, n)
            cin >> coin[i];
    vector<int> dp(x+1,0);

    //base
    dp[0] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 1; j <= x; j++)
        {
          if(coin[i]<=j)  
            dp[j] = (dp[j]+dp[j-coin[i]])%mod;  
        }
    forn(i,x+1)
     cout<<dp[i]<<" ";
    // cout << dp[x] % mod << endl;
}



//Method 1
//Unbounded knapsack ---> "always give unique ways"

// void solve()
// {
//     int n, x;
//     cin >> n >> x;
//     int coin[n];
//     forn(i, n)
//             cin >>coin[i];
//     vector<vector<int>> dp(n + 1, vector<int>(x + 1));
//     for (int j = 0; j <= x ; j++)
//     {
//         dp[0][j] = 0;
//     }
//     for (int i = 0; i <= n ; i++)
//     {
//         dp[i][0] = 1;
//     }

//     dp[0][0] = 0;

//     for (int i = 1; i <= n ; i++)
//         for (int j = 1; j <= x; j++)
//         {
//             if (coin[i - 1] > j)
//             {
//                 dp[i][j] = dp[i - 1][j] % mod;
//             }
//             else
//             {
//                 dp[i][j] = (dp[i][j - coin[i - 1]] % mod + dp[i - 1][j] % mod) % mod;
//             }
//         }

//     cout << dp[n][x]%mod << endl;
// }
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
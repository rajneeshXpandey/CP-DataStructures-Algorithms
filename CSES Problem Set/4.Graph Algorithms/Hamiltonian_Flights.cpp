#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
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
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x) 
#define mod 1000000007   //1e9+7

// *********************** Code Begins ************************ //

vector<int> *adj;

int Hamiltonian(int src, int mask, int dest, vector<vector<int>> &dp)
{
    if(setbits(mask)==dest)
      return 1;
    else if(src==dest-1) // this case is important
      return 0;  

    if(dp[mask][src]!=-1)
        return dp[mask][src];
      
    int count = 0;
    for(auto nb : adj[src])
    {
        if(mask&(1<<nb))
          continue;
        count = (count+Hamiltonian(nb,mask|(1<<nb),dest,dp))%mod;  
    }

    return dp[mask][src] = count;
}

void solve()
{  
    int n,e;
    cin>>n>>e;
    adj = new vector<int>[n];
    forn(i,e)
     {
         int a,b;
         cin>>a>>b;
         // 0-based index
         a--,b--;
         adj[a].pb(b);
     }

     vector<vector<int>> dp(1<<n,vector<int>(n,-1));
     cout << Hamiltonian(0, (1 << 0), n,dp) << endl;

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
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
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
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define oset  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

// *************************** Code Begins **************************** //

int power(int a,int n)
 {
     int res = 1;
     while(n>0)
      {
          if(n%2) 
            res = (res*a)%mod , n--;
          else
            a = (a*a)%mod , n /= 2; 
      }

      return res;
 }

void solve()
{  
    int n,k;
    cin>>n; cin>>k;
    string s; cin>>s;
    //  cout<<s<<endl;
    if (n == 1)
    {
        cout << (s[0] - 'a')<< endl;
        return;
    }
    int ans = 0;
    forn(i,ceil((double)n / 2))
     {
        
        int num = (s[i] - 'a'), ways = (power(k, (ceil((double)n / 2) - 1 - i)));
        ans += num*ways;
        // deb3(ans, num,ways );
        ans %= mod;
     }
     bool ok = 0;
     for(int i = ((n + 1) / 2) -1 ; i>=0;i--)
     {
         if (s[i] < s[n - i - 1])
         {
             ok = true;
             break;
         }
         else if (s[i] > s[n - i - 1])
             break;
     }
    if(ok)
       ans++;
    cout<<ans%mod<<endl;
}

signed main()
{
    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
         cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
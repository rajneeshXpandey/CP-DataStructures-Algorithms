// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//   cout << fixed << setprecision(10);
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
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
#define mod 1000000007
#define inf 2000000000000000000 //2e18
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define fo(i, a, n) for (ll i = (ll)a; i < (ll)n; i++)
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

// *************************** Code Begins **************************** //

ll nCr(ll n, ll r)
{
    if (r == 0 || r == n)
        return 1;
    if (r == 1)
        return n;
    if ((n - r) > r)
        r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    int i;
    fo(i, 1, n + 1)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[r];
}

void solve()
{
    string st;
    cin>>st;
    int o=0,x=0,may=0;
    for(auto s : st)
     {
         if(s=='o') o++;
         else if(s=='x') x++;
         else may++;
     }
    
    if(o<4)
     {
         int ans = 0;
         forn(i,o+1)
         {
             if(i%2)
               ans -= (nCr(o, i)*pow((o+may-i),4));
             else
               ans += (nCr(o, i)*pow((o+may-i),4));
            //dbg(ans);
         }
         cout<<ans<<endl;
         return;
     }
    if(o==4)
     {
         cout<<24<<endl;
         return;
     } 
    if(o>4)
     {
         cout<<0<<endl;
         return;
     } 
}

signed main()
{
    FIO;
    int tt = 1;
    //cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}
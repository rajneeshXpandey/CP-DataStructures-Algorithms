 #pragma GCC optimize ("O3")
 #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;

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
#define removeDuplicate(x) \
    sort(all(x));          \
    x.erase(unique(all(x)), x.end())       //remove Duplicate
#define setbits(x) __builtin_popcountll(x) // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007                                        //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI 3.141592653589793238
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

// *********************** Code Begins ************************ //

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n) cin >> v[i];
    vector<pii> o, e;
    forn(i, n){
        if (v[i] % 2)
            o.pb({i, v[i]});
        else
            e.pb({i, v[i]});
    }
    sort(all(o));
    sort(all(e));
    vector<pii> ores, eres;
    int l = 0, r = 0;
    forn(i, n){
        if (i % 2 == 0 and l < e.size())
            eres.pb(e[l]), l++;
        if (i % 2 and r < o.size())
            eres.pb(o[r]), r++;
    }
    l = 0, r = 0;
    forn(i, n){
        if (i % 2 and l < e.size())
            ores.pb(e[l]), l++;
        if (i % 2 == 0 and r < o.size())
            ores.pb(o[r]), r++;
    }
    int eeswap = 0, eoswap = 0, eok = 0, ook = 0;
    if (eres.size() == n)
    {
        eok = 1;
        forn(i, n){
            if (i % 2 == 0)
                eeswap += abs(eres[i].ff - i);
            else
                eoswap += abs(eres[i].ff - i);
        }
    }
    int oeswap = 0, ooswap = 0;
    if (ores.size() == n){
        ook = 1;
        forn(i, n){
            if (i % 2 == 0)
                oeswap += abs(ores[i].ff - i);
            else
                ooswap += abs(ores[i].ff - i);
        }
    }
    if (abs((int)o.size() - (int)e.size()) > 1)
            cout << "-1" << endl; 
    else if (eok and ook)
            cout << min(ooswap, eoswap) << endl;
    else if (eok)
            cout << eoswap << endl;
    else cout << ooswap << endl;
    
}

signed main()
{
    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        // cout<<"Case #"<< i <<": ";
        solve();
    }
}
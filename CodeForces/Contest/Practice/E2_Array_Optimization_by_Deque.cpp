#pragma G++ optimize ("O3")
#pragma G++ target ("sse4")
#pragma G++ target("avx2")
#pragma G++ optimize("Ofast")

#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
#define removeDuplicate(x)   sort(all(x)); x.erase(unique(all(x)),x.end())   //remove Duplicate
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
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

// find_by_order, order_of_key
#define pbds  tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// *********************** Code Begins ************************ //

bool Exist(pbds &s, int x)
{ //this function checks weather the value (x) exists in the set or not.

    if ((s.upper_bound(x)) == s.end())
    {
        return 0;
    }
    return ((*s.upper_bound(x)) == x);
}

int Value(pbds &s, int idx)
{ //this function returns the value at the index (idx)..(0 indexing).

    return (*s.find_by_order(idx));
}

int FirstIdx(pbds &s, int x)
{ //this function returns the first index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    return (s.order_of_key(x));
}

int LastIdx(pbds &s, int x)
{ //this function returns the last index of the value (x)..(0 indexing).

    if (!Exist(s, x))
    {
        return -1;
    }
    if (Value(s, (int)s.size() - 1) == x)
    {
        return (int)(s.size()) - 1;
    }
    return FirstIdx(s, *s.lower_bound(x)) - 1;
}

void solve()
{  
     pbds oset;
     int n;
     cin>>n;
     vector<int> v(n);
     forn(i,n){
         cin>>v[i];
     }
     int ans = 0;
     oset.insert(v[0]);
     rep(i,1,n){
         int less_x = oset.order_of_key(v[i]),
             less_equal_x = LastIdx(oset, v[i])+1,
             greater_x = oset.size() - less_x - (((less_equal_x == 0) ? less_x : less_equal_x) - less_x);
         ans += min(less_x,greater_x);
         oset.insert(v[i]);
     }
    cout<<ans<<endl;
}

signed main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
#pragma GCC optimize("unroll-loops,O3,Ofast")

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define sz(v) (ll)(v.size())
#define pb push_back
#define pii pair<int, int>
#define make_unique(vec) \
    sort(all(vec));      \
    vec.resize(unique(all(vec)) - vec.begin());                              // remove Duplicate
#define generate_random(vec) generate(all(vec), rand);                       // fill vec with ramdom nums
#define rotate_by_k(vec, k) rotate(vec.begin(), vec.begin() + k, vec.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a));                                 // Create a set from a vector
#define is_present(vec, key) binary_search(all(vec), key);                   // Check if an element occurs in a sorted sequence
#define binary_rep(n) bitset<32>(n);                                         // binary representation of a number
#define min4(a, b, c, d) min({a, b, c, d});                                  // min of four elements
#define min3(a, b, c) min({a, b, c});
#define setbits(x) __builtin_popcountll(x) // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)   // zeros before first setbit
#define mod 1000000007                     // 1e9+7
#define mod1 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg1 cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define pqmx priority_queue<int>                               // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqmx priority_queue<pii>                            // maxheap for pair<int,int>
#define piipqmn priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define ump unordered_map<int, int>

typedef tuple<int, int, int> tuplei;

// assign and update min and max values.
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// mt19937_64 rng(61378913);
/* usage - just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
inline ll power(ll a, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res *= a;
        a *= a, n /= 2;
    }
    return res;
}
inline void printArr(vector<int> v)
{
    for (auto val : v)
        cout << val << ' ';
    cout << endl;
}

// ********************************* Code Begins ********************************** //

void solve()
{
    int n, m;
    cin >> n >> m;
    int l = 1;
    int ind[n + 2] = {0}, a[n + 1] = {0};
    ind[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ind[x] = i;
        a[i] = x;
    }
    int c = 1;
    for (int i = 1; i <= n; i++)
    {
        if (l > ind[i])
            c++;
        l = ind[i];
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        int r = a[x], s = a[y];
        swap(a[x], a[y]);
        if (ind[r - 1] <= ind[r] && ind[r - 1] > y)
            c++;
        if (ind[r - 1] > ind[r] && ind[r - 1] <= y)
            c--;
        if (ind[r] <= ind[r + 1] && y > ind[r + 1])
            c++;
        if (ind[r] > ind[r + 1] && y <= ind[r + 1])
            c--;
        ind[r] = y;
        if (ind[s - 1] <= ind[s] && ind[s - 1] > x)
            c++;
        if (ind[s - 1] > ind[s] && ind[s - 1] <= x)
            c--;
        if (ind[s] <= ind[s + 1] && x > ind[s + 1])
            c++;
        if (ind[s] > ind[s + 1] && x <= ind[s + 1])
            c--;
        ind[s] = x;
        cout << c << endl;
    }
}

/*
 4 2 1 5 3 => 3

 a_idx :
p.ff=1,p.ss=6
p.ff=2,p.ss=1
p.ff=3,p.ss=2
p.ff=4,p.ss=8
p.ff=5,p.ss=10 <-
p.ff=6,p.ss=16
p.ff=7,p.ss=3
p.ff=8,p.ss=4
p.ff=9,p.ss=7
p.ff=10,p.ss=14
p.ff=11,p.ss=15
p.ff=12,p.ss=17
p.ff=13,p.ss=12
p.ff=14,p.ss=9
p.ff=15,p.ss=0
p.ff=16,p.ss=13
p.ff=17,p.ss=19 <-
p.ff=18,p.ss=18
p.ff=19,p.ss=5
p.ff=20,p.ss=11

 elements   indexes
 1      :     1 <- newr
 2      :     2 <- newl
 3      :     4  <-
 4      :     0  <-
 5      :     3

lets collect like this:
    1
    2 -> 3
    4 -> 5
    so, backarrow we need to draw when we don't have
    further elements to add to current sequence
    2 <- 1
    4 <- 3 these are two back arrows
*/

signed main(){
    FastIO;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    // cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}
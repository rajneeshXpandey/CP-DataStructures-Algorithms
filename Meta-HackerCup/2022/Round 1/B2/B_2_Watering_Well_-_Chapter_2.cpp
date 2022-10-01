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

int productSum(vector<int> &arr)
{
    int n = sz(arr);
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (sum * arr[i]) % mod;
        ans %= mod;
        sum += arr[i];
        sum %= mod;
    }
    return (ans);
}

void solve()
{
    // inputs
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    forn(i, n)
    {
        cin >> a[i] >> b[i];
    }
    int q;
    cin >> q;
    vector<int> x(q), y(q);
    forn(i, q)
    {
        cin >> x[i] >> y[i];
    }

    // pre-process
    int aSqSum = 0, bSqSum = 0, xSqSum = 0, ySqSum = 0;
    forn(i, n)
    {
        aSqSum = (aSqSum + (a[i] * a[i]) % mod) % mod;
    }
    forn(i, n)
    {
        bSqSum = (bSqSum + (b[i] * b[i]) % mod) % mod;
    }
    forn(i, q)
    {
        xSqSum = (xSqSum + (x[i] * x[i]) % mod) % mod;
    }
    forn(i, q)
    {
        ySqSum = (ySqSum + (y[i] * y[i]) % mod) % mod;
    }
    // forn(i,n){
    //     aSumSq = (aSumSq + a[i]) % mod;
    // }
    // aSumSq = (aSumSq*aSumSq)%mod;
    // forn(i, n)
    //{
    //     bSumSq = (bSumSq + b[i]) % mod;
    // }
    // bSumSq = (bSumSq*bSumSq)%mod;
    // forn(i,q){
    //     xSumSq = (xSumSq + x[i]) % mod;
    // }
    // xSumSq = (xSumSq*xSumSq)%mod;
    // forn(i,q){
    //     ySumSq = (ySumSq + y[i]) % mod;
    // }
    // ySumSq = (ySumSq*ySumSq)%mod;

    vector<int> ax(n + q), by(n + q);
    forn(i, n)
    {
        ax[i] = a[i];
    }
    forn(i, q)
    {
        ax[i + n] = x[i];
    }
    forn(i, n)
    {
        by[i] = b[i];
    }
    forn(i, q)
    {
        by[i + n] = y[i];
    }

    int axProduct = 0; // productSum(ax)-productSum(a)-productSum(x)
    int byProduct = 0; // productSum(by)-productSum(b)-productSum(y)4

    axProduct = productSum(ax);
    axProduct = (mod + axProduct - productSum(a)) % mod;
    axProduct = (mod + axProduct - productSum(x)) % mod;

    byProduct = productSum(by);
    byProduct = (mod + byProduct - productSum(b)) % mod;
    byProduct = (mod + byProduct - productSum(y)) % mod;

    // calculating ans
    int ans = 0;
    ans = (ans + (q * aSqSum) % mod) % mod;
    ans = (ans + (q * bSqSum) % mod) % mod;

    ans = (ans + (n * xSqSum) % mod) % mod;
    ans = (ans + (n * ySqSum) % mod) % mod;

    ans = (mod + ans - (2 * axProduct) % mod) % mod;
    ans = (mod + ans - (2 * byProduct) % mod) % mod;

    cout << ans << endl;
}

signed main()
{
    FastIO;
    freopen("watering_well_chapter_2_input.txt", "r", stdin);
    freopen("watering_well_chapter_2_output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        cout << "Case #" << test_case << ": ";
        solve();
    }
}
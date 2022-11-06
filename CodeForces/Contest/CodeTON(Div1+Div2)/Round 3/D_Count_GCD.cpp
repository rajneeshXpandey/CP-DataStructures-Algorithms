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
#define binary_rep(n) bitset<32>(n);                                         // binary representation of a number
#define setbits(x) __builtin_popcountll(x)                                   // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)                                     // zeros before first setbit
#define mod 1000000007                                                       // 1e9+7
#define mod1 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

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
/* usage - generate random numbers, just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
inline ll power(ll a, ll n)
{
    a %= mod;
    int res = 1;
    while (n)
    {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}
inline void binary(ll n)
{
    std::string binaryMask = std::bitset<64>(n).to_string();
    cout << binaryMask << endl;
}
inline void printArr(vector<int> v)
{
    for (auto val : v)
        cout << val << ' ';
    cout << endl;
}

// ********************************* Code Begins ********************************** //
vector<int> prime_factorization(int n)
{
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                mp[i]++, n /= i;
        }
    }
    if (n > 1)
        mp[n]++;
    vector<int> v;
    for(auto p : mp) v.pb(p.ff);
    sort(all(v));
    return v;
}
int gc(int f, int c)
{
    vector<int> pfacs = prime_factorization(f);
    int k = sz(pfacs);
    assert(k<=10);
    int gcc = 0;
    for (int mask = 1; mask<(1<<k); mask++)
    {
        if (setbits(mask) & 1)
        { // odd -> add
            int cc = c;
            for (int j = 0; j < k; j++)
            {
                if (mask&(1 << j))
                    cc /= pfacs[j];
            }
            gcc += cc;
        }
        else
        { // even
            int cc = c;
            for (int j = 0; j < k; j++)
            {
                if (mask & (1 << j))
                    cc /= pfacs[j];
            }
            gcc -= cc;
        }
    }
    return (c-gcc);
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    int ans = 1;
    int _gcd = a[0];
    loop(i, 1, n - 1)
    {
        /*
            _gcd = a[i]*fac1
            b[i] = a[i]*fac2
            now fac2 -> 1....m/a[i] but exclude fac2 such that gcd(fac2,fac1)==1
            ans += (m/a[i] - #(num_coprime with fac1))
        */
        if(_gcd%a[i]) ans=0;
        int fac1 = (_gcd/ a[i]);
        int inc = (gc(fac1, (m / a[i])) + mod1) % mod1;
        //deb3(_gcd,fac1,gc(fac1, m/a[i]));
        ans = (ans * inc) % mod1;
        _gcd = gcd(_gcd, a[i]);
    }
    ans%=mod1;
    cout << ans << endl;
}

signed main()
{
    FastIO;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}
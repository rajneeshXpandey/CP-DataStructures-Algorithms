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
inline void assign1ton(vector<int> &v) { iota(v.begin(), v.end(), 1); }
template <typename T>
inline void printDS(T ds)
{
    for (auto val : ds)
        cout << val << ' ';
    cout << endl;
}

// ********************************* Code Begins ********************************** //

bool check(vector<int> &arr){
    loop(i, 0, sz(arr) - 3){
        if (arr[i] == arr[i + 1] or arr[i + 1] == arr[i + 2])
            return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    vector<int> ans1,ans2,ans3,ans4;
    int l = 0, r = n / 2;
    while (r < n and l < n/2){
        ans1.pb(a[l]),l++;
        ans1.pb(a[r]),r++;
    }
    if (r == n-1)
        ans1.pb(a[r]);
    if(check(ans1)){
        printDS(ans1);
        return;
    }  
    l=0, r=(n+1)/2;
    while(l<(n+1)/2 and r<n){
        ans2.pb(a[l]), l++;
        ans2.pb(a[r]), r++;
    } 
    if(l==n/2)
        ans2.pb(a[l]), l++;
    if(check(ans2)){
        printDS(ans2);
        return;
    } 

    l = 0, r = n / 2;
    while (r < n and l < n/2){
        ans3.pb(a[r]),r++;
        ans3.pb(a[l]),l++;
    }
    if (r == n-1)
        ans3.pb(a[r]);

    if(check(ans3)){
        printDS(ans3);
        return;
    }  
    l=0, r=(n+1)/2;
    while(l<(n+1)/2 and r<n){
        ans4.pb(a[r]), r++;
        ans4.pb(a[l]), l++;
    } 
    if(l==n/2)
        ans4.pb(a[l]), l++;

    if(check(ans4)){
        printDS(ans4);
        return;
    }  
    //printDS(ans);
    neg;
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
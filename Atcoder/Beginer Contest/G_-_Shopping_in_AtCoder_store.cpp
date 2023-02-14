#pragma GCC optimize("unroll-loops,O3,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

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
#define size(dataStructure) (ll)(dataStructure.size())
#define pb push_back
#define pii pair<int, int>
#define make_unique(vect) \
    sort(all(vect));      \
    vect.resize(unique(all(vect)) - vect.begin());                               // remove Duplicate
#define generate_random(vect) generate(all(vect), rand);                         // fill vect with ramdom nums
#define rotate_by_k(vect, k) rotate(vect.begin(), vect.begin() + k, vect.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a));                                     // Create a set from a vector
#define binary_rep(n) bitset<32>(n);                                             // binary representation of a number
#define setbits(x) __builtin_popcountll(x)                                       // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)                                         // zeros before first setbit
#define mod 1000000007                                                           // 1e9+7
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
inline void printDS(T dataStructure)
{
    for (auto val : dataStructure)
        cout << val << ' ';
    cout << endl;
}
template <typename T>
inline void print(T anything) { cout << anything << "\n"; }

// ********************************* Here we go!! ********************************** //
// Convex Hull Trick
// use : for recurrence of type: yi = mj*xi + cj   [j<i]

/* query in logN */
// for max yi, insert (mi,ci), max y = eval()
// for min yi, insert (-mi,-ci), min y = -eval()

const ll is_query = -(1LL << 62);
struct line
{
    ll m, b;
    mutable function<const line *()> succ;
    bool operator<(const line &rhs) const
    {
        if (rhs.b != is_query)
            return m < rhs.m;
        const line *s = succ();
        if (!s)
            return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};

struct dynamic_hull : public multiset<line>
{ // will maintain upper hull for maximum
    bool bad(iterator y)
    {
        auto z = next(y);
        if (y == begin())
        {
            if (z == end())
                return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end())
            return y->m == x->m && y->b <= x->b;

        /* compare two lines by slope, make sure denominator is not 0 */
        ll v1 = (x->b - y->b);
        if (y->m == x->m)
            v1 = x->b > y->b ? inf : -inf;
        else
            v1 /= (y->m - x->m);
        ll v2 = (y->b - z->b);
        if (z->m == y->m)
            v2 = y->b > z->b ? inf : -inf;
        else
            v2 /= (z->m - y->m);
        return v1 >= v2;
    }
    void insert_line(ll m, ll b)
    {
        auto y = insert({m, b});
        y->succ = [=]
        { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y))
        {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y)))
            erase(next(y));
        while (y != begin() && bad(prev(y)))
            erase(prev(y));
    }
    ll eval(ll x)
    {
        auto l = *lower_bound((line){x, is_query});
        return l.m * x + l.b;
    }
};

/*
    line m*x+c
    for every j -> x
                                         mi   xj       c       const
        find maxx of [(Bi+Cj)*(n-i)] => (-i)*(Cj) + Bi*(n-i) + Cj*n

*/
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> b(n);
    forn(i, n) cin >> b[i];
    sort(all(b));
    dynamic_hull hull;
    forn(i, n)
    {
        hull.insert_line(-i, b[i] * (n - i));
    }
    int c;
    forn(i, m)
    {
        cin >> c;
        cout << hull.eval(c) + c * n << ' ';
    }
}

signed main()
{
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
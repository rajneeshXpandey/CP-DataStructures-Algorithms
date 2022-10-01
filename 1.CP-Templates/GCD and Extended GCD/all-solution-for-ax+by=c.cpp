#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include "bits/stdc++.h"
using namespace std;

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
//  using namespace __gnu_pbds;

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
#define make_unique(vec) \
    sort(all(vec));      \
    vec.resize(unique(all(vec)) - vec.begin());                              // remove Duplicate
#define generate_random(vec) generate(all(vec), rand);                       // fill vec with ramdom nums
#define rotate_by_k(vec, k) rotate(vec.begin(), vec.begin() + k, vec.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a));                                 // Create a set from a vector
#define is_present(vec, key) binary_search(all(vec), key);                   // Check if an element occurs in a sorted sequence
#define binary_rep(n) bitset<20>(n);                                         // binary representation of a number
#define min4(a, b, c, d) min({a, b, c, d});                                  // min of four elements
#define min3(a, b, c) min({a, b, c});
#define setbits(x) __builtin_popcountll(x) // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007                                        // 1e9+7
#define mod1 998244353
#define inf 2000000000000000000 // 2e18
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

// find_by_order, order_of_key
// #define pbds  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// mt19937_64 rng(61378913);
/* usage - just do rng() */

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

inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
inline void printArr(vector<int> v)
{
    for (auto val : v)
        cout << val << ' ';
    cout << endl;
}

// *********************** Code Begins ************************ //

//all solution of ax+by=c in [minx,maxx], [miny,maxy]
int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool solve_any(int a, int b, int c, int &x, int &y, int &g) {
    if (a == 0 && b == 0) {
        g = x = y = 0;
        return true;
    }
    g = gcd(abs(a), abs(b), x, y);
    if (c % g != 0) {
        return false;
    }
    x *= (c / g);
    y *= (c / g);
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return true;
}

void shift(int &x, int &y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int solve_all(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!solve_any(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;
    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;
    shift(x, y, a, b, (minx - x) / b);
    if (x < minx) {
        shift(x, y, a, b, sign_b);
    }
    if (x > maxx)
        return 0;
    int lx1 = x;
    shift(x, y, a, b, (maxx - x) / b);
    if (x > maxx) {
        shift(x, y, a, b, -sign_b);
    }
    int rx1 = x;
    shift(x, y, a, b, (y - miny) / a);
    if (y < miny) {
        shift(x, y, a, b, -sign_a);
    }
    if (y > maxy)
        return 0;
    int lx2 = x;

    shift(x, y, a, b, (y - maxy) / a);
    if (y > maxy) {
        shift(x, y, a, b, sign_a);
    }
    int rx2 = x;
    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
    if (lx > rx) return 0;
    return (rx - lx) / abs(b) + 1;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int minx, miny, maxx, maxy;
    cin >> minx >> maxx >> miny >> maxy;
    if (maxx < minx || maxy < miny) {
        cout << 0 << endl;
        exit(0);
    }
    if (a == 0 && b == 0) {
        if (c == 0) {
            cout << (maxy - miny + 1) * (maxx - minx + 1) << endl;
        } else {
            cout << 0 << endl;
        }
    } else if (a == 0 || b == 0) {
        if (a == 0) {
            if (c % b == 0 && (c / b) >= miny && (c / b) <= maxy) {
                cout << maxx - minx + 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            if (c % a == 0 && (c / a) >= minx && (c / a) <= maxx) {
                cout << maxy - miny + 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    } else
        cout << solve_all(a, b, c, minx, maxx, miny, maxy) << endl;
}

signed main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        // cout<<"Case #"<< i <<": ";
        solve();
    }
}
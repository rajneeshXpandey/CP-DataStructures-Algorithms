#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define generate_random(vect) generate(all(vect), rand); // fill vect with ramdom nums
#define binary_rep(n) bitset<32>(n);                     // binary representation of a number
#define setbits(x) __builtin_popcountll(x)               // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)                 // zeros before first setbit
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// useful functions
inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); } // gcd
// power in mod
inline ll power(ll a, ll n, ll mod)
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
inline ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
inline ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down

// Debugging
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
template <typename T>
inline void printDS(T dataStructure)
{
    for (auto val : dataStructure)
        cout << val << ' ';
    cout << endl;
}

// numeric values
// #define mod 1000000007   //1e9+7
// #define mod 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> mis0(n + 1), mis1(n + 1);
    vector<int> pref0(n + 1), pref1(n + 1);

    for (int i = 1; i <= n; i++) {
        int bit = s[i - 1] - '0';

        int p0 = (i & 1) ? 0 : 1; // 010101...
        int p1 = p0 ^ 1;          // 101010...

        mis0[i] = (bit != p0);
        mis1[i] = (bit != p1);

        pref0[i] = pref0[i - 1];
        pref1[i] = pref1[i - 1];

        if (mis0[i] && (i == 1 || !mis0[i - 1]))
            pref0[i]++;

        if (mis1[i] && (i == 1 || !mis1[i - 1]))
            pref1[i]++;
    }

    auto runs = [&](vector<int> &mis, vector<int> &pref, int l, int r) {
        int res = pref[r] - pref[l - 1];
        if (l > 1 && mis[l] && mis[l - 1])
            res--;
        return res;
    };

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        int ans;

        if (l & 1) {
            ans = min(runs(mis0, pref0, l, r),
                      runs(mis1, pref1, l, r));
        } else {
            ans = min(runs(mis1, pref1, l, r),
                      runs(mis0, pref0, l, r));
        }

        cout << (ans <= k ? "YES" : "NO") << '\n';
    }
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
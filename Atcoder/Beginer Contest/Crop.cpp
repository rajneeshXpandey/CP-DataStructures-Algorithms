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

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m));
    forn(i, n){
        forn(j,m){
            cin >> grid[i][j];
        }
    }
    int sx=n, sy=m, ex=-1, ey=-1;
    bool found=0;
    forn(i, n){
        forn(j,m){
            if(grid[i][j]=='#'){
                sx = i;
                found = 1;
                break;
            }
        }
        if(found) break;
    }
    found=0;
    for(int i=n-1;i>=0;i--){
        for( int j=m-1;j>=0;j--){
            if(grid[i][j]=='#'){
                ex = i;
                found = 1;
                break;
            }
        }
        if(found) break;
    }
    found=0;
    for( int j=0;j<m;j++){
            for(int i=n-1;i>=0;i--){
            if(grid[i][j]=='#'){
                sy = j;
                found = 1;
                break;
            }
        }
        if(found) break;
    }
    found=0;
    for( int j=m-1;j>=0;j--){
        for(int i=n-1;i>=0;i--){
            if(grid[i][j]=='#'){
                ey = j;
                found = 1;
                break;
            }
        }
        if(found) break;
    }
    int srow = min(sx,ex);
    int erow = max(sx,ex);
    int scol = min(sy,ey);
    int ecol = max(sy,ey);

    for(int i=srow;i<=erow;i++){
        for(int j=scol;j<=ecol;j++){
                cout<<grid[i][j];
        }
        cout<<endl;
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
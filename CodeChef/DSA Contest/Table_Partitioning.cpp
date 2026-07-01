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

/** 
2

5 5
1 2
2 3
3 1
3 4
4 5

1 -> 2, 3
2 -> 1, 3 
3 -> 1, 2, 4
4 -> 3, 5
5 -> 4


  1 - 2 
  \  /
   (3) --- 4 - (5)


5 3
1 2
2 3
4 5

1 -> 2
2 -> 3 
3 -> 2
4 -> 5
5 -> 4

    1--2--3
    4--5
 */

 // check bipartite 
bool dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color)
{
    color[node] = col;

    for (auto child : adj[node])
    {
        if (color[child] == -1)
        {
            if (!dfs(child, col ^ 1, adj, color))
                return false;
        }
        else if (color[child] == col)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mat[u][v] = 1;
        mat[v][u] = 1;
    }

    // Build complement graph
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (!mat[i][j])
            {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, adj, color))
            {
                NO;
                return;
            }
        }
    }

    YES;
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
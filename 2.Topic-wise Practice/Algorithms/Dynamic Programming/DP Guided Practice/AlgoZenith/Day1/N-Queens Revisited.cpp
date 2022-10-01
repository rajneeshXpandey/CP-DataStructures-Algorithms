#pragma GCC optimize("unroll-loops,O3,Ofast")

#include "bits/stdc++.h"
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

int dx[] = {-2,-1,-2,-1};
int dy[] = {-1,-2,1,2};

bool good(int x,int y,int n){
    if(x>=0 and x<n and y>=0 and y<n) return 1;
    return 0;
}
bool place_possible(vector<int> &Squeen, int row_level, int n, int col)
{
    if (Squeen[row_level] != -1)
        return 0;
    for (int row = 0; row < row_level; row++)
    {
        if (Squeen[row] == col)
            return 0; // check for column
        if (abs(row_level - row) == abs(col - Squeen[row]))
            return 0; // check for diagonal
    }
    // checking for knight only above the curr row
    for(int k=0;k<4;k++){
        if (good(row_level + dx[k], col + dy[k], n) and Squeen[row_level + dx[k]] == col + dy[k])
            return 0;
    }
    return 1;
}

int findways(vector<int> &Squeen, int row_level, int n)
{
    if (row_level == n)
        return 1; // because, as when we reached n, we have made one possible arrangments.
    int cnt = 0;
    for (int col = 0; col < n; col++)
    {
        if (place_possible(Squeen, row_level, n, col))
        {
            Squeen[row_level] = col;
            cnt += findways(Squeen, row_level + 1, n);
            Squeen[row_level] = -1;
        }
    }
    return cnt;
}
/*
An S-Queen is a chess piece that combines the power of a knight and a queen.
Find the number of ways to place N S-Queens on N x N chessboard.



Input Format

The input contains only single integer N denoting the side of the chessboard.


Output Format

Print the number of ways to place N S-Queens on the N x N chessboard.


Constraints

2 ≤ N ≤ 14
*/
void solve()
{
    // Squeen -> has power of both queen and knight
    int n;
    cin>>n;
    vector<int> Squeen(n, -1); // position of Squeen in every row
    int ans = findways(Squeen, 0, n);
    cout << ans << endl;
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
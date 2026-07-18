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


void bfs(int x,int y, vector<vector<int>>& grid, vector<vector<int>>& vis,vector<vector<int>>& dist,int n, int m,int k){
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    dist[x][y]=0;
    while(!q.empty()){
        auto [xx,yy] = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((abs(xx-i)+abs(yy-j)<=k) && vis[i][j]==0 && grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                    dist[i][j] = min(dist[i][j],dist[xx][yy]+1);
                }
            }
        }
    }
}

void solve()
{
    int n, m, k1, k2;
    cin >> n >> m >> k1 >> k2 ;
    vector<vector<int>> grid(n,vector<int>(m)),
                    vis1(n,vector<int>(m,0)),
                    vis2(n,vector<int>(m,0)),
                    mindist1(n,vector<int>(m,inf)),
                    mindist2(n,vector<int>(m,inf));
    forn(i, n){
        forn(j,m){
            cin>>grid[i][j];
        }
    }
    bfs(0,0,grid,vis1,mindist1,n,m,k1);
    bfs(0,m-1,grid,vis2,mindist2,n,m,k2);
    int ans = inf;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                if((i==0 && j==0) || (i==0 && j==m-1)){}
                else{
                    ans = min(ans,max(mindist1[i][j],mindist2[i][j]));
                }
        }
    }
    if(ans==inf) ans = -1;
    cout<<ans-1<<endl;
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
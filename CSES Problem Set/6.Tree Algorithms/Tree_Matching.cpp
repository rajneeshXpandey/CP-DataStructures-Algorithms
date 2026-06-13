#include <bits/stdc++.h>

using namespace std;

#define loop(i, a, b)  for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n-1)
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
#define binary_rep(n) bitset<32> (n); // binary representation of a number
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x) // zeros before first setbit
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
inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);} // gcd
inline ll power(ll a, ll n, ll mod){a %= mod; int res = 1; while(n){if (n & 1) res = (res * a) % mod; a = (a * a) % mod;n >>= 1;} return res;} // power in mod
inline ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
inline ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

// Debugging
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
template<typename T> inline void printDS(T dataStructure){for(auto val : dataStructure) cout<<val<<' '; cout<<endl;}
template<typename T> inline void print(T anything){cout<<anything<<"\n";}

// numeric values
//#define mod 1000000007   //1e9+7
//#define mod 998244353
#define inf 2000000000000000000 //2e18
#define pi  3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

void dfs(int node, int par, vector<vector<int>> &tree, vector<vector<int>>& dp){
    for(auto& child: tree[node]){
        if(child==par) continue;
        dfs(child,node,tree,dp);
        dp[node][0] += max(dp[child][0], dp[child][1]);
    }
    for (auto &child : tree[node])
    {
        if (child == par)
            continue;
        dp[node][1] = max(dp[node][1], 1 + dp[child][0] + dp[node][0] - max(dp[child][0], dp[child][1]));
    }
}
void solve(){
    int n,u,v;
    cin >> n;
    vector<vector<int>> tree(n);
    for(int i=1;i<n;i++){
        cin>>u>>v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    // dp[i][0/1]: max #edges in matching set, if (i -> x) edge is none_taken/one_taken
    vector<vector<int>> dp(n,{0,0}); 
    dfs(0,-1,tree,dp);
    int ans=0;
    ans = max({ans,dp[0][0],dp[0][1]});
    cout<<ans<<endl;
}

signed main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
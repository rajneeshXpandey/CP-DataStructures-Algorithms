#pragma GCC optimize("unroll-loops,O3,Ofast")

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b)  for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n-1)
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
#define make_unique(vec) sort(all(vec)); vec.resize(unique(all(vec)) - vec.begin()); //remove Duplicate
#define generate_random(vec) generate(all(vec), rand); // fill vec with ramdom nums
#define rotate_by_k(vec,k) rotate(vec.begin(), vec.begin() + k, vec.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a)); // Create a set from a vector
#define binary_rep(n) bitset<32> (n); // binary representation of a number
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x) // zeros before first setbit
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define pi  3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

typedef tuple<int, int, int> tuplei;

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// mt19937_64 rng(61378913);
/* usage - generate random numbers, just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline ll power(ll a, ll n){ ll res = 1; while (n > 0){ if (n % 2) res *= a; a *= a,n /= 2;} return res;}
inline void binary(ll n) { std::string binaryMask = std::bitset<64>(n).to_string(); cout<<binaryMask<<endl;}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// ********************************* Code Begins ********************************** //

// Minimum Spanning Tree using DSU

class dsu
{
public:
    vector<int> parent;
    vector<int> size, rank;

    explicit dsu(int n)
    {
        parent.resize(n);
        size.resize(n);
        rank.resize(n);
        for (int x = 0; x < n; x++)
        {
            parent[x] = x;
            size[x] = 1;
            rank[x] = 0;
        }
    }

    int find_set(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find_set(parent[x]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            size[b] += size[a];
            size[a] = 0;
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return (weight < other.weight);
    }
};

vector<Edge> MST(vector<Edge> &edges, int n,int &cost)
{
    dsu d(n+1);
    vector<Edge> result;
    sort(edges.begin(), edges.end());
    for (Edge e : edges)
    {
        if (d.find_set(e.u) != d.find_set(e.v))
        {
            cost += e.weight;
            result.push_back(e);
            d.union_sets(e.u, e.v);
        }
    }
    return result;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n){ 
        cin >> a[i];
    }
    //sort(all(a));
    vector<vector<int>> bitrep(31);
    loop(i,0,n-1){
        for(int x=0;x<31;x++){
            if((a[i]&(1LL<<x))){
                bitrep[x].pb(i);
            }
        }
    }
    vector<Edge> edges;
    forn(i,31){
            for(int j=1;j<bitrep[i].size();j++){
                edges.pb({bitrep[i][j], bitrep[i][j-1], (1LL<<i)});
        }
    }
    int cost=0;
    vector<Edge> _mst = MST(edges,n,cost);
    if(_mst.size()!=n-1){
        cout<<"-1"<<endl;
        return;
    }
    //for(auto x:_mst){
    //    cout<<x.u+1<<" "<<x.v+1<<" "<<x.weight<<endl;
    //}
    cout<<cost<<endl;
}

signed main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
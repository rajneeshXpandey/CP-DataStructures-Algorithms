#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <numeric>
#include <climits>
using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define tuplei tuple<int, int, int>;

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
template <typename T>
inline void print(T anything) { cout << anything << "\n"; }

// Data structures
#define max_heap priority_queue<int>                            // maxpq
#define min_heap priority_queue<int, vector<int>, greater<int>> // minpq

// numeric values
// #define mod 1000000007   //1e9+7
// #define mod 998244353
#define inf 2000000000000000000 // 2e18
#define pi 3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

void dfs(long long src, long long dest, vector<vector<pair<long long, long long> > > &graph, vector<long long> &visited, long long xorValue, long long &minXor)
{
    if(src == dest){
        minXor = min(minXor, xorValue);
        return;
    }
    visited[src] = 1;
    for(auto &neighbour : graph[src]){
        if(!visited[neighbour.first]){
            dfs(neighbour.first, dest, graph, visited, (xorValue^neighbour.second), minXor);
        }
    }
    visited[src] = 0;
}

void solve(){
    long long n,m;
    cin>>n>>m;
    vector<vector<pair<long long, long long> > > graph(n);
    forn(i,m){
        long long u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u, w));
    }
    long long minXor = inf;
    vector<long long> visited(n, 0);
    dfs(0,n-1,graph,visited,0,minXor);
    cout<<minXor<<endl;
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
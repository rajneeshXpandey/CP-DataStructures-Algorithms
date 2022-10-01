#pragma G++ optimize ("O3")
#pragma G++ target ("sse4")
#pragma G++ target("avx2")
#pragma G++ optimize("Ofast")

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
#define removeDuplicate(x)   sort(all(x)); x.erase(unique(all(x)),x.end())   //remove Duplicate
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
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

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// *********************** Code Begins ************************ //

const int LIM = 800008;
const int LIM2 = 21; // ceil(log2(LIM)) + 1

int N;
int D[LIM] // depth of ith node
  , A[LIM]; // Ancestor level
vector<int> adj[LIM], F[LIM] // for Freq
            , P[LIM]; // P <==> dp[u][i] 
vector<int> O; // for storing the traversal

void rec(int i)
{
    O.push_back(i);
    for (int j = 0; j < LIM2; j++)
    {
        int p = P[i][j];
        if (p < 0)
        {
            break;
        }
        P[i][j + 1] = P[p][j];
    }
    for (int j : adj[i])
    {
        if (j != P[i][0])
        {
            P[j][0] = i;
            D[j] = D[i] + 1;
            rec(j);
        }
    }
}

int lca(int a, int b)
{
    if (D[a] < D[b])
    {
        swap(a, b);
    }
    for (int i = LIM2 - 1; i >= 0; i--)
    {
        int p = P[a][i];
        if (p >= 0 && D[p] >= D[b])
        {
            a = p;
        }
    }
    for (int i = LIM2 - 1; i >= 0; i--)
    {
        if (P[a][i] != P[b][i])
        {
            a = P[a][i];
            b = P[b][i];
        }
    }
    return a == b ? a : P[a][0];
}

void solve()
{
    O.clear();
    for (int i = 0; i < LIM; i++)
    {
        adj[i].clear();
        P[i].assign(LIM2, -1);
        F[i].clear();
    }
    // Input.
    cin >> N;
    for (int i = 0, a, b; i < N - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0, f; i < N; i++)
    {
        cin >> f;
        F[f - 1].push_back(i);
    }
    // DFS through tree, computing depths, ancestors, and pre-order.
    rec(0);
    // Compute LCA requirements for each frequency.
    for (int i = 0; i < N; i++)
    {
        if (F[i].empty())
        {
            continue;
        }
        int a = F[i][0];
        for (int j = 1; j < (int)F[i].size(); j++)
        {
            a = lca(a, F[i][j]);
        }
        for (int k : F[i])
        {
            A[k] = D[a];
        }
    }
    // Iterate upwards through tree, computing answer.
    int ans = 0;
    for (int j = N - 1; j > 0; j--)
    {
        int i = O[j];
        if (A[i] == D[i])
        {
            ans++;
        }
        else
        {
            A[P[i][0]] = min(A[P[i][0]], A[i]);
        }
    }
    cout<<ans<<endl;
}

signed main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
          cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
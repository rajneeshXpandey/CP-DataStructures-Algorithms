// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

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
// #define oset  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}

// *********************** Code Begins ************************ //

#include <bits/stdc++.h>
using namespace std;

struct node
{
    //req variable
    int minVal;
    //default value
    node()
    {
        minVal = INT_MAX;
    }
};
class segtree
{
public:
    int n{};
    vector<node> tree;
    vector<int> a;
    node neutral;

    void init(int N)
    {
        n = N;
        tree.resize(4 * n + 1);
        //default values
        a.assign(n, 0);
    }

    void put(vector<int> &val)
    {
        a = val;
    }

    //merge function
    void merge(node &curr, node &left, node &right)
    {
        curr.minVal = min(left.minVal , right.minVal);
    }

    //for leaf
    void single(node &curr, int idx)
    {
        curr.minVal = a[idx];
    }

    void build(int index, int ss, int se)
    {
        if (ss == se)
        {
            single(tree[index], ss);
            return;
        }
        int mid = (ss + se) / 2;
        build(2 * index, ss, mid);
        build(2 * index + 1, mid + 1, se);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }

    void build()
    {
        build(1, 0, n - 1);
    }

    node query(int index, int ss, int se, int qs, int qe)
    {
        if (qs > se || qe < ss)
            return neutral;
        if (qs <= ss && qe >= se)
            return tree[index];
        int mid = (ss + se) / 2;
        node left = query(2 * index, ss, mid, qs, qe);
        node right = query(2 * index + 1, mid + 1, se, qs, qe);
        node mer;
        merge(mer, left, right);
        return mer;
    }

    node query(int l, int r)
    {
        return query(1, 0, n - 1, l, r);
    }
};

void solve()
{  
    int n,q,left,right;
    cin>>n>>q;
    vector<int> v(n);
    forn(i,n) cin>>v[i];
    segtree st;
    st.init(n);
    st.put(v);
    st.build();
    forn(i,q){
        cin>>left>>right;
        cout<<st.query(left-1,right-1).minVal<<endl;
    } 
}

signed main()
{
    FastIO;
    int tt = 1;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
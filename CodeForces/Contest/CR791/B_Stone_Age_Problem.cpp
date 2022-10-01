#pragma GCC optimize("unroll-loops,O3,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include "bits/stdc++.h"
using namespace std;

#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n - 1)
#define forone(i, n) loop(i, 1, n)
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
#define setbits(x) __builtin_popcountll(x)                     // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x)                       // zeros before first setbit
#define pqmx priority_queue<int>                               // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqmx priority_queue<pii>                            // maxheap for pair<int,int>
#define piipqmn priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define mod 1000000007                                         // 1e9+7
#define mod1 998244353
#define inf 2000000000000000000 // 2e18
#define PI 3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

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
vector<int> a;

class segtree
{
public:
    int n{};
    vector<int> tree;
    vector<int> lazy;

    void init(int N)
    {
        n = N;
        tree.resize(4 * n + 4);
        // default values
        lazy.assign(4 * n + 4, 0);
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            // Leaf node will have a single element
            tree[node] = a[start];
        }
        else
        {
            int mid = (start + end) / 2;
            // Recurse on the left child
            build(2 * node, start, mid);
            // Recurse on the right child
            build(2 * node + 1, mid + 1, end);
            // Internal node will have the sum of both of its children
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val)
    {
        if (lazy[node] != 0)
        {
            // This node needs to be updated
            tree[node] = (end - start + 1) * lazy[node]; // Update it
            if (start != end)
            {
                lazy[node * 2] = lazy[node];     // Mark child as lazy
                lazy[node * 2 + 1] = lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start > end or start > r or end < l) // Current segment is not within range [l, r]
            return;
        if (start >= l and end <= r)
        {
            // Segment is fully within range
            tree[node] = (end - start + 1) * val;
            if (start != end)
            {
                // Not leaf node
                lazy[node * 2] = val;
                lazy[node * 2 + 1] = val;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(node * 2, start, mid, l, r, val);       // Updating left child
        updateRange(node * 2 + 1, mid + 1, end, l, r, val); // Updating right child
        tree[node] = tree[node * 2] + tree[node * 2 + 1];   // Updating root with max value
    }

    int queryRange(int node, int start, int end, int l, int r)
    {
        if (start > end or start > r or end < l)
            return 0; // Out of range
        if (lazy[node] != 0)
        {
            // This node needs to be updated
            tree[node] = (end - start + 1) * lazy[node]; // Update it
            if (start != end)
            {
                lazy[node * 2] = lazy[node];     // Mark child as lazy
                lazy[node * 2 + 1] = lazy[node]; // Mark child as lazy
            }
            lazy[node] = 0; // Reset it
        }
        if (start >= l and end <= r) // Current segment is totally within range [l, r]
            return tree[node];
        int mid = (start + end) / 2;
        int p1 = queryRange(node * 2, start, mid, l, r);       // Query left child
        int p2 = queryRange(node * 2 + 1, mid + 1, end, l, r); // Query right child
        return (p1 + p2);
    }
};
void solve()
{
    int n, q, type, idx, x;
    cin >> n >> q;
    a.resize(n);
    forn(i, n) cin >> a[i];
    //printArr(a);
    segtree st;
    st.init(n);
    st.build(1,0,n-1);
    while(q--)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> idx >> x;
            idx--;
            st.updateRange(1,0,n-1,idx,idx, x);
            cout << st.queryRange(1, 0, n - 1, 0, n - 1) << endl;
        }
        else if(type==2)
        {
            cin >> x;
            st.updateRange(1, 0, n - 1, 0, n - 1, x);
            cout << st.queryRange(1, 0, n - 1, 0, n - 1) << endl;
        }
    }
}

signed main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    FastIO;
    int total_testcases = 1;
    // cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++)
    {
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }
}
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

template <typename A, typename B>
string to_string(pair<A, B> p)
{
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <size_t N>
string to_string(bitset<N> v)
{
    string res = "";
    for (size_t i = 0; i < N; i++)
    {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v)
{
    bool first = true;
    string res = "{";
    for (const auto &x : v)
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
//   cout << fixed << setprecision(10);
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define dbg3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007
#define inf 2000000000000000000 //2e18
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define oset            tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

// *************************** Code Begins **************************** //

struct node
{
    //req variable
    int ggcd;
    //default value
    node()
    {
        ggcd = 0;
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
        curr.ggcd = __gcd(left.ggcd, right.ggcd);
    }

    //for leaf
    void single(node &curr, int idx)
    {
        curr.ggcd = a[idx];
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

    void update(int index, int idx, int ss, int se)
    {
        if (idx < ss || idx > se)
            return;
        if (ss == se)
        {
            single(tree[index], ss);
            return;
        }
        int mid = (ss + se) / 2;
        update(2 * index, idx, ss, mid);
        update(2 * index + 1, idx, mid + 1, se);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }

    void update(int idx)
    {
        update(1, idx, 0, n - 1);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    forn(i, n)
            cin >>v[i];

    segtree st;
    st.init(n);
    st.put(v);
    st.build();
    // int g = st.query(0, 4).gcd;
    // dbg(g);
    int min_size = inf;
    int i = -1, j = 0;
    while(j<n)
    {
       while (i <= j and st.query(i + 1, j).ggcd == 1)
          i++;
       if (st.query(i, j).ggcd == 1)
           min_size = min(j - i + 1, min_size);
       j++;
    //    dbg(min_size);      
    }
    if(min_size==inf)
     cout<<"-1"<<endl;
    else
        cout << min_size;
}

signed main()
{
    FIO;
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
        solve();
}
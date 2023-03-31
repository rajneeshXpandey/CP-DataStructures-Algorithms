#pragma GCC optimize("unroll-loops,O3,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

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
#define size(dataStructure) (ll)(dataStructure.size())
#define pb push_back
#define pii pair<int, int>
#define make_unique(vect) sort(all(vect)); vect.resize(unique(all(vect)) - vect.begin()); //remove Duplicate
#define generate_random(vect) generate(all(vect), rand); // fill vect with ramdom nums
#define rotate_by_k(vect,k) rotate(vect.begin(), vect.begin() + k, vect.end()); // cyclically shift a vector by k.
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
inline ll power(ll a, ll n){a %= mod; int res = 1; while(n){if (n & 1) res = (res * a) % mod; a = (a * a) % mod;n >>= 1;} return res;}
inline void binary(ll n) { std::string binaryMask = std::bitset<64>(n).to_string(); cout<<binaryMask<<endl;}
inline void assign1ton(vector<int> &v) { iota(v.begin(), v.end(), 1); }
template<typename T> inline void printDS(T dataStructure){for(auto val : dataStructure) cout<<val<<' '; cout<<endl;}
template<typename T> inline void print(T anything){cout<<anything<<"\n";}

// ********************************* Here we go!! ********************************** //

struct node
{
    ll lrsum,one,zero,op,oprev;
    // default value
    node()
    {
        lrsum = 0;
        one = 0;
        zero = 0;
        op = 0;
        oprev = 0;
    }
};
class segte
{
public:
    ll n{};
    vector<node> tree;
    vector<ll> lazy;
    vector<bool> prsnt;
    node neutral;
    vector<int> a;

    void init(ll N)
    {
        n = N;
        tree.resize(4 * n + 1);
        lazy.assign(4 * n + 1, 0);
        prsnt.assign(4 * n + 1, false);
    }
    void put(vector<int> &val)
    {
        a = val;
    }

    // merge function
    static void merge(node &curr, node &left, node &right)
    {
        curr.lrsum = left.lrsum + right.lrsum;
        curr.one = left.one + right.one;
        curr.zero = left.zero + right.zero;
        curr.op = left.op + right.op + (left.one * right.zero);
        curr.oprev = left.oprev + right.oprev + (left.zero * right.one);
    }

    void prop(ll index, ll ss, ll se)
    {
        ll len = (se - ss) + 1;

        if (lazy[index]&1LL){
            tree[index].lrsum = len - tree[index].lrsum;
            tree[index].one = len - tree[index].one;
            tree[index].zero = len - tree[index].zero;
            ll temp = tree[index].oprev;
            tree[index].oprev = tree[index].op;
            tree[index].op = temp;
        }

        if (ss != se)
        {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
            prsnt[2 * index] = prsnt[2 * index + 1] = true;
        }
        lazy[index] = 0;
        prsnt[index] = false;
    }

    void build(ll index, ll ss, ll se)
    {
        if (ss == se)
        {
            tree[index].lrsum = a[ss];
            tree[index].op = 0;
            tree[index].oprev = 0;
            if (a[ss] == 0)
                tree[index].zero = 1;
            else
                tree[index].one = 1;
            return;
        }
        ll mid = (ss + se) / 2;
        build(2 * index, ss, mid);
        build(2 * index + 1, mid + 1, se);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }

    void build()
    {
        build(1, 0, n - 1);
    }

    node query(ll index, ll ss, ll se, ll qs, ll qe)
    {
        if (prsnt[index])
            prop(index, ss, se);
        if (qs > se || qe < ss)
            return neutral;
        if (qs <= ss && qe >= se)
            return tree[index];
        ll mid = (ss + se) / 2;
        node left = query(2 * index, ss, mid, qs, qe);
        node right = query(2 * index + 1, mid + 1, se, qs, qe);
        node mer;
        merge(mer, left, right);
        return mer;
    }
    node query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
    void update(ll index, ll ss, ll se, ll l, ll r, ll inc)
    {
        if (prsnt[index])
            prop(index, ss, se);
        if (r < ss || l > se)
            return;
        if (ss >= l && se <= r)
        {
            prsnt[index] = true;
            lazy[index] += inc;
            prop(index, ss, se);
            return;
        }
        ll mid = (ss + se) / 2;
        update(2 * index, ss, mid, l, r, inc);
        update(2 * index + 1, mid + 1, se, l, r, inc);
        merge(tree[index], tree[2 * index], tree[2 * index + 1]);
    }
    void update(ll l, ll r, ll inc)
    {
        update(1, 0, n - 1, l, r, inc);
    }
};

void solve(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> arr(n);
    forn(i, n) {
        arr[i] = s[i] - '0';
    }
    segte st;
    st.init(n);
    st.put(arr);
    st.build();
    int type, l, r;
    while (q--) {
        cin>> type >> l >> r;
        l--, r--;
        if(type == 1) {
            st.update(l, r, 1);
        }
        else {
            auto ans = st.query(l, r).op;
            cout << ans << endl;
        }
    }

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
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
inline ll power(ll a, ll n){a %= mod; int res = 1; while(n){if (n & 1) res = (res * a) % mod; a = (a * a) % mod;n >>= 1;} return res;}
inline void binary(ll n) { std::string binaryMask = std::bitset<64>(n).to_string(); cout<<binaryMask<<endl;}
template<typename T> inline void printDS(T ds){for(auto val : ds) cout<<val<<' '; cout<<endl;}

// ********************************* Code Begins ********************************** //
/*
struct node
{
    // required variables
    vector<pii> countAtKthbit; //#0 and #1 
    // default value
    node()
    {
        countAtKthbit.assign(60,{0,0});
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
        // default values
        a.assign(n, 0);
    }

    void put(vector<int> &val)
    {
        a = val;
    }

    // merge function
    void merge(node &curr, node &left, node &right)
    {
        // merge operations
        forn(i,60){
            curr.countAtKthbit[i].ff = left.countAtKthbit[i].ff + right.countAtKthbit[i].ff;
            curr.countAtKthbit[i].ss = left.countAtKthbit[i].ss + right.countAtKthbit[i].ss;
        }
    }

    // for leaf
    void single(node &curr, int idx)
    {
        // carefully assign values to single node/consider updates here
        //curr.sum = a[idx];
        forn(i,60){
            if(a[idx]&(1<<i))
                curr.countAtKthbit[i].ss++;
            else
                curr.countAtKthbit[i].ff++;
        }
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

    void update(int idx, int updated_value)
    {
        a[idx] = updated_value;
        update(1, idx, 0, n - 1);
    }
};
*/
void solve(){
    int n,q;
    cin >> n >>q;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    //segtree st;
    //st.init(n);
    //st.put(a);
    //st.build();
    vector<vector<array<int, 2>>> prex(n + 1, vector<array<int, 2>>(61,{0, 0}));
    loop(i,1,n){
        forn(k,61){
            if((a[i-1]&(1LL<<k))){
                prex[i][k][1] = prex[i-1][k][1]+1;
                prex[i][k][0] = prex[i-1][k][0];
            }
            else{
                prex[i][k][1] = prex[i-1][k][1];
                prex[i][k][0] = prex[i-1][k][0]+1;
            }
        }
    }
    //loop(i,0,n){
    //    forn(k,60){
    //        cout<<prex[i][k][0]<<' '<<prex[i][k][1]<<endl;
    //    }
    //    cout<<"-----"<<endl;
    //}
    int k,l1,r1,l2,r2;
    while(q--){
        cin>>k>>l1>>r1>>l2>>r2;
        //l1--,r1--,l2--,r2--;
        //auto ans1 = st.query(l1, r1).countAtKthbit[k];
        //auto ans2 = st.query(l2,r2).countAtKthbit[k];
        //int ans = (ans1.ff*ans2.ss)+(ans1.ss*ans2.ff);
        auto ans10 = prex[r1][k][0]-prex[l1-1][k][0];
        auto ans11 = prex[r1][k][1]-prex[l1-1][k][1];
        auto ans20 = prex[r2][k][0]-prex[l2-1][k][0];
        auto ans21 = prex[r2][k][1]-prex[l2-1][k][1];
        int ans = ((ans10 * ans21) + (ans20 * ans11));
        cout<<ans<<endl;
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
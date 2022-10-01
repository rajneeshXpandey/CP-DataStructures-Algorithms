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

struct node
{
    // req variable
    int sum;
    int cnt[3]; // counts of 1,2,3 
    // default value
    node()
    {
        forn(i,3) cnt[i]=0;
        sum = 0;
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
        curr.sum = left.sum + right.sum;
        curr.cnt[0] = left.cnt[0] + right.cnt[0];
        curr.cnt[1] = left.cnt[1] + right.cnt[1];
        curr.cnt[2] = left.cnt[2] + right.cnt[2];
    }

    // for leaf
    void single(node &curr, int idx)
    {
        curr.sum = a[idx];
        if(a[idx]==1)
            curr.cnt[0] = 1, curr.cnt[1] = 0, curr.cnt[2] = 0;
        else if(a[idx]==2)
            curr.cnt[0] = 0, curr.cnt[1] = 1, curr.cnt[2] = 0;
        else if(a[idx]==3)
            curr.cnt[0] = 0, curr.cnt[1] = 0, curr.cnt[2] = 1;
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
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    forn(i, n) cin >> arr[i];
    segtree st;
    st.init(n);
    st.put(arr);
    st.build();
    int x,y,z;
    int ans=0;
    while(m--){
        cin>>x>>y>>z;
        x--,z--;
        st.a[x] = y;
        st.update(x);
        auto q1 = st.query(0,z);
        auto q2 = st.query(z+1,n-1);
        int tans=0;
        if(abs(q1.sum + q2.sum)%2){
            tans = -1;
        }
        if(q1.sum==q2.sum){
            tans=0;
        }
        else{
            int l1=q1.cnt[0],l2=q1.cnt[1],l3=q1.cnt[2];
            int r1=q2.cnt[0],r2=q2.cnt[1],r3=q2.cnt[2];
            if (q1.sum > q2.sum){
                int diff = q1.sum - q2.sum;
                // 3 1 
                int remove4 = min({diff/4,l3,r1});
                diff -= 4*remove4;
                l3 -= remove4;
                r1 -= remove4;
                tans += remove4;
                // 2 1
                int remove2 = min({diff/2,l2,r1});
                diff -= 2*remove2;
                l2 -= remove2;
                r1 -= remove2;
                tans += remove2;
                // 3 2
                remove2 = min({diff/2,l3,r2});
                diff -= remove2*2;
                l3 -= remove2;
                r2 -= remove2;
                tans += remove2;
                if(diff) tans=-1;
            }
            else {
                int diff = q2.sum - q1.sum;
                // 1 3
                int remove4 = min({diff / 4, l1, r3});
                diff -= 4 * remove4;
                l1 -= remove4;
                r3 -= remove4;
                tans += remove4;
                // 1 2
                int remove2 = min({diff / 2, l1, r2});
                diff -= 2 * remove2;
                l1-= remove2;
                r2 -= remove2;
                tans += remove2;
                // 2 3
                remove2 = min({diff / 2, l2, r3});
                diff -= remove2 * 2;
                l2 -= remove2;
                r3 -= remove2;
                tans += remove2;

                if(diff) tans=-1;
            }
        }
        ans += tans;
    }
    cout<<ans<<endl;

}

signed main(){
    FastIO;
    freopen("worklife_balance_chapter_1_input.txt", "r", stdin);
    freopen("worklife_balance_chapter_1_output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
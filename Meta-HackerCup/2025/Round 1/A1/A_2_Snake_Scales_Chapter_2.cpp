#pragma GCC optimize("unroll-loops,O3,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
#include <iostream>
#include <map>

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
#define pii pair<int, int>
#define make_unique(vect) sort(all(vect)); vect.resize(unique(all(vect)) - vect.begin()); //remove Duplicate
#define generate_random(vect) generate(all(vect), rand); // fill vect with ramdom nums
#define rotate_by_k(vect,k) rotate(vect.begin(), vect.begin() + k, vect.end()); // cyclically shift a vector by k.
#define vector_to_set(a) set<int> S(all(a)); // Create a set from a vector
#define binary_rep(n) bitset<32> (n); // binary representation of a number
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x) // zeros before first setbit
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define neg cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define tuplei tuple<int, int, int>;

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// useful functions
inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);} // gcd
inline ll power(ll a, ll n, ll mod){a %= mod; int res = 1; while(n){if (n & 1) res = (res * a) % mod; a = (a * a) % mod;n >>= 1;} return res;} // power in mod
inline ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
inline ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
inline void binary(ll n) { std::string binaryMask = std::bitset<64>(n).to_string(); cout<<binaryMask<<endl;}
inline void assign1ton(vector<int> &v) { iota(v.begin(), v.end(), 1); }

// Debugging
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define deb4(x, y, z, zz) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << "," << #zz << "=" << zz << endl
template<typename T> inline void printDS(T dataStructure){for(auto val : dataStructure) cout<<val<<' '; cout<<endl;}
template<typename T> inline void print(T anything){cout<<anything<<"\n";}

//Data structures
#define max_heap priority_queue<int> //maxpq
#define min_heap priority_queue<int, vector<int>, greater<int>> //minpq

// numeric values
//#define mod 1000000007   //1e9+7
//#define mod 998244353
#define inf 2000000000000000000 //2e18
#define pi  3.141592653589793238
double eps = 1e-12;

// ********************************* start ********************************** //

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

    int find(int x)
    {
        return (x == parent[x]) ? (x) : (parent[x] = find(parent[x]));
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return;
        if (rank[a] < rank[b])
            swap(a, b);
        size[b] += size[a];
        size[a] = 0;
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};

struct Edge
{
    int u, v;
    int w;
    bool operator<(Edge const &other) const
    {
        return (w < other.w);
    }
};

void solve(){
        int N;
        cin >> N;
        vector<int> A(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> A[i];

        vector<Edge> edges;
        edges.reserve((N - 1) + N);

        // ground edges
        for (int i = 1; i <= N; ++i)
        {
            Edge e;
            e.u = 0;
            e.v = i;
            e.w = A[i];
            edges.push_back(e);
        }
        // adjacent platform edges
        for (int i = 1; i <= N - 1; ++i)
        {
            Edge e;
            e.u = i;
            e.v = i + 1;
            e.w = llabs(A[i] - A[i + 1]);
            edges.push_back(e);
        }

        sort(edges.begin(), edges.end());

        dsu D(N + 1);
        int components = N + 1;
        int answer = 0;

        for (const auto &e : edges)
        {
            if (D.find(e.u) != D.find(e.v))
            {
                D.unite(e.u, e.v);
                if (e.w > answer)
                    answer = e.w;
                components--;
                if (components == 1)
                    break;
            }
        }
        cout << answer << "\n";
}

signed main(){
    FastIO;
    // freopen("snake_scales_chapter_2_validation_input.txt", "r", stdin);
    // freopen("snake_scales_chapter_2_validation_output.txt", "w", stdout);
     freopen("snake_scales_chapter_2_input.txt", "r", stdin);
     freopen("snake_scales_chapter_2_output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
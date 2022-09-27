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
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// ********************************* Code Begins ********************************** //

void solve(){
    int d,n,x;
    cin>>d>>n>>x; // d: Max D days after they mature, x : one day plant value
    vector<array<int,3>> data(n);
    forn(i, n) 
        cin >> data[i][0] >> data[i][1] >> data[i][2]; // qi, li, vi
    sort(all(data),[&](array<int,3> &a,array<int,3> &b){
        if((d-a[1])==(d-b[1])) 
            return (a[2]>b[2]);
        return ((d - a[1]) < (d - b[1]));
    });
    /*
        we will start planting seeds and when the capacity {(d-li)*x} will reach we remove 
        previuosly planted seeds (that have less vi) from the min_priority_queue and adjust the answers.
    */
    priority_queue<pii, vector<pii>, greater<pii>> minheap;
    int max_cost=0,planted=0,capacity=0;
    forn(i,n){
        capacity = (d-data[i][1])*x;
        planted += data[i][0];
        max_cost += data[i][0]*data[i][2];
        minheap.push({data[i][2],data[i][0]}); // vi , qi
        while(planted>capacity){
            int to_remove = planted-capacity;
            if(minheap.top().ss > to_remove){
                auto c = minheap.top();
                minheap.pop();
                planted -= to_remove;
                c.ss -= to_remove;
                max_cost -= to_remove*c.ff;
                minheap.push(c); // vi , qi-to_remove
            }
            else{
                auto c = minheap.top();
                minheap.pop();
                max_cost -= c.ss * c.ff;
                planted -= c.ss;
            }
        }
    } 
    cout<<max_cost<<endl;
}

signed main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
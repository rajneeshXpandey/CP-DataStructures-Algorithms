#pragma GCC optimize("unroll-loops,O3,Ofast")

#include "bits/stdc++.h"
using namespace std;

#define loop(i, a, b)  for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n-1)
#define forone(i, n) loop(i,1,n)
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
#define is_present(vec, key) binary_search(all(vec), key); // Check if an element occurs in a sorted sequence
#define binary_rep(n) bitset<32> (n); // binary representation of a number
#define min4(a,b,c,d) min({a, b, c, d}); // min of four elements
#define min3(a,b,c) min({a, b, c});
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x) // zeros before first setbit
#define pqmx priority_queue<int>                               // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqmx priority_queue<pii>                            // maxheap for pair<int,int>
#define piipqmn priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

// mt19937_64 rng(61378913);
/* usage - just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline ll power(ll a, ll n){ ll res = 1; while (n > 0){ if (n % 2) res *= a; a *= a,n /= 2;} return res;}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// ********************************* Code Begins ********************************** //

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    map<int,int> mp;
    forn(i,n){
        mp[a[i]%10]++;
    }
    set<vector<pii>> st;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(i+j+k==3 or i+j+k==13 or i+j+k==23){
                    set<int> s;
                    s.insert(i);
                    s.insert(j);
                    s.insert(k);
                    vector<pii> v;
                    if(s.size()==1){
                        v.pb({i,3});
                    }
                    else if(s.size()==2){
                        if(i==j and j!=k)
                            {v.pb({i,2});
                            v.pb({k,1});}
                        else if(i==k and k!=j)
                            {v.pb({i,2});
                            v.pb({j,1});} 
                        else if(j==k and k!=i)
                            {v.pb({j,2});
                            v.pb({i,1});}
                    }
                    else if(s.size()==3){
                            v.pb({j,1});
                            v.pb({i,1});
                            v.pb({k,1});
                    }
                    sort(all(v));
                    st.insert(v);
                }
            }
        }
    }
    for(auto v:st){
        if(sz(v)==1){
            if(mp[v[0].ff]>=v[0].ss){
                cout<<"YES"<<endl;
                return;
            }
        }
        else if(sz(v)==2){
            if(mp[v[0].ff]>=v[0].ss and mp[v[1].ff]>=v[1].ss){
                cout<<"YES"<<endl;
                return;
            }
        }
        else if(sz(v)==3){
            if(mp[v[0].ff]>=v[0].ss and mp[v[1].ff]>=v[1].ss and mp[v[2].ff]>=v[2].ss){
                cout<<"YES"<<endl;
                return;
            }
        }    
    }
    cout << "NO" << endl;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    FastIO;
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
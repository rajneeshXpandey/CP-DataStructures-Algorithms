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

void solve(){
    string str;
    cin>>str;
    int n = str.size();
    int cnt10=0,cnt01=0;
    forn(i,n-1){
        if(str[i]=='0' && str[i+1]=='1') cnt01++;
        if(str[i]=='1' && str[i+1]=='0') cnt10++;
    }
    int ans = 0;
    // changing ith bit
    loop(i,1,n-2){
        if(str[i-1]=='0' and str[i]=='0' && str[i+1]=='0') {      // 000
            if(cnt01+1==cnt10+1) ans++;
        }
        else if(str[i-1]=='0' and str[i]=='0' && str[i+1]=='1') { // 001
            if(cnt01==cnt10) ans++;
        }
        else if(str[i-1]=='0' and str[i]=='1' && str[i+1]=='0') { // 010
            if(cnt01-1==cnt10-1) ans++;
        }
        else if(str[i-1]=='0' and str[i]=='1' && str[i+1]=='1') { // 011
            if(cnt01==cnt10) ans++;
        }
        else if(str[i-1]=='1' and str[i]=='0' && str[i+1]=='0') { // 100
            if(cnt01==cnt10) ans++;
        }
        else if(str[i-1]=='1' and str[i]=='0' && str[i+1]=='1') { // 101
            if(cnt01-1==cnt10-1) ans++;
        }    
        else if(str[i-1]=='1' and str[i]=='1' && str[i+1]=='0') { // 110
            if(cnt01==cnt10) ans++;
        }
        else if(str[i-1]=='1' and str[i]=='1' && str[i+1]=='1') { // 111
            if(cnt01+1==cnt10+1) ans++;
        }
    }
    // for change in idx=0
    int l=0,r=1;
    if(str[l]=='0' and str[r]=='0') {      // 00
        if(cnt01==cnt10+1) ans++;
    }
    else if(str[l]=='0' and str[r]=='1') { // 01
        if(cnt01-1==cnt10) ans++;
    }
    else if(str[l]=='1' and str[r]=='0') { // 10
        if(cnt01==cnt10-1) ans++;
    }
    else if(str[l]=='1' and str[r]=='1') { // 11
        if(cnt01+1==cnt10) ans++;
    }
    // for change in idx=n-1
    l=n-2,r=n-1;
    if(str[l]=='0' and str[r]=='0') {      // 00
        if(cnt01+1==cnt10) ans++;
    }
    else if(str[l]=='0' and str[r]=='1') { // 01
        if(cnt01-1==cnt10) ans++;
    }
    else if(str[l]=='1' and str[r]=='0') { // 10
        if(cnt01==cnt10-1) ans++;
    }
    else if(str[l]=='1' and str[r]=='1') { // 11
        if(cnt01==cnt10+1) ans++;
    }
    cout<<ans<<endl;
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
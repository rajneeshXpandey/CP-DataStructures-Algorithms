#pragma GCC optimize("unroll-loops,O3,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include <bits/stdc++.h>
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

// mt19937_64 rng(61378913);
/* usage - generate random numbers, just do rng() */
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// useful functions
inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);} // gcd
inline ll power(ll a, ll n){int res = 1; while(n){if (n & 1) res = (res * a); a = (a * a);n >>= 1;} return res;} // power in mod
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
vector<int> a;
int cache[1000001];
ll countNumbersWith4(ll n)
{
    // Base case

    if (n < 4)
        return 0;

    // d = number of digits minus one in n. For 328, d is 2
    int d = log10(n);
    if(n<=1e6){
        if(cache[n]!=-1) return cache[n];
    }
    // computing count of numbers from 1 to 10^d-1,
    // d=0 a[0] = 0;
    // d=1 a[1] = count of numbers from 0 to 9 = 1
    // d=2 a[2] = count of numbers from 0 to 99 = a[1]*9 + 10 = 19
    // d=3 a[3] = count of numbers from 0 to 999 = a[2]*19 + 100 = 171
    a.assign(d+1,0);
    a[0] = 0, a[1] = 1;
    for (int i = 2; i <= d; i++)
        a[i] = a[i - 1] * 9 + (power(10, i - 1));

    // Computing 10^d
    int p = (power(10, d));

    // Most significant digit (msd) of n,
    // For 328, msd is 3 which can be obtained using 328/100
    int msd = n / p;

    // If MSD is 4. For example if n = 428, then count of
    // numbers is sum of following.
    // 1) Count of numbers from 1 to 399
    // 2) Count of numbers from 400 to 428 which is 29.
    if (msd == 4){
        if(n<=1e6) 
            return cache[n] = (msd)*a[d] + (n % p) + 1;
        return (msd)*a[d] + (n % p) + 1;
    }

    // IF MSD > 4. For example if n is 728, then count of
    // numbers is sum of following.
    // 1) Count of numbers from 1 to 399 and count of numbers
    //    from 500 to 699, i.e., "a[2] * 6"
    // 2) Count of numbers from 400 to 499, i.e. 100
    // 3) Count of numbers from 700 to 728, recur for 28
    if (msd > 4){
        if (n <= 1e6)
            return cache[n] = (msd - 1) * a[d] + p + countNumbersWith4(n % p);
        return (msd - 1) * a[d] + p + countNumbersWith4(n % p);
    }

    // IF MSD < 4. For example if n is 328, then count of
    // numbers is sum of following.
    // 1) Count of numbers from 1 to 299 a
    // 2) Count of numbers from 300 to 328, recur for 28
    if (n <= 1e6)
        return cache[n] = (msd)*a[d] + countNumbersWith4(n % p);
    return (msd)*a[d] + countNumbersWith4(n % p);
}
void solve(){
    ll k;
    cin >> k;
    // find x such that count(x) = k
    ll l = k, r = 10*k;
    ll x = -1;
    while(l<=r){
        int mid = (l+r)/2;
        int cnt = (mid-countNumbersWith4(mid));
        if(cnt==k){
            x = mid;
            r = mid-1;
        }
        else if(cnt<k){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << x << endl;
}

signed main(){
    FastIO;
    //for(int i=1;i<=150;i++){
    //    cout << i << " " << (i-countNumbersWith4(i)) << endl;
    //}
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(cache,-1,sizeof(cache));
    //countNumbersWith4(1e6);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
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

void rotateMatrix(vector<vector<int>> mat, vector<vector<int>> &rotmat, int n)
{
    for (int x=0,i = n-1; x<n and i >= 0; x++,i--)
    {
        for (int y=0,j = n-1; y<n and j >= 0; y++,j--)
            rotmat[x][y] = mat[i][j];
    }
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<vector<int>> mat(n,vector<int>(n));
    int one=0,z=0;
    forn(i, n)
        forn(j, n) {
            cin >> mat[i][j];
            if(mat[i][j] == 0) z++;
            else one++;
        }
    vector<vector<int>> rotmat(n,vector<int>(n));
    rotateMatrix(mat,rotmat,n);
    //forn(i, n){
    //    forn(j, n) 
    //        cout << rotmat[i][j] << " ";
    //    cout << endl;
    //}
    int cnt=0;
    forn(i, n){
        forn(j, n) 
            if(rotmat[i][j] != mat[i][j]){
                cnt++;
            }
    }
    cnt /= 2;
    if(cnt>k){
        NO;
        return;
    }
    k -= cnt;
    if(n%2==0){
        if(k%2==0){
            YES;
            return;
        }
        else{
            NO;
            return;
        }
    }
    YES;
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
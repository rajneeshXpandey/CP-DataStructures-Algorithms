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
inline void assign1ton(vector<int> &v) { iota(v.begin(), v.end(), 1); }
template<typename T> inline void printDS(T ds){for(auto val : ds) cout<<val<<' '; cout<<endl;}

// ********************************* Here we go!! ********************************** //

bool dfs(vector<vector<char>> &wall,int i,int j,int &n,int b,int &_B,int parx,int pary){
    if(j>=n and b==_B){ 
        //deb2(b,B);
        return true;
    }
    if(j<n and wall[i][j]=='B'){
        if(i==1){
            if(i-1!=parx and j!=pary and wall[i-1][j]=='B'){
                return dfs(wall,i-1,j, n, b + 1, _B,i,j);
            }
            else
                return dfs(wall, i, j + 1, n, b+1, _B,i,j);
        }
        else if(i==0){
            if (i+1!=parx and j!=pary and wall[i+1][j] == 'B'){
                return dfs(wall,i+1,j, n, b + 1, _B,i,j);
            }
            else
                return dfs(wall, i, j + 1, n,b+1,_B,i,j);
        }
        else return 0;
    }
    else 
        return false;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<char>> wall(2LL,vector<char>(n,'$'));
    forn(i, n){
        cin>>wall[0][i];
    }
    forn(i, n){
        cin>>wall[1][i];
    }
    int _B=0;
    forn(i,n){
        //deb2(wall[0][i],wall[1][i]);
        if (wall[0][i]=='W' and wall[1][i]=='W'){
            no;
            return;
        }
        if(wall[0][i]=='B') _B++; 
        if(wall[1][i]=='B') _B++;
    }
    if (dfs(wall, 0, 0, n, 0, _B,-1,-1) || dfs(wall, 1, 0, n, 0, _B,-1,-1)){
        yes;
    }
    else no;
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
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
const int N = 1000002;
vector<bool> prime(N, 1);
void sieve()
{
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < N; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j < N; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(const std::vector<std::vector<int>> &matrix, int n, int m)
{
    // Check the four adjacent cells.
    loop(row,0,n-1){
        loop(col,0,m-1){
                    forn(i,4){
                        if(row+dx[i]>=0 and col+dy[i]>=0 and row+dx[i]<n and col+dy[i]<m){
                            int adjacent_cell = matrix[row + dx[i]][col + dy[i]];
                            // Check if the absolute difference is prime.
                            //deb(abs(adjacent_cell - matrix[row][col]));
                            if (abs(adjacent_cell - matrix[row][col])>1 && prime[(abs(adjacent_cell - matrix[row][col]))]){
                                return false;
                            }
                        }
                    }
            }
    }
    return true;
}


void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> ans(n,vector<int>(m,0));
    if(!prime[n]){
        int x=1;
        forn(j,m){
            forn(i,n){
                ans[i][j]=x;
                x++;
            }
        }
    }
    else if(!prime[m]){
        int x=1;
        forn(i,n){
            forn(j,m){
                ans[i][j]=x;
                x++;
            }
        }
    }
    else{
        int x=1;
        forn(i,n){
            forn(j,m){
                if(i%2==0){
                    ans[i][j]=x;
                    x++;
                }
            }
        }
        forn(i,n){
            forn(j,m){
                if(i%2){
                    ans[i][j]=x;
                    x++;
                }
            }
        }
    }
    assert(check(ans,n,m));
    forn(i,n){
        forn(j,m){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

signed main(){
    FastIO;
    sieve();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
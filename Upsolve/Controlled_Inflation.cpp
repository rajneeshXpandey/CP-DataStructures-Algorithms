#pragma GCC optimize("unroll-loops,O3,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

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
    int n,p;
    cin >> n >> p;
    vector<vector<int>> a(n, vector<int>(p));
    forn(i, n){
        forn(j,p){
            cin >> a[i][j];
        }
    }
    vector<vector<array<int, 3>>> dp(n, vector<array<int, 3>>(2)); /*   inc -> st , end , cost
                                              dec -> st , end ,cost
                                         */
    forn(i,n){
        sort(all(a[i]));
        dp[i][0][0] = a[i][0];
        dp[i][0][1] = a[i][p-1];
        dp[i][0][2]=0;
        forn(j,p-1)
            dp[i][0][2] += abs(a[i][j]-a[i][j+1]);
        sort(rall(a[i]));
        dp[i][1][0] = a[i][0];
        dp[i][1][1] = a[i][p-1];
        dp[i][1][2] = dp[i][0][2];
    }

    int ans = 0;
    int flag = 2; // for curr array iff 0 -> inc , 1 -> dec, 2 -> not sure
    forn(i,n-1){
        int tcost = inf,cost=0;
        if(flag==2){
            // case1 : inc inc
            if (tcost > (dp[i][0][2] + dp[i][0][0] + abs(dp[i][0][1] - dp[i + 1][0][0])))
                tcost = dp[i][0][2] + dp[i][0][0] + abs(dp[i][0][1] - dp[i + 1][0][0]),
                flag = 0;
            // case2 : inc dec
            if (tcost > (dp[i][0][2] + dp[i][0][0] + abs(dp[i][0][1] - dp[i + 1][1][0])))
                tcost = (dp[i][0][2] + dp[i][0][0] + abs(dp[i][0][1] - dp[i + 1][1][0])),
                flag = 1;
            // case3 : dec inc
            if (tcost > (dp[i][1][2] + dp[i][1][0] + abs(dp[i][1][1] - dp[i + 1][0][0])))
                tcost = (dp[i][1][2] + abs(dp[i][1][1] - dp[i + 1][0][0])),
                flag = 0;
            // case4 : dec dec
            if (tcost > (dp[i][1][2] + dp[i][1][0] + abs(dp[i][1][1] - dp[i + 1][1][0])))
                tcost = (dp[i][1][2] + abs(dp[i][1][1] - dp[i + 1][1][0])),
                flag = 1;
        }
        else if(flag == 1){ // case3 and case4
            // case3 : dec inc
            if (tcost > (dp[i][1][2] + abs(dp[i][1][1] - dp[i + 1][0][0])))
                tcost = (dp[i][1][2] + abs(dp[i][1][1] - dp[i + 1][0][0])),
                flag = 0;
            // case4 : dec dec
            if (tcost > (dp[i][1][2] + abs(dp[i][1][1] - dp[i + 1][1][0])))
                tcost = (dp[i][1][2] + abs(dp[i][1][1] - dp[i + 1][1][0])),
                flag = 1;
        }
        else if(flag == 0){ // case1 and case2
            // case1 : inc inc
            if (tcost > (dp[i][0][2] + abs(dp[i][0][1] - dp[i + 1][0][0])))
                tcost = (dp[i][0][2] + abs(dp[i][0][1] - dp[i + 1][0][0])),
                flag = 0;
            // case2 : inc dec
            if (tcost > (dp[i][0][2] + abs(dp[i][0][1] - dp[i + 1][1][0])))
                tcost = (dp[i][0][2] + abs(dp[i][0][1] - dp[i + 1][1][0])),
                flag = 1;
        }

        ans += tcost;
     }
     if(flag==1){
          ans += dp[n-1][1][2];
     }
     if(flag==0){
         ans += dp[n - 1][0][2];
     }

    cout<<ans<<endl;

}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    FastIO;
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
         cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
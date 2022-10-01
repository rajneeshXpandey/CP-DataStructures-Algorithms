#pragma GCC optimize("unroll-loops,O3,Ofast")

#include "bits/stdc++.h"
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
#define is_present(vec, key) binary_search(all(vec), key); // Check if an element occurs in a sorted sequence
#define binary_rep(n) bitset<32> (n); // binary representation of a number
#define min4(a,b,c,d) min({a, b, c, d}); // min of four elements
#define min3(a,b,c) min({a, b, c});
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerobefone(x) __builtin_ctzll(x) // zeros before first setbit
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define pi  3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg1 cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define pqmx priority_queue<int>                               // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqmx priority_queue<pii>                            // maxheap for pair<int,int>
#define piipqmn priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define ump unordered_map<int, int>

typedef tuple<int, int, int> tuplei;

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

int dx[] = {1,1,1};
int dy[] = {-1,0,1};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> building(n,vector<int>(m)), clearWindows(n,vector<int>(m,0));
    forn(i, n){
        forn(j,m){
            cin>>building[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(m,-1));
    
    for(int i=0;i<n;i++)
    {
        forn(j, m)
        {
            if(i==0){
                dp[i][j] = building[i][j];
                clearWindows[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i - 1][j];
                if(j-1>=0)
                    dp[i][j] = max(dp[i][j] , dp[i - 1][j - 1]);
                if(j+1<m)
                    dp[i][j] = max(dp[i][j] , dp[i - 1][j + 1]);

                if (dp[i][j] < building[i][j])
                    clearWindows[i][j] = 1;
                dp[i][j] = max(building[i][j],dp[i][j]);
            }
        }
    }

    forn(i, n)
    {
        forn(j, m)
        {
            cout << clearWindows[i][j];
        }
        cout<<endl;
    }
}


/*
Description

There is a building with N (numbered 1 through N from top to bottom) floors, each with M windows. All the windows need to be cleaned. For each valid i and j, the window (i,j) must be cleaned on the A(i,j)-th turn. From window(i, j), water flows to the window(i+1,j-1), window(i+1,j), and window(i+1,j+1) if exists. When a window(i,j) is cleaned, window(i+1,j-1), window(i+1,j) and window(i+1,j+1) become dirty because of dirty water after cleaning window(i,j). Water flows further down of these dirty windows making next level windows dirty, and the same things go on recursively.

E.g. When the window(0, 5) is getting cleaned. Then the water flows down to windows (1, 4), (1, 5) and (1, 6) making them dirty. Then the water flows from the window (1, 4) down to (2, 3), (2, 4), (2, 5), from the window (1,5) to (2, 4), (2, 5), (2, 6). And so on.

You have to determine whether each window will be clean after the cleaning process ends.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, M - the size of the building.

Each of the next N lines contains Ai,j - the time at which window (i,j) is cleaned. At a time, only one window can be cleaned.


Output Format

For each test case, print N lines, each with M integers denoting whether the (i,j)-th window will be clean or not after the cleaning process ends.


Constraints

1 ≤ T ≤ 1000

1 ≤ N, M ≤ 1000

1 ≤ Ai,j ≤ NM

Sum of NM across all test cases <= 10^7.

*/

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
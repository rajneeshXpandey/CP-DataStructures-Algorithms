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

int dp[100001][4]; // n, idx in [h,a,r,d]
string hard="hard";
int hardProblem(string &str,vector<int> &cost,int level,int idx){
    //deb2(level,idx);
    if(idx==4 or level==sz(str)) return inf;
    
    if (level == sz(str) - 1)
    {
        if (idx == 3 && str[level] == hard[idx])
        {
            return dp[level][idx] = cost[level];
        }
        else
        {
            return dp[level][idx]= 0;
        }
    }

    if(dp[level][idx]!=-1) 
        return dp[level][idx];
    
    int ans = inf;

    // take or not
    if(str[level]==hard[idx])
        ans = min(hardProblem(str, cost, level + 1, idx + 1), cost[level] + hardProblem(str, cost, level + 1, idx));
    else 
        ans = min(ans,hardProblem(str, cost, level+1, idx));

    return dp[level][idx]=ans;
}
void solve(){
    int n;
    cin >> n;
    string str;
    cin>>str;
    vector<int> cost(n);
    forn(i, n) cin >> cost[i];
    memset(dp,-1,sizeof(dp));
    int ans = hardProblem(str,cost,0,0);
    cout<<ans<<endl;
}
/*
Description

You are given a string S with length N. Each character is assigned a cost for removing it. Find the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains one integer N - the length of the array.

The second line of each test case contains a string S.

The third line of each test case contains N space-separated integers - the cost of removing a character.


Output Format

For each test case, print the minimum cost for removing characters such that it does not contain any subsequence ‘hard’.


Constraints

1≤ T ≤ 1000

1≤ N ≤ 10^5

1≤ Ai ≤ 10^9
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
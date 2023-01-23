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

int dp[503][503];
int mergeElement(vector<int> &prex,int l,int r){
    
    if(r==l){
        return 0;
    }
    
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r] = inf;
    for(int k=l;k<=r-1;k++){
        int x = (prex[k]-prex[l-1])%100; 
        int y = (prex[r]-prex[k])%100;
        dp[l][r] = min(dp[l][r], (x * y) + mergeElement(prex,l,k) + mergeElement(prex,k+1,r));
        //deb(dp[l][r]);
    }
    return dp[l][r];
}
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    forn(i, n) cin >> arr[i];
    /*
        merging three elements in any order gives the same result
        [a1 , a2, a3] -> ((a1+a2)%100+a3)%100 == (a1+(a2+a3)%100)%100

                    l        mid mid+1    r
        so lets _ _ [_ _ _ _ _ ][_ _ _ _ _ _] _ _ 
                     \        /  \        /
                      \      /    \      /
                       \    /      \    /
                        \  /        \  /
                         \/          \/
  value after merge      x           y  the values x and y are sum over (l,mid) and (mid+1,r) 
 (l,mid) and (mid+1,r)     \       /
                            \     /
                             \   /
                               z
  and this cost will be x*y for making z
  
    */
    memset(dp,-1,sizeof(dp));
    vector<int> prex(n+1,0);
    loop(i,1,n){
        prex[i] = (prex[i-1]+arr[i-1]);
    }
    int ans = mergeElement(prex,1,n);
    cout<<ans<<endl;
}
/*
Description

You are given N elements, in an array A. You can take any 2 consecutive elements a and b and merge them. On merging you get a single element with value (a+b)%100 and this process costs you a*b. After merging you will place this element in place of those 2 elements.


If the sequence is [A1, A2, A3, A4] and you merge A2 and A3, you incur a cost of A2*A3 and the array becomes [A1, (A2+A3)%100, A4].


Find the Minimum cost to merge all the elements into a single element.


Input Format

The first line contains a single element N. 1 <= N <= 500

The Second line contains N space separated integers, the Ai for the Array.  0 <= Ai < 100


Output Format

Output a single integer, the Minimum cost to Merge all the elements.
*/
signed main(){
    FastIO;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int total_testcases = 1;
    //cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        //cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
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
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// ********************************* Code Begins ********************************** //

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    /*
        -> break the array with bound by 0,
        -> count -ve terms in each subarray(breaked) : 
            if odd [....-x{.....-z......]-y....} => ans will be max of these two cases
            else [....-w....-x....-y....-z....] => whole ans
    */
    vector<int> zero_idx;
    zero_idx.pb(-1);
    forn(i,n){
        if(a[i]==0) zero_idx.pb(i);
    }
    zero_idx.pb(n);
    int ans = -11;
    forn(i,sz(zero_idx)-1){
        int negCount=0,currAns=-11;
        pii boundNegIdx = {-1,-1};
        for(int j=zero_idx[i]+1;j<=zero_idx[i+1]-1;j++){
            if(a[j]<0){
                if (boundNegIdx.ff == -1)
                    boundNegIdx.ff = j;
                boundNegIdx.ss = j;
                negCount++;
            } 
        }
        if(zero_idx[i]+1==zero_idx[i+1]-1){
            currAns = a[zero_idx[i]+1];
        }
        else if(negCount&1){
            int case1Ans=1,case2Ans=1;
            for(int j=boundNegIdx.ff+1;j<=zero_idx[i+1]-1;j++){
                case1Ans *= a[j];
            }
            for(int j=zero_idx[i]+1;j<=boundNegIdx.ss-1;j++){
                case2Ans *= a[j];
            }
            //deb2(case1Ans,case2Ans);
            currAns = max(case1Ans,case2Ans);
        }
        else{
            for(int j=zero_idx[i]+1;j<=zero_idx[i+1]-1;j++){
                if(j==zero_idx[i]+1) currAns = 1;
                currAns *= a[j];
            }
        }
        ans = max(ans,currAns);
    }
    if(sz(zero_idx)>2 and ans<0) ans=0;
    cout<<ans<<endl;
}
/*
Description

Given an integer array nums ,find a contiguous non-empty subarray within the array
that has the largest product and return the product.

The test cases are generated so that the answer will fit in a 64-bit integer.

A subarray is a contiguous subsequence of the array.


Input Format

First-line contains T- the number of test cases.
The first line of each test case contains n - the size of the array.
The second line of each test case contains n elements of the array nums


Output Format

For each test case, print the maximum subarray product on a new line.

Constraints:
T => [1,100]
N => [1,1e5]
a[i] => [-10,10]

The test cases are generated so that the answer will fit in a 64-bit integer.
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
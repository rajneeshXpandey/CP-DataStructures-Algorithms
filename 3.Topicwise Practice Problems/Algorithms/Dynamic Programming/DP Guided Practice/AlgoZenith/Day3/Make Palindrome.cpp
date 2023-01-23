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
int dp[1001][1001];
int lcs(string &a, string &b, int i, int j)
{
    // base
    if (i == sz(a) or j == sz(b))
        return 0;

    // check
    if (dp[i][j] != -1)
        return dp[i][j];

    // transition
    int _lcs = 0;
    if (a[i] == b[j])
        _lcs = max(_lcs, 1 + lcs(a, b, i + 1, j + 1));
    _lcs = max(_lcs, lcs(a, b, i + 1, j));
    _lcs = max(_lcs, lcs(a, b, i, j + 1));

    // save and return
    return dp[i][j] = _lcs;
}
void solve()
{
    string s;
    cin >> s;
    int n = sz(s);
    string a = s,b=s;
    memset(dp, -1, sizeof(dp));
    reverse(all(b));
    //deb2(a,b);
    int _lcs = lcs(a, b,0, 0);
    int ans = (n - _lcs) ;
    cout << ans << endl;
    /*
        another solution :
        This question requires us to find the minimum number of insertions to create a palindrome from a given string.

        DP[i][j] => number of insertion needed from string S[j....i]

        Let's say you have the string: “xxa”

        xxa :   -> xxa_x
                -> a_xxa

                You can either insert a character at the beginning, 
                which will be the same character as the end, i.e “a”, or you can insert a character at the end, 
                which will be the same character as at the beginning, i.e “x”. If you add an “a” at the beginning, 
                then you have to see how many insertions are required to make “xx” a palindrome, otherwise, 
                if you add “x” at the end, you will need to calculate how many insertions are required to make “xa” a palindrome. 
                Hence, finding the answer for substrings, “xx”, and “xa”, are the smaller subproblems.
  */
}

/*
Description

Given a strings, find the minimum number of characters that need to be inserted into the string to make it a palindrome.

Input Format

First line contains T the number of test cases.
First line of each test case contains the strings.


Output Format

For each test case, output the minimum number of characters that need to be inserted into the string to make it a palindrome.


Constraints

1≤T≤100

1≤|s|≤1000
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
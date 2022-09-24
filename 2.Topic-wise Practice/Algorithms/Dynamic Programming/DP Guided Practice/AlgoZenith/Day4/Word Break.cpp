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
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
    string s;
    cin>>s;
    int sz = sz(s);
    vector<string> words(n);
    forn(i, n) 
        cin >> words[i];
    vector<bool> visi(sz,0);
    for(auto word: words){
        for(int i=0;i<sz;){
            if(s[i]==word[0]){
                int j=i,k=0;
                while(j<sz and k<sz(word) and s[j]==word[k]){
                    j++,k++;
                }
                if(k==sz(word)){
                    loop(z,i,i+k-1){
                        visi[z] = 1;
                    }
                    //i += sz(word);
                }
                //else
                //    i++;
            }
            //else 
            i++;
        }
        //L:
    }
    //printArr(visi);
    forn(i,sz){
        if(visi[i]==0){ 
            no;
            return;
        }
    }
    yes;
}
/*
Description

Given a string s and a dictionary of strings "words"
, output "Yes" if s can be segmented into a space-separated sequence of one or more dictionary
words, else output "No".

Note that the same word in the dictionary may be reused multiple times in the segmentation.


Input Format

First-line contains T - the number of test cases.
The first line of each test case contains n - the size of the dictionary
words
The second line of each test case contains string s.
The next n lines of each test case contain n words of the dictionary
words.

Output Format

For each test case, output "Yes" if
s can be segmented into a space-separated sequence of one or more dictionary
words, else output "No".


Constraints:
T => [1,1000]
N => [1,1000]
|s| => [1,300]
words.size() => [1,20]
Sum of |s| over all test cases is <= 30000
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
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define forn(i, n) rep(i, 0, n)
#define rof(i, n) per(i, n, 0)
#define forone(i, n) for (int i = 1; i <= (n); ++i)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define deb3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define ff first
#define ss second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define removeDuplicate(x) \
    sort(all(x));          \
    x.erase(unique(all(x)), x.end())       //remove Duplicate
#define setbits(x) __builtin_popcountll(x) // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007                                        //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI 3.141592653589793238
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define meminf(a) memset(a, 0x7f, sizeof(a))
#define precise(x, y) fixed << setprecision(y) << x
#define FastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
// #define oset  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
inline void printArr(vector<int> v)
{
    for (auto val : v)
        cout << val << ' ';
    cout << endl;
}

// *********************** Code Begins ************************ //

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    /*
    at position i =>
      fs : total substr ending at i and have Undecided hand as current writing hand 
      xs : total substr ending at i and have Xs hand as current writing hand
      os : total substr ending at i and have Os hand as current writing hand
      change : total substr ending at i have changed hand
      total : ans of all the substrings

        -----
          ---
            - |
        O X F O 
    
    int fs=0,xs=0,os=0,change=0,total=0;
    for(auto ch : str){
        if(ch=='F'){
            fs += 1;  
        }
        else if (ch == 'X'){
            xs += os+fs+1;
            change += os;
            os = fs = 0;
        }
        else if (ch == 'O'){
            os += xs + fs+1;
            change += xs;
            xs = fs = 0;
        }
        total = (total+change)%mod; 
    }
    cout<<total<<endl;
    */
    // -----------------------------------------------------------------------------------------
    /*
    Solution 2 :
        iterate through SS and identify all such pairs of letters
        (either an "X" followed by an "O", with only "F"s in between, or vice versa).
        For each such pair, if it involves letters at indices aa and bb in SS (such that a a<b), 
        then it effectively contributes an addition of 1 to the value of FF for 
        each substring of SS which includes the entire substring S_{a..b}
        (as each such substring would have a hand switch in between typing the pair's letters).
        There are (a+1)∗(∣S∣−b) such substrings, 
        meaning that such a pair contributes an addition of a∗(∣S∣−b+1) to G(S)
    */
    int a = -1, total = 0;
    forn(b,n){
        if (str[b] == 'F') continue;
        else if (a != -1 and str[a]!=str[b]){
            total = (total + (n - b) * (a+1)) % mod;
        }
        a = b;
    }
    cout << total << endl;
}

signed main()
{
    FastIO;

    freopen("weak_typing_chapter_2_input.txt", "r", stdin);
    freopen("A2_op.txt", "w", stdout);

    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
}
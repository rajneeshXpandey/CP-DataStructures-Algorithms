 #pragma GCC optimize ("O3")
 #pragma GCC target ("sse4")
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
#define pb push_back
#define pii pair<int, int>
#define removeDuplicate(x)   sort(all(x)); x.erase(unique(all(x)),x.end())   //remove Duplicate
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>

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
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// *********************** Code Begins ************************ //

int good(string &str,int st,int end,char ch){
  
    if(st==end-1){
        if(str[st]==ch)
         return 0;
        else 
         return 1; 
    }
    int x = (end+st)/2;

    int lchange = 0, rchange = 0;

    rep(i,st,x)
        if(str[i]!=ch) lchange++;

    rep(i,x,end)
        if(str[i]!=ch) rchange++;

    int lgood = good(str, st, x, ch+1);
    int rgood = good(str, x, end, ch+1);

    int change = min(rchange+lgood,lchange+rgood);

    return change;
}

void solve()
{  
    int n;
    cin>>n;
    string str;
    cin>>str;
    /*
    1 ≤ n ≤ 131072  =>  2^0 ≤ n ≤ 2^17 
    */
    if(n==1){
        cout<<((str=="a")?0:1)<<endl;
        return;
    }
    char ch = 'a';
    int ans = good(str, 0, n, ch);
    cout<<ans<<endl;
}

signed main()
{
    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
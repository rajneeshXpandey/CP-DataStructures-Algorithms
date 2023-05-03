#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#include "bits/stdc++.h"
using namespace std;

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>
//  using namespace __gnu_pbds;

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
#define binary_rep(n) bitset<20> (n); // binary representation of a number
#define min4(a,b,c,d) min({a, b, c, d}); // min of four elements
#define min3(a,b,c) min({a, b, c});
#define setbits(x) __builtin_popcountll(x)      // count set bits in binary rep
#define zerbefone(x) __builtin_ctzll(x)
#define pqb priority_queue<int>                               // maxheap
#define pqs priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqs priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define piipqb priority_queue<pii>                            // maxheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
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

    // find_by_order, order_of_key
    // #define pbds  tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

    mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

// mt19937_64 rng(61378913);
/* usage - just do rng() */

//assign and update min and max values.
template<typename T, typename T1> T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b) {if (b < a)a = b; return a;}

inline ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
inline void printArr(vector<int> v){for(auto val : v) cout<<val<<' '; cout<<endl;}

// *********************** Code Begins ************************ //
bool possible(unordered_map<char, int> &mp,int k){
    int len = 0;
    if(k%2){
    bool f = 1;
        for (auto ele : mp)
        {
            if (f and ele.ss==1){
                f = 0;
                len++;
            }
            else if (ele.ss % 2 == 0 and ele.ss >= 2)
            {
                len += ele.ss;
            }
            else if (ele.ss % 2 and ele.ss >= 2)
            {
                int x = ele.ss - 1;
                len += x;
            }
        }
        if(len>=k) return true;
    }
    else
    {
        for (auto ele : mp)
        {
            if (ele.ss % 2 == 0 and ele.ss >= 2)
            {
                len += ele.ss;
            }
            else if (ele.ss % 2 and ele.ss >= 2)
            {
                int x = ele.ss - 1;
                len += x;
            }
        }
        if (len >= k)
            return true;
    }

    return false;
}
int maxPal(unordered_map<char, int> &mp){
    int len = 0,len1=0;
    bool f = 1;
    for (auto ele : mp)
    {
        if (f and ele.ss == 1)
        {
            f = 0;
            len++;
        }
        else if (ele.ss % 2 == 0 and ele.ss >= 2)
        {
            len += ele.ss;
        }
        else if (ele.ss % 2 and ele.ss >= 2)
        {
            int x = ele.ss - 1;
            len += x;
        }
    }
    
        for (auto ele : mp)
        {
            if (ele.ss % 2 == 0 and ele.ss >= 2)
            {
                len1 += ele.ss;
            }
            else if (ele.ss % 2 and ele.ss >= 2)
            {
                int x = ele.ss - 1;
                len1 += x;
            }
        }
     return max(len,len1);   
}
void solve()
{
    int n,k;
    cin >> n >>k;
    string str;
    cin>>str;
    int l = 1, h = n;
    int ans = l;
    unordered_map<char,int> mp;
    for(auto ch :str) mp[ch]++;
    while(l<=h){
        int mid = (l+h)/2;
        if(possible(mp,mid)){
            ans = mid;
            l=mid+1;
        }
        else{
            h = mid-1;
        }
    }
    //deb(ans);
    //ans = ans/k;
    //if(ans==0) ans++;
    //cout<<ans<<endl;
     
    int len = maxPal(mp);
    ans = len / k;
    vector<int> poss(k,ans);
    int rem = len%k + n-len;
    for(int i=0;i<k;i++){
        if(poss[i]%2==0 and rem>0) poss[i]++, rem--;
    }
    sort(all(poss));
    cout << poss[0] << endl;
    //if(ans%2){
    //    cout << (ans - 1) / k << endl;
    //}
    //else{
    //    cout << (ans) / k << endl;
    //}
    
}

signed main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
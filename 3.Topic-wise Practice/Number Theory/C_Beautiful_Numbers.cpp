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

const int N = 1e6+1;
vector<int> fac(N);
int m = 1e9 + 7;

void pre() // call this func to precalculate
{
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = (fac[i - 1] * i)%m; // (a*b)%m = ((a%m)*(b%m))%m
}

int modexpo(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * a) % m;
        a = (a * a)%m;
        n /= 2;
    }
    return res;
}

int modinv(int a)
{
    return modexpo(a, m - 2);
}

int nCr(int n, int r)
{
    int numerator = fac[n],
        denominator = (fac[n - r] * fac[r])%m;   
    int modinv_denominator = modinv(denominator); // now modinv_denominator is the mod mult inverse
    int ncr = (numerator * modinv_denominator)%m;
    return ncr;
}

bool isGood(int a,int b,int sum){ // check by digits
    for(int num=sum;num>0;num/=10){
        int digit = num%10;
        if(digit!=a and digit!=b) 
            return false;
    }
    return true;
}

void solve()
{
    int a,b,n;
    cin >> a >> b >> n;
    int ans=0; 
    forn(i,n+1){
        int sum = a*i + (n-i)*b;
        if(isGood(a,b,sum)) 
         ans = (ans+nCr(n,i))%m;

    }
    cout<<ans<<endl;
    
}
/*
 => 1 3 3 : _ _ _
    111
    #(1)*1 + #(3)*3 = made up of 1 and 3
    x*a + (n-x)*b gives a number now check for digits

 => 2 3 10 : _ _ _ _ _ _ _ _ _ _
    x*2 + (10-x)*3 (x : 0,10)

    3333333333 => 30 = 0
    2333333333 => 29 = 0
    2233333333 => 28 = 0
    2223333333 => 27 = 0
    2222333333 => 26 = 0
    2222233333 => 25 = 0
    2222223333 => 24 = 0
    2222222333 => 23 = 10C7 or 10C3
    2222222233 => 22 = 0
    2222222223 => 21 = 0
    2222222222 => 20 = 0

    sum => max*n,max*(n-1)-min*1,......min*n
*/

signed main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    FastIO;
    pre();
    int tt = 1;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
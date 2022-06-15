#pragma GCC optimize("unroll-loops,O3,Ofast")

#include "bits/stdc++.h"
using namespace std;

#define loop(i, a, b)  for(int i = a; i <= b; i++)
#define rloop(i, a, b) for(int i = a; i >= b; i--)
#define forn(i, n) loop(i, 0, n-1)
#define forone(i, n) loop(i,1,n)
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
#define pqmx priority_queue<int>                               // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqmx priority_queue<pii>                            // maxheap for pair<int,int>
#define piipqmn priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define PI  3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

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
bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
}
// bool findPlease(vector<int> a,int target){
//     if(a[0]==target and a[1]==target and a[2]==target) 
//         return true;
//     if(a[2]==target and a[1]==target and a[0]!=target) {
//         int add = 0;
//         while(a[0]<target){
//             a[0]+=(1<<add);
//             add++;
//         } 
//         if(a[0]==target){
//             return 1;
//         }
//     }  
//     if(a[2]==target and a[1]!=target and a[0]!=target){
//         int sz = log2(target)+1;
//         for(int i=0;i<sz;i++){
//             if(target&(1<<i)){
//                 if(((a[0]&(1<<i)) and (a[1]&(1<<i))) || (!(a[0]&(1<<i)) and !(a[1]&(1<<i)))){
//                    break;
//                 }
//                 else if((a[0]&(1<<i))){
//                     a[1] += (1<<i);
//                 }
//                 else if((a[1]&(1<<i))){
//                     a[0] += (1<<i);
//                 }
//             }
//             else if(!(target&(1<<i))){
//                 if(((a[0]&(1<<i)) and (a[1]&(1<<i))) || (!(a[0]&(1<<i)) and !(a[1]&(1<<i)))){
//                     break;
//                 }
//                 else if(!(a[0]&(1<<i))){
//                     a[1] += (1<<i);
//                 }
//                 else if(!(a[1]&(1<<i))){
//                     a[0] += (1<<i);
//                 }
//             }
//             if(a[0]==target and a[1]==target){
//                 return 1;
//             }
//             // deb3(a[0],a[1],target);
//         }
//     }
//     else{
//         int sz = log2(target)+1;
//         for(int i=0;i<sz;i++){
//             if(target&(1<<i)){
//                 if((!(a[0]&(1<<i)) and (a[1]&(1<<i)) and (a[0]&(1<<i)))){
//                    a[0] += (1<<i);
//                 }
//                 else if(((a[0]&(1<<i)) and !(a[1]&(1<<i)) and (a[0]&(1<<i)))){
//                    a[1] += (1<<i);
//                 }
//                 else if(((a[0]&(1<<i)) and (a[1]&(1<<i)) and !(a[0]&(1<<i)))){
//                    a[2] += (1<<i);
//                 }
//                 else break;
//             }
//             else if(!(target&(1<<i))){
//                 if(((a[0]&(1<<i)) and !(a[1]&(1<<i)) and !(a[0]&(1<<i)))){
//                    a[0] += (1<<i);
//                 }
//                 else if((!(a[0]&(1<<i)) and (a[1]&(1<<i)) and !(a[0]&(1<<i)))){
//                    a[1] += (1<<i);
//                 }
//                 else if((!(a[0]&(1<<i)) and !(a[1]&(1<<i)) and (a[0]&(1<<i)))){
//                    a[2] += (1<<i);
//                 }
//                 else break;
//             }
//             if(a[0]==target and a[1]==target and a[2]==target){
//                 return 1;
//             }
//             // deb3(a[0],a[1],target);
//         }
//     }
//     return 0;
// }
void solve(){
    int n=3;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    // for(int target=a[2];target<=(a[2]+100);target++){
    //     if(findPlease(a,target)){
    //         cout<<"YES"<<endl;
    //         return;
    //     }
    // }
    for(int target=a[2];target<=10*a[2];target+=a[2]){
        int val1 = 3*target-a[2]-a[1]-a[0]+1;
        int val2 = val1+4;
        int val3 = val1-2;
        if(isPowerOfTwo(val1) or isPowerOfTwo(val2)){
            cout<<"YES"<<endl;
            return;
        }
        if(target!=a[2] and isPowerOfTwo(val3)){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    FastIO;
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        // cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
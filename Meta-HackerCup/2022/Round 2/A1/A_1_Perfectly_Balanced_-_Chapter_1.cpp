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

void solve(){
    string str;
    cin>>str;
    vector<vector<int>> data(26);
    int n=sz(str);
    forn(i,n){
        data[str[i]-'a'].pb(i);
    } 
    int q;
    cin >> q;
    int l,r;
    int ans=0;
    //forn(i,26){
    //    if(sz(data[i])){
    //        cout<<char(i+'a')<<' ';
    //        printArr(data[i]);
    //    }
    //}
    //return;
    while(q--){
        cin>>l>>r;
        l--,r--;
        if((r-l+1)&1){
            int odd=0,mid=l+(r-l+1)/2;
            bool ok=1;
            forn(i,26){
                if(data[i].size()==0) continue;
                int lidx = lower_bound(all(data[i]),l)-data[i].begin();
                int ridx = lower_bound(all(data[i]),r)-data[i].begin();

                if(lidx==sz(data[i])){
                    continue;};
                if (ridx == sz(data[i]))
                    ridx--;

                if(data[i][ridx]>r) ridx--;
                //deb4(mid,char(i+'a'),lidx,ridx);
                if(lidx>ridx or lidx<0 or ridx<0) continue;
                if(data[i][lidx]>=l and data[i][ridx]<=r){
                    int len = ridx-lidx+1;
                    if(len>=2 and len%2==0){ //even
                        int idx1=lidx+(len/2)-1 , idx2=idx1+1;
                        if (data[i][idx1] > mid or data[i][idx2] < mid)
                        {
                            ok=0;
                            break;
                        }
                    }
                    else if(len%2){ // odd
                        odd++;
                        if(odd>1){
                            ok=0;
                            break;
                        }
                        if(len==1){
                            continue;
                        }
                        int idx1 = lidx+(len / 2) - 1, idx2 = lidx+(len / 2) + 1;
                        if (data[i][idx1] > mid or data[i][idx2] < mid)
                        {
                            ok = 0;
                            break;
                        }
                    }

                }
                else{
                    continue;
                }
            }
            if(odd<=1 and ok){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

signed main(){
    FastIO;
    freopen("perfectly_balanced_chapter_1_input.txt", "r", stdin);
    freopen("perfectly_balanced_chapter_1_output.txt", "w", stdout);
    int total_testcases = 1;
    cin >> total_testcases;
    for (int test_case = 1; test_case <= total_testcases; test_case++){
        cout<<"Case #"<< test_case <<": ";
        solve();
    }        
}
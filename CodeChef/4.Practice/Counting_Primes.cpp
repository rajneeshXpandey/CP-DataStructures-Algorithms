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

// *********************** Code Begins ************************ //
int N = 1e7 + 5;
vector<int> Prefixcount(N, 0);
void buildSeive(){
   
    vector<bool> Prime(N, 1);
    Prime[0]=0;
    Prime[1]=0;
    for(int i=2;i*i<N;i++){
        for(int j=i*i;j<N;j+=i){
            if(Prime[i])
                    Prime[j] = 0;
        }
    }

    Prefixcount[0] = 0;
    Prefixcount[1] = 0;

    rep(i,2,N){
        if(Prime[i])
            Prefixcount[i] = 1+Prefixcount[i-1];
        else
            Prefixcount[i] = Prefixcount[i - 1];
    }
}
/**
0 1 1 0 1 0 1 0 0 0  1  0  1  0  0  0  1  0  1  0  0  0  1  0  0
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
*/
void solve()
{  
    int l,r;
    cin>>l>>r;
    cout<<Prefixcount[r]-Prefixcount[l-1]<<endl; 
}

signed main()
{
    FastIO;
    buildSeive();
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
        {            
         // cout<<"Case #"<< i <<": "; 
         solve();
        }        
}
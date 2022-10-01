
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

// *********************** Code Begins ************************ //

int bfs(unordered_map<char, vector<char>> &adj,char root,char target){

    unordered_map<char, bool> visi;
    queue<char> q;
    q.push(root);
    int dis = 0;
    //cout<<"------ ";
    while (!q.empty())
    {
        int sz = q.size();
        forn(i, sz)
        {
            char node = q.front();
            //cout<<node<<' ';
            if (node == target)
                return dis;
            visi[node] = 1;
            q.pop();
            for (auto nb : adj[node])
            {
                if(!visi.count(nb)) 
                    q.push(nb);
            }
       }
    //   cout<<'\n';
       dis++;
   }
   return 0;
}
void solve()
{
    string s,trans;
    cin>>s;
    int n = s.size();
    int k;
    cin >> k;
    unordered_map<char,vector<char>> adj;
    set<char> tar;
    for(auto ch : s)
     tar.insert(ch);
    forn(i, k)
      {
          cin>>trans;
          adj[trans[0]].pb(trans[1]);
          tar.insert(trans[1]);
     }
    
    int ans = INT_MAX;
    for(auto node : tar){
        //cout << node << ' ';
        int time = 0;
        bool imposs = false;
        for(auto ch :s){
            if(ch==node)
             continue;
            else{
                int t = bfs(adj,ch,node);
                 if(t)
                    time += t;
                 else{
                      imposs = true;
                      break;
                 }   
            } 
        }
    //   cout<<' '<<time<<endl; 
       if(!imposs)
         ans = min(ans,time); 
    }
    if(ans==INT_MAX)
        cout<<"-1"<<endl;
    else{
        cout<<ans<<endl;
    }
}

signed main()
{
    FastIO;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        cout<<"Case #"<< i <<": ";
        solve();
    }
}
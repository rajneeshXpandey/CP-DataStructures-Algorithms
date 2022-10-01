#include "bits/stdc++.h"
using namespace std;

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

// *********************** Code Begins ************************ //

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> mat(n,vector<char>(n));
    forn(i, n) 
      forn(j,n)
        cin >> mat[i][j];
     int ways = 0,minX = INT_MAX;   
     forn(i,n){
         bool good = true;
         int x = 0, empty = 0;
         forn(j,n){
             if(mat[i][j]=='O') {
                 good = false;
                 break;
             }
             else if (mat[i][j] == '.')
              empty++;
             else
              x++; 
         }
        if(good){
            minX = min(minX, empty);
        } 
     }
     forn(j, n)
     {
         bool good = true;
         int x = 0, empty = 0;
         forn(i, n)
         {
             if (mat[i][j] == 'O')
             {
                 good = false;
                 break;
             }
             else if (mat[i][j] == '.')
                 empty++;
             else
                 x++;
         }
         if (good)
             minX = min(minX,empty);   
     }
     set<set<pii>> st;

     forn(i, n)
        {
            bool good = true;
            int cnt = 0;
            set<pii> temp;
      forn(j, n)
          {
              if (mat[i][j] == 'O')
              {
                  good = false;
                  break;
              }
              else if (mat[i][j] == '.')
                 { cnt++;
                   temp.insert({i,j});
                 }
          }
          if(good and cnt==minX)
               st.insert(temp);
           
     }
     forn(j, n)
     {
         bool good = true;
         int cnt = 0;
         set<pii> temp;
         forn(i, n)
         {
             if (mat[i][j] == 'O')
             {
                 good = false;
                 break;
             }
             else if (mat[i][j] == '.')
             {    cnt++;
                 temp.insert({i, j});
             }
         }
         if (good and cnt == minX)
             st.insert(temp);
     }

     if (minX == INT_MAX)
     {
         cout<<"Impossible"<<endl;
         return;
     }
    cout << minX << ' ' << st.size() << endl;
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
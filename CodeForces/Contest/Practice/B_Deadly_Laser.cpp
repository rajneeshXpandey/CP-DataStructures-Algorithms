#pragma GCC optimize("unroll-loops,O3,Ofast")

#include "bits/stdc++.h"
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
#define mod 1000000007   //1e9+7
#define mod1 998244353
#define inf 2000000000000000000 //2e18
#define pi  3.141592653589793238
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define neg1 cout << "-1" << endl
#define precise(x, y) fixed << setprecision(y) << x // cout<<precise(value,uptodecimalpt)<<endl;

#define pqmx priority_queue<int>                               // maxheap
#define pqmn priority_queue<int, vector<int>, greater<int>>    // minheap
#define piipqmx priority_queue<pii>                            // maxheap for pair<int,int>
#define piipqmn priority_queue<pii, vector<pii>, greater<pii>> // minheap for pair<int,int>
#define ump unordered_map<int, int>

typedef tuple<int, int, int> tuplei;

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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs_laser(vector<vector<int>> &mat,int &x,int &y,int &d,int &n,int &m){
    queue<pii> q;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    q.push({x,y});
    vis[x][y] = 1;
    mat[x][y] = -1;
    while(!q.empty()){
        auto pts = q.front();
        q.pop();

        bool change = 0;
        forn(i,4){
            int xx = pts.ff+dx[i];
            int yy = pts.ss+dy[i];
            if(xx<n and xx>=0 and yy>=0 and yy<m and abs(x - xx) + abs(y - yy) <= d and !vis[xx][yy]){
                vis[xx][yy] = 1;
                mat[xx][yy] = -1;
                q.push({xx, yy});
                change = 1;
            }
    }
     if(!change) return; 
}
}
bool bfs_ans(vector<vector<int>> &mat, int x, int y, int &n, int &m){
    queue<pii> q;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    q.push({x, y});
    int mindis=0;
    while (!q.empty())
    {
        auto pts = q.front();
        vis[pts.ff][pts.ss] = 1;
        q.pop();
        forn(i, 4)
        {
            int xx = pts.ff + dx[i];
            int yy = pts.ss + dy[i];
            if (xx < n and xx >= 0 and yy >= 0 and yy < m and !vis[xx][yy] and mat[xx][yy] != -1)
            {
                mindis++;
                if(xx==n-1 and yy==m-1) return 1;
                q.push({xx, yy});
            }
        }
    }
    // forn(i,n){
    //    forn(j,m){
    //        cout<<mindis[i][j]<<' ';
    //    }
    //    cout<<endl;
    //}
    return 0;
}

void solve(){
    int n,m,x,y,d;
    cin>>n>>m>>x>>y>>d;
    //x--,y--;
    //vector<vector<int>> mat(n, vector<int>(m, 1));
    //bfs_laser(mat,x,y,d,n,m);
    //forn(i,n){
    //    forn(j,m){
    //        cout<<mat[i][j]<<' ';
    //    }
    //    cout<<endl;
    //}
    //bool poss = 1;
    //bool rposs = 1;
    //bool cposs = 1;
    //forn(i,n) if(mat[i][m-1]==-1) rposs=0;
    //forn(j,m) if(mat[n-1][j]==-1) cposs=0;
    //if(!rposs and !cposs) poss = 0;
    //int ans = n+m-2;
    //if (!bfs_ans(mat,0,0,n,m))
    //{
    //    cout<<"-1"<<endl;
    //}
    //else cout<<ans<<endl;
    if ((x - d > 1 && y + d < m) or (x + d < n && y - d > 1)){
            cout << n + m - 2 << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    //cout<<"haa"<<endl;
}

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
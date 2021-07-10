#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int,int> pii;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const int mod = 1'000'000'007;
//========================================
bool cmp1(pii a, pii b)
{
    return a.first < b.first;
}
bool cmp2(pii a, pii b)
{
    return a.second < b.second;
}

void solve() {
 int n,m;
 cin>>n>>m;
 int mat[n][m];
 int ans=1;

for (size_t i = 0; i < n; i++)
{   string st;
     cin>>st;
    for (size_t j = 0; j < m; j++)
    {
        if(st[j]=='1')
          mat[i][j]=1;
          else mat[i][j]=0;
    } 
}
// for (size_t i = 0; i < n; i++)
// {
//     for (size_t j = 0; j < m; j++)
//     {
//         cout<< mat[i][j]<<" ";
//     }
//     cout<<endl;
// }

int rmin, rmax,cmin, cmax;
vpii v;
for (size_t row = 0; row < n; row++)
{
        for (size_t col = 0; col < m; col++)
        {
            if(mat[row][col]==1)
               v.pb({row,col});
        }           
}

sort(v.begin(),v.end(),cmp1);
 rmin = v[0].first;
 rmax = v[v.size()-1].first;
 sort(v.begin(), v.end(), cmp2);
 cmin = v[0].second;
 cmax = v[v.size() - 1].second;
if((rmax-rmin+1)*(cmax-cmin+1)==v.size()) ans = 1;
else ans =0;
 if(ans)cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    //deb(t);
    while(t--) {
      solve();
    }
    return 0;
}



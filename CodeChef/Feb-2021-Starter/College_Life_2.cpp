#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

void solve() {
 int s;
 cin>>s;
 int q[s];
 ll time=0;
 for (int i = 0; i < s; i++)
    cin>>q[i];

 for (int i = 0; i < s; i++)
 {
     int e;
     cin>>e;
     int l[e];
     for (int j = 0; j < e; j++)
     {
         cin>>l[j];
     }
     time += l[0] ;
     for (int j = 1; j < e; j++)
     {
         time += l[j]-q[i];
     }
 }
 
 cout<<time<<endl;
 
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



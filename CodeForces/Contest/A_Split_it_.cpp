#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define int             long long
#define pb              push_back
#define pii             pair<int,int>
#define setbits(x)      __builtin_popcountll(x)
#define zerbefone(x)    __builtin_ctzll(x)
#define pqmx            priority_queue<int> // maxheap
#define pqmn   priority_queue<int,vector<int>,greater<int>> //minheap
#define mod             1000000007
#define inf             100000000000000000 //1e17
#define Pi              acos(-1.0)
#define precise(x,y)    fixed<<setprecision(y)<<x
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
       int n,k;
       cin>>n>>k;
       string s;
       cin >> s;
       if(k==0)
       {
           cout << "YES" << endl;
       }
       else if(2*k >= n)
       {
           cout << "NO" << endl;
       }
       else 
       {

           string revsk = s.substr(n-k, k);
           string sk = s.substr(0,k);
           reverse(revsk.begin(),revsk.end());
           //deb2(sk, revsk) ;
           if (revsk == sk)
               cout << "YES" << endl;
           else
               cout << "NO" << endl;
       }
    }
    return 0;
}
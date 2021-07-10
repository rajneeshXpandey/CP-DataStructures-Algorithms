#include<bits/stdc++.h>
using namespace std;

//    cout << fixed << setprecision(10);
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
       int n,m;
       cin>>n>>m;
       int arr[n];
       map<int, int> mp;
       for (int i = 0; i < n; i++)
       {
           cin>>arr[i];
           arr[i] = arr[i]%m;
           mp[arr[i]]++;
       }
       int ans = 0;
       for(auto x : mp)
        {
           // cout<<x.ff<<" "<<x.ss<<endl;
            if(x.ff==0)
              ans++;
            else if (x.ss > 0)
            {
                if (mp.find(m - x.ff) == mp.end())
                {
                    ans += x.ss;
                 }
                 else if (x.ss > 0 and mp[m - (x.ff)]>0)
                 {
                     if (abs(x.ss - (mp[m - (x.ff)])) <= 1)
                         ans++;
                     else
                     {
                         ans += abs(x.ss - (mp[m - (x.ff)]));
                         //deb(x.ss - (mp[m - (x.ff)]));
                     }
                     mp[(m - (x.ff))] = 0;
                 }
            }
            mp[x.ff] = 0;
                }
                cout << ans << endl;
    }
    return 0;
}
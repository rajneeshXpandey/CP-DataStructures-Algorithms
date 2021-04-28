// rajneesh_1708 : Rajneesh Pandey
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
       int n;
       cin>>n;
       vector<int> ans;
       int p = 1;
       for (int i = 1; i<n; i++)
       {
           if(__gcd(i,n)==1)
             {
                 ans.pb(i);
                 p = (p*i)%n;
             }
       }
        if(p!=1)
        {
            cout << ans.size()-1 << endl;
            for (auto x : ans)
            {
                if(x!=(n-1))
                cout << x << " ";
            }
        }
        else{
            cout << ans.size() << endl;
            for (auto x : ans)
            {
                cout << x << " ";
            }
        }
        
       cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define all(x)          (x).begin(), (x).end()
#define int             long long
#define endl            "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
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
    cout << fixed << setprecision(10);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin>>n;
        vector<int> mine,dim;
        for(int i=0;i<(n*2);i++)
        {
            int x,y;
            cin>>x>>y;
            if(x==0) mine.pb(abs(y));
            else if(y==0) dim.pb(abs(x));
        }
        sort(all(dim));
        sort(all(mine));
        long double min_energy=0;

         for (int i = 0; i < n; i++)
        {
            min_energy += sqrt((dim[i] * dim[i]) + (mine[i] * mine[i]));
        }
        cout<<min_energy<<endl;
    }
    return 0;
}
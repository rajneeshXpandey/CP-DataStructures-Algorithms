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
       int n;cin>>n;
       int arr[n];
       for (int i = 0; i < n; i++)
       {
           cin>>arr[i];
       }
       if(n==2)
         {
             cout<<1<<endl;
             continue;
         }

         vector<int> v;
         v.pb(0);v.pb(1);
         int dist = 1;
         int s = v.size();
         for (int i = 2; i < n; i++)
         {
             while (v.size()>=2)
             {
double curr_slope = (double)((double)(arr[i] - arr[v[s - 1]]) / (double)(i - v[s - 1]));
double prev_slope = (double)((double)(arr[v[s - 1]] - arr[v[s - 2]])/(double)(v[s - 1] - v[s - 2]));
      //deb2(curr_slope,prev_slope);
                 if (curr_slope >= prev_slope)
                 {
                     v.pop_back();
                     s--;
                 }
                 else
                     break;
             }
            v.pb(i);
            s++;
            dist = max(dist,v[s-1]-v[s-2]);
       }

       cout<<dist<<endl;
        
    }
    return 0;
}
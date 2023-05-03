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
       int n;
       cin>>n;
       int arr[n]; 
      
       for (int i = 0; i < n; i++)
       {
           cin>>arr[i]; 
        }

        sort(arr,arr+n);
        int count=0,ok=0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<=(i+1))
               count +=(i+1)-arr[i];
            else {
                ok=1;
            }  
        }
        if(ok)
         {
             cout << "Second" << endl;
         }
        else{if(count%2 == 1)
         cout<<"First"<<endl;
        else 
          cout<<"Second"<<endl; }       
    }
    return 0;
}
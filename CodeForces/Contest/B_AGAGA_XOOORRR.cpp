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
       int prexor[n];
       prexor[0]=arr[0];
       for (int i = 1; i < n; i++)
       {
           prexor[i] = (arr[i]^prexor[i-1]);
       }
     // if the answer is yes then the final array will contain 2 or 3 elements
    //for 2 : xor of all the array == 0
    int flag = 0;
    if(prexor[n-1]==0)
     flag = 1;
    // for 3 : xor of three parts should be equal at any time 
    if(!flag)
    {
        int st,mid,end;
      for (int i = 0; i <= n-3; i++)
        {
            st = prexor[i];
            for (int j = i+1; j <= n-2; j++)
            {
                mid = (prexor[j]^st);

                end = (prexor[n-1]^prexor[j]);

                if(st == mid and mid == end and end == st)
                 {
                     flag = 1;
                     break;
                 }

            }
            if(flag)
              break;   
        }  
    }

    if(flag)
     cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;  
    }
    return 0;
}
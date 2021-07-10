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

int count(int n)
{
    int count = 0;
    if(n==0)
       return 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
      int n;
      cin>>n;
      int ans = 0;
      if (count(n) <= 3)
      {
          cout << "-1" << endl;
          continue;
      }
       
      while (n >= 2050)
       {
           
           int x = (count(n) - 4);
           
           int num = 2050 * pow(10, x);
           while(num>n)
             num = num/10;
            n = n - num;
        //    deb2(n,num);
           ans++;
       }
     if(n==0)
      {
          cout<<ans<<endl;
      }
      else{
          cout<<"-1"<<endl;
      }     
       
    }
    return 0;
}
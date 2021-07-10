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
      int n,e,h,a,b,c;
      cin>>n>>e>>h>>a>>b>>c;
      int price = inf;
      for (int i = 0; i <=n ; i++)
      {
          if(e<i or h<i)
            break;
          int cost = i*c;
          int friendLeft = n-i;
          int eggLeft = e-i;
          int barLeft = h-i;
          if(a>=b)
          {
            int bars = min(friendLeft,(barLeft/3));
            cost += bars*b;
            friendLeft -= bars;
            if(friendLeft > (eggLeft/2))
             continue;
            cost += friendLeft*a;
            price = min(price,cost);  
          }
          else{
              int eggs = min(friendLeft,(eggLeft/2));
              cost  += eggs*a;
              friendLeft -= eggs;
              if(friendLeft > (barLeft/3))
               continue;
              cost += friendLeft*b;
              price = min(price,cost);  
          }    
      }
      if(price == inf)
       cout<<-1<<endl;
      else
      {
           cout<<price<<endl;
      }
       
        
    }
    return 0;
}
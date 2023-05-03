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
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      int i=0,j=n-1;
      int c = 0;
      for (int i = 0; i < n; i++)
      {
          if(s[i]=='*')c++;
      }
      if(c==1)
       {cout<<1<<endl;
      continue;}
      // if(c>1)
      int st = 0, en = n - 1;
      bool flag1 = 1, flag2 = 1;
      while(i<n and j>=0)
       {
           if(s[i]=='*' and flag1) 
                {
                    st = i;
                    flag1=0;
                }
           if (s[j] == '*' and flag2)
                {
                    en = j;
                    flag2 = 0;
                }
            i++;
            j--;            
       }
       //deb2(st,en);
       int mn = 0;
       int a=st;
       for (a = st; a<=en; a+=k)
       {
           if(s[a]=='*')
            mn++;
           else
           {
               while (s[a] != '*' and a>st)
                   a--;

               mn++;
           }
       }
       if(a-k!=en) mn++;
       cout<<mn<<endl;
           
    }
    return 0;
}
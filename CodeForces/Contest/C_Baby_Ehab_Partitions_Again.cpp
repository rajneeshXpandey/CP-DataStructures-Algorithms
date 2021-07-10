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
      int sum = 0;
      int arr[n];
      for (int i = 0; i < n; i++)
      {
          cin >> arr[i];
          sum += arr[i];
      }

     if(sum%2)
       {
           cout<<0<<endl;
       }
      else
      {
          sum = sum/2;
          int dp[n+1][sum+1];
          for (int i = 0; i <= n; i++)
          {
              for (int j = 0; j <= sum; j++)
              {
                  if (i == 0)
                      dp[i][j] = 0;
                  if(j==0)
                      dp[i][j] = 1;
                 
              }
          }
          for (int i = 1; i <= n; i++)
          {
              for (int j = 1; j <= sum; j++)
              {
                  if(arr[i-1]>j)
                      dp[i][j] = dp[i-1][j];
                   else{
                    dp[i][j] = (dp[i - 1][j - arr[i-1]] || dp[i - 1][j]);
                   }    
              }
          }

          if(dp[n][sum]==1)
           {
             int ans = -1;
             bool flag = 0;
             while (1)
             {
                 for (int i = 0; i < n; i++)
                 {
                     if (arr[i] % 2)
                     {
                         ans = i + 1;
                         flag = 1;
                         break;
                     }
                     else{
                         arr[i] = (arr[i]>>1);
                     }
                 }

                 if(flag)
                  break;
             }
             
             
             if(ans!=-1)
              {
                  cout<<1<<endl;
                  cout<<ans<<endl;
              }
             else{
                cout<<0<<endl;
             }            
           }
          else
          {
              cout<<0<<endl;
          }
      }
    return 0;
}
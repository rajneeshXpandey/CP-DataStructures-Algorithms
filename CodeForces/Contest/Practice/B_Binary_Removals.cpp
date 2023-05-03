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

bool isSorted(int arr[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
         return false;
    }
    
   return true;
}

bool leftone(int arr[],int n,int idx)
{
    for(int i = idx-1; i>=0; i--) {
      if (arr[i]==1)
                 return true;
         }
       return false  ;
}

bool conseOne(int arr[],int n,int idx)
{
    for (int i = idx-1; i > 0; i--)
    {
        if (arr[i] == 1 and arr[i - 1] == 1)
        {
          return true;
        }
    }
    return false;
}

signed main()
{
    FIO;
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        string s;
        cin>>s;
        int n = s.size();
        bool ok = true;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='1') arr[i]=1;
              else arr[i]= 0;
        }
        if(isSorted(arr,n))
         { cout<<"YES"<<endl;
          continue;}
        for (int i = n-1; i >0; i--)
        {
            if(arr[i]==0 and arr[i-1]==0)
              {                 
                  if(i-2 >= 0 and leftone(arr,n,i-1))
                   {
                       if (i - 2 >= 0 and conseOne(arr, n, i - 1))
                            ok = false;
                   }
 
              }
         }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;  
        
    }
    return 0;
}
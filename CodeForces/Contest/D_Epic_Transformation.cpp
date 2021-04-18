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
       map<int,int> mp;
       for (int i = 0; i < n; i++)
       {
           int x;
           cin>>x;
           mp[x]++;
       }
       priority_queue<pii> mxheap;
       for(auto it : mp)
       {
           mxheap.push({it.second,it.first});
       } 
       int num = n;
       while(mxheap.size()>=2)
       {
           pii a = mxheap.top();
           mxheap.pop();
           pii b = mxheap.top();
           mxheap.pop();
           a.first--;
           b.first--;
           num -= 2;
           if(a.first)
            mxheap.push(a);
           if(b.first)
            mxheap.push(b);
       }
       cout<<num<<endl;

        }
    return 0;
}
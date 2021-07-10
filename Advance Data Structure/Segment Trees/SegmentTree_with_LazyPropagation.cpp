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

int SegTree[1000];
int Lazy[1000] = {0};
int arr[5] = {2, 4, 1, 6, 7};

void buildTree(int s,int e,int idx){
    
    if(s == e)
    {
        //deb(arr[s]);
        SegTree[idx]=arr[s];
        //deb(SegTree[s]);
        return ;
    }

    int mid = (s+e)/2;
    buildTree(s,mid,2*idx+1);
    buildTree(mid+1,e,2*idx+2);

    SegTree[idx] = max(SegTree[2 * idx + 1], SegTree[2 * idx + 2]);
}

void incrementQuery(int us,int ue,int s,int e,int idx,int x)
{
    // need to propagate
    if(Lazy[idx] !=0)
    {
       SegTree[idx] += Lazy[idx];
        if(s!=e)
        {
            Lazy[2 * idx + 1] += x;
            Lazy[2 * idx + 2] += x;
        }
       Lazy[idx]=0;
    }
    //no overlap
     if(us>e or ue<s)
       return;
    //complete overlap
    if(us<=s and ue>=e)
      {
          SegTree[idx] += x;
          if(s!=e)
           {
               Lazy[2*idx+1] += x;
               Lazy[2 * idx + 2] += x;
           }
           return;
      }
    //partial overlap
      int mid = (s+e)/2;
      incrementQuery(us, ue, s, mid, 2 * idx + 1, x);
      incrementQuery(us, ue, mid + 1, e, 2 * idx + 1+1, x);

      SegTree[idx] = max(SegTree[2 * idx + 1], SegTree[2 * idx + 2]);
}
int getMaxQuery(int qs,int qe,int s,int e,int idx)
{
         if(Lazy[idx]!=0)
          {
              {
                  SegTree[idx] += Lazy[idx];
                  if (s != e)
                  {
                      Lazy[2 * idx + 1] += Lazy[idx];
                      Lazy[2 * idx + 2] += Lazy[idx];
                  }
                  Lazy[idx] = 0;
              }
          }

          if (qs > e or qe < s)
              return 0;
          //complete overlap
          if (qs <= s and qe >= e)
          {
            return SegTree[idx];
          }
          //partial overlap
          int mid = (s + e) / 2;
          getMaxQuery(qs, qe, s, mid, 2 * idx + 1);
          getMaxQuery(qs, qe, mid + 1, e, 2 * idx + 1+1);

          return max(SegTree[2 * idx + 1], SegTree[2 * idx + 2]);
}
signed main()
{
    FIO;
    int n= 5;
    buildTree(0, n - 1, 0);
    for (int i = 0; i < n*2+3; i++)
    {
        cout << SegTree[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n * 2+3; i++)
    {
        cout << Lazy[i] << " ";
    }
    cout << endl;
    cout<<getMaxQuery(3,4,0,n-1,0)<<endl;
    incrementQuery(3,4,0,n-1,0,4);
    cout << getMaxQuery(3, 4, 0, n - 1, 0) << endl;
    for (int i = 0; i < n * 2 + 3; i++)
    {
        cout << SegTree[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n * 2 + 3; i++)
    {
        cout << Lazy[i] << " ";
    }
    cout << endl;

    return 0;
}
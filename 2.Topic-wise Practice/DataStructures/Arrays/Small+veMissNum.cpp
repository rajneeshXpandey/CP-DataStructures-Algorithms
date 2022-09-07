#include <bits/stdc++.h>
using namespace std;

void solve(int a[],int s)
{
    const int N = 1e6+2;
    bool check[N];
    for(int i=0;i<N;i++)
      {
          check[i] = false;
      }
    for(int i=0;i<s;i++)
    {
        if(a[i]>=0)
          check[a[i]]=true;
    }
    int ans =-1;
    for(int i=1;i<N;i++)
    {
        if(check[i]==false)
          {ans = i;
          break;}
    }

    cout << ans << endl;
}

int main()
{

    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve(array,n);
    }

    return 0;
}

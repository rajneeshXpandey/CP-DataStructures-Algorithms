#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    string ans = "";
    s.erase(remove(s.begin(),s.end(),'+'),s.end());
    int n = s.size();
    int a[n];
    for(int i=0;i<n;i++) 
    {
        a[i] = s[i]-'0';
    }
    sort(a,a+n);
   for(int i=0;i<n;i++) 
    {
        ans = ans + "+" + to_string(a[i]);
    }
  for(int i=1;i<ans.size();i++) 
    {
        cout<<ans[i];
    }
    

    return 0;
}
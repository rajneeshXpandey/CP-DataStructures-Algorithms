#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> w(n);
        rep(i,n) cin>>w[i];
        vector<int> l(n);
        rep(i, n) cin >> l[i];

       if(n==2)
       {
          int ans=0;
          if(w[0]==2 and l[0]==1)
          ans+=2;
          else if (w[0] == 2 and l[0] >1)
          ans++;

          cout << ans << endl;   
          
       } 
       if(n==3)
       {
           int a,a1, b,b1, c,c1;
           int ans=0;
           for (int i = 0; i < n; i++)
           {
               if (w[i] == 1)
                   {a = i; a1 = i;}
               else if (w[i] == 2)
                  { b = i; b1=i;}
               else
                  { c = i; c1 =i;}
           }
           while (b <= a)
           {
               b += l[b1];
               ans++;
           }
           while (c <= b or c <= a)
           {
               c += l[c1];
               ans++;
           }
          cout<<ans<<endl; 
           }
        if (n == 4)
           {
               int ans = 0;
               int a, a1, b, b1, c, c1,d,d1;
               for (int i = 0; i < n; i++)
               {
                   if (w[i] == 1)
                   {
                       a = i;
                       a1 = i;
                   }
                   else if (w[i] == 2)
                   {
                       b = i;
                       b1 = i;
                   }
                   else if (w[i] == 3)
                   {
                       c = i;
                       c1 = i;
                   }
                   else
                       {d = i; d1=i;}
               }

               while (b <= a)
               {
                   b += l[b1];
                   ans++;
               }
               while (c <= b or c<=a)
               {
                   c += l[c1];
                   ans++;
               }
               while (d <= c or d<=b or d<=a)
               {
                   d += l[d1];
                   ans++;
               }

               cout << ans << endl;
           }   
    }
    return 0;
}
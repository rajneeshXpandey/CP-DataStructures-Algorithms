#include <bits/stdc++.h>

using namespace std;



int main() {
    int tc ;
     cin >> tc;
    for (int t = 1; t <= tc; t++) {
      int cost;
      int n;
      cin>>n;
      int s[n],p[n],v[n];
      int max = -1;
      for(int i=0;i<n;i++)
      {
          cin>>s[i];
          cin>>p[i];
          cin>>v[i];
     cost  = (p[i]/(s[i]+1))*v[i];
       if(cost > max)
           max = cost;
          
      }

      cout<<max<<endl;
      
    }
}
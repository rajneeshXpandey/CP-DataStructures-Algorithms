#include <bits/stdc++.h>

using namespace std;


int main() {

    int tc = 1;
     cin >> tc;
    for (int t = 1; t <= tc; t++) {
         int k;
         cin>>k;
         int n = 2*k;
         char a[n];
         for(int i=0;i<n;i++)
           cin>>a[i];

         int bleft = k;
         int aleft = k;
         int sa = 0,sb =0;
   
        for(int i=0;i<n;i++)
        {
          if(i%2 == 0)
             {
                 if(a[i] == '1')sa++;
                 aleft--;
             }
          else
           {  if(a[i] == '1')sb++;
                bleft--;
         }

          if((sa-sb)>bleft)
            {
             cout<<i+1<<endl;
            break;
            }
          else if((sb-sa)>aleft)
            {
             cout<<i+1<<endl; 
            break;
            }
          else if(sa == sb && i == n-1)
           {cout<<i+1<<endl;
           break; 
            }       
        
        }
    }
    return 0;
}
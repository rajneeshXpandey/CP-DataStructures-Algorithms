#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int tc = 1;
     cin >> tc;
    for (int t = 1; t <= tc; t++) {
        int n;
        cin>>n;
        int a[n];
        for (size_t i = 0; i < n; i++)
        {
            cin>>a[i];
        }
   
    long long int min = a[0];
    long long int ans[n];
      for (size_t i = 0; i < n; i++)
        {
            if(a[i]<min)
              { 
                  min = a[i];          
              }
           ans[i] = min;  
        }
     long long int sum = 0;
      for(int i=0;i<n;i++){
          sum += ans[i];
      }
         cout<<sum<<endl;       

    }
}
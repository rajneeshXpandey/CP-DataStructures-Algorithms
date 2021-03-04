#include <bits/stdc++.h>

using namespace std;

int main() {


    int tc = 1;
    //  cin >> tc;
    for (int t = 1; t <= tc; t++) {
       int a,b;
       cin>>a>>b;
        int years=0;  
          while(a<=b)
          { 
              a *= 3;
              b *= 2;
              years++;
          }  
        cout<<years;
         
    }
}
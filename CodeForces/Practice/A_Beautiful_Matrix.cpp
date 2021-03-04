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
  
       int matrix[6][6];
       pair<int,int> p;
       for (size_t i = 1; i <= 5; i++)
       {
           for (size_t j = 1; j <= 5; j++)
           {
              cin>>matrix[i][j];
           }
       }
       for (size_t i = 1; i<=5; i++)
       {
           for (size_t j = 1; j <=5; j++)
           {
               if(matrix[i][j])
             {  p.first = i;
                p.second = j;
                  break;}
           }
           
       }      
        cout<<abs(p.first-3)+abs(p.second-3)<<endl;
  
    return 0;
}
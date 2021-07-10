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
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        ll x,y;
        cin>>n>>k>>x>>y;

       if(x == y)
        cout<<n<<" "<<n<<endl;
      else{
           pair<int,int> firstcoll;
           pair<int, int> secondcoll;
           pair<int, int> thirdcoll;
           pair<int, int> fourthcoll;

           firstcoll.first = x + min(n - x, n - y);
           firstcoll.second = y + min(n - x, n - y);

           secondcoll.first = firstcoll.second;
           secondcoll.second = firstcoll.first;

           thirdcoll.first = n - firstcoll.first;
           thirdcoll.second = n - firstcoll.second;

           fourthcoll.first = thirdcoll.second;
           fourthcoll.second = thirdcoll.first;

               if(k%4 == 1)
                   cout << firstcoll.first<<" "<<firstcoll.second<<endl;
               else if(k%4==2)
                   cout << secondcoll.first << " " << secondcoll.second << endl;
               else if (k % 4 == 3)
                   cout << thirdcoll.first << " " << thirdcoll.second << endl;
               else if (k % 4 == 0)
                   cout << fourthcoll.first << " " << fourthcoll.second << endl;
        
      }
    
    }
    return 0;
}
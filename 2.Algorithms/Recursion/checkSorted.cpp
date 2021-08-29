#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

bool checkSort (int a[],int n)
{
    //Base Case
    if(n==1)
      return true;
    // Intuition 
    bool isSort = checkSort(a+1,n-1);
    // work
    return (a[0] < a[1] and isSort);
       
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
        int a[]={1,5,3,8,7};

        cout<<checkSort(a,5);   
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
// number of sub arrays == (nC2 + n)

void recordDay(int a[],int n)
{
    //base case
  if(n==1)
    {
        cout<<"1"<<" ";
        return;
    }

    int max = a[0];
    int ans = 0;
    //corner
    if(a[0]>a[1])
      ans++;
    for (size_t i = 1; i < n-1; i++)
    {
        if(a[i]>a[i+1] and a[i]>max)
          {
            max = a[i];
            ans++;
           }   
    }
    //corner
    if(a[n-1]>max)
      ans++;
      cout<<ans<<" ";
    cout<<endl;
}
int main()
{

    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    recordDay(array, n);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
// number of sub arrays == (nC2 + n)

void LongAPSubArray(int a[], int n)
{
    int prevdiff = a[1]-a[0];
     int subl = 2;
     int ans = 2;

    for (size_t i = 1; i < n-1; i++)
    {
        
        if(prevdiff == a[i+1]-a[i])
           subl++;
        else
            {
              prevdiff = a[i] - a[i + 1];             
              subl=2;
            }
     ans = max(ans, subl);
    }

   cout<<ans<<endl;

}
int main()
{

    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    LongAPSubArray(array, n);

    return 0;
}

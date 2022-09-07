// Algos/Approaches:
// i. Brute Force :O(n^3)
 //               find sum of every possible subarray 
//                and find max sum

// ii. Cumulative Sum approach  O(n^2)
//           : create extra array for sum of value till index of new array
//             to get ans use subtraction

// iii . Kadane's Algorithm: O(n)
//          keep currsum var(change it to zero if becomes <0) and also maxsum variable


#include <bits/stdc++.h>
using namespace std;

void Kadanes(int a[], int n){
      
      int currsum = 0;
      int max_sum = a[0];

      for(int i=0;i<n;i++)
      {
         currsum += a[i];

         if (currsum < 0)
             currsum = 0;

         if (max_sum < currsum)
             max_sum = currsum;   
      }

      cout<<max_sum<<endl;
      
}

    void Cumulative(int a[], int n)
{
    int cumSum[n+1];
    cumSum[0] = 0;
    for(int i=1;i<=n;i++)
    {
         cumSum[i] = cumSum[i-1]+a[i-1];         
    }

    int maxsum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j<i; j++)
        {
            if(maxsum < cumSum[i]-cumSum[j])
                maxsum = cumSum[i] - cumSum[j];
        }
    }

    cout<<maxsum<<endl;
}

int main()
{

    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
        cin >> array[i];

    int t = 1;
    //cin>>t;
    while (t--)
    {
        Cumulative(array,n);
        Kadanes(array,n);
    }

    return 0;
}

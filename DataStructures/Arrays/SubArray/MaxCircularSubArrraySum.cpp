// iii . Kadane's Algorithm: O(n)
//          keep currsum var(change it to zero if becomes <0) and also maxsum variable

#include <bits/stdc++.h>
using namespace std;

int Kadanes(int a[], int n)
{

    int currsum = 0;
    int max_sum = a[0];

    for (int i = 0; i < n; i++)
    {
        currsum += a[i];

        if (currsum < 0)
            currsum = 0;

        if (max_sum < currsum)
            max_sum = currsum;
    }

    return max_sum;
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
        int wrapsum = 0;
        int nonwrapsum = 0;

       nonwrapsum =  Kadanes(array, n);

      int  totalsum = 0;

       for(int i=0;i<n;i++){
          totalsum += array[i];
          array[i] = -array[i]; 
       }

       wrapsum = totalsum - (-Kadanes(array,n));

       cout<<max(wrapsum,nonwrapsum)<<endl;
    }

    return 0;
}

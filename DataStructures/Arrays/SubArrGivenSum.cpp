// Two Pointer Approach:
//   use when have to find something that equals target 


#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n,s;
    cin >> n >> s;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];


    int sum = 0;
    int i =0,j=0,st = -1,en = -1;

    while(j<n)
    {
        sum += a[j];

        while(sum>s)
        {
           sum -= a[i];
           i++;
        }
        if(sum == s)
           {
               st = i+1;
               en = j+1;
               break;
           }        
       j++; 
    }

    cout << st<< " " << en<< endl;
    return 0;
}

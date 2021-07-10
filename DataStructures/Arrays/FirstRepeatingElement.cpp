#include <bits/stdc++.h>

using namespace std;


int main()
{

    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    

    int S = 10;

    int idx[S];

    for (int j = 0; j < S; j++)
    {
        idx[j] = -1;
    }

    int min_index = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (idx[a[i]] != -1)
            min_index = min(min_index, idx[a[i]]);
        else            
            idx[a[i]] = i;
    }

   if(min_index == INT_MAX)
     cout<<"-1"<<endl;
    else 
    cout << min_index+1 << endl;

    return 0;
}

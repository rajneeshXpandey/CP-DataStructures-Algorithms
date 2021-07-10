#include <bits/stdc++.h>
using namespace std;
//Brute force approach: LInear search

//Must be sorted
//Optimized Approach:
//   --  --  <X   (X)          () start from here
//   --  --  --  >X
//   --  --  --  --
//   (--)  --  --  --

void solve()
{
    int n,m;
    cin >> n>>m;
    int key;
    cin >> key;
    int array[n][m];

    for (int j = 0; j < n; j++)
    {
        {
            for (int i = 0; i < m; i++)
                cin >> array[j][i];
        }
    }

    int row = 0;
    int col = m - 1;
    bool found = false;
    while(row<n and col>=0)
        {
            if(array[row][col] ==key )
              { 
                  found = true;
                  break;
              }
            else if (array[row][col] > key)
              col--;
            else
              row++;             
        }
            
       cout<<found<<endl;
     
}


int main()
{

    int t = 1;
    //cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}

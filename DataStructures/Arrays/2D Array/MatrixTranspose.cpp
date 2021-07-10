#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n=0;
    cin>>n;
    int matrix[n][n];
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin>>matrix[i][j];
        }
        
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
           // if (i < j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            
           cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
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

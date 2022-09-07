#include <bits/stdc++.h>
using namespace std;


int main()
{
    int p =3, q=4, r=3;

    int arr[p][q] = {
        {2,4,1,2},
        {8,4,3,6},
        {1,7,9,5}
        };
    int mat[q][r] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {4,5,6}
    };
    int ans[p][r]; 

    for (int x = 0; x < p; x++)
        for (int y = 0; y < r; y++)
          { ans[x][y]=0;
            for (int k = 0; k < q; k++)
                ans[x][y] += arr[x][k] * mat[k][y];
          }
    for (int a = 0; a < p; a++)
    {
        for (int b = 0; b < r; b++)
        {
            cout << ans[a][b] << " ";
        }
        cout << endl;
    }
    return 0;
}

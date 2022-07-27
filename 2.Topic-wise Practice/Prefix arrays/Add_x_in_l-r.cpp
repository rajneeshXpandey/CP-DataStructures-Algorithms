/*
You are given an array of n numbers and q number of queries,
in each query you will be given 3 integers “l”,”r”,”x” and
do an operation of adding the number x to each element between index “l” to “r”.
After all the q operations what would be the final array?

    A[10] = {0,0,0,0,0,0,0,0,0,0}
    Q queries -> l r x
    l=3,r=7,x=5
    1<=n<=10^5 , 1<=q<=10^5
    l=2 r= 4 ,x=3
********************************
  arr    = {0,0,0,5,0,0,0,0,-5,0}
         = {0,0,3,5,0,-3,0,0,-5,0}
         = {0,0,3,8,8,5,5,5,0,0}


*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    int q;
    cin >> q;
    while (q--)
    { //->for(int i=1;i<=q;i++)
        int l, r, x;
        cin >> l >> r >> x;
        a[l] += x; // l=0,r=n-1;
        a[r + 1] -= x;
    }
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
}

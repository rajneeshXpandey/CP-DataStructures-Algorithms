#include <bits/stdc++.h>
using namespace std;

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x;
    cin>>x;
    for (int i = 0; i < 5; i++)
    {
        x += i;
    } 
    cout << x << '\n';
    return 0;
}

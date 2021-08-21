
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int sum(int n)
{
    int s = 0, x = 0;
    if ((n % 2) != 0)
    {
        x = (n + 1) / 2;
        s = (n % mod * x % mod) % mod;
    }
    else
    {
        x = n / 2;
        s = (x % mod * (n + 1) % mod) % mod;
    }
    return s;
}

int sqsum(int n)
{
    int x = 0, s = 0;

    if (n * (n + 1) % 6 == 0)
    {
        x = (n * (n + 1)) / 6;
        s = (x % mod * (2 * n + 1) % mod) % mod;
    }
    else if (n * ((2 * n) + 1) % 6 == 0)
    {
        x = (n * (2 * n + 1)) / 6;
        s = (x % mod * (n + 1) % mod) % mod;
    }
    else
    {
        x = ((n + 1) * (2 * n + 1)) / 6;
        s = (x % mod * n % mod) % mod;
    }

    return s;
}

#include <bits/stdc++.h>
using namespace std;
#define ll int
// func is to calculate sum of digit of number a in base b 

ll func(int a, int b)
{
    int unitDigit,s = 0;
    while (a > 0)
    {
        unitDigit = (a % b);
        s += unitDigit;
        a /= b;
    }
    return s;
}
// solve function prints the final answer
void solve()
{
    int A;
    cin >> A;
    ll sum=0;
    for (int i = 2; i <= A - 1; i++)
    {
        sum += func(A, i);
    }
    int B = A - 2;
    int g = __gcd(sum,B);
    while(g!=1){
        sum/=g;
        B/=g;
        g = __gcd(sum,B);
    }
    cout << sum <<"/"<< B << endl;
}
int main()
{
    solve();
}
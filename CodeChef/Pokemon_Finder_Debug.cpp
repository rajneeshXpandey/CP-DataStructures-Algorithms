#include <bits/stdc++.h>
using namespace std;
int isSquare(int n)
{
    double sr = sqrt(n);
    if ((sr - floor(sr)) == 0)
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int left, right, ans = 0;
        int sum = 0, i;
        for (i = 0; i < k; i++)
        {
            sum += arr[i];
        }
        if (isSquare(sum) == 1)
        {
            left = 0;
            right = i - 1;
            ans = 1;
        }
        else
        {
            for (int j = i; j < arr.size(); j++)
            {
                sum = sum + arr[j];
                sum-=arr[j-k];
                if (isSquare(sum) == 1)
                {
                    left = j-k+1;
                    right = j;
                    ans = 1;
                    j = arr.size();
                }
            }
        }
        if (ans == 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            for (int k = left; k <= right; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
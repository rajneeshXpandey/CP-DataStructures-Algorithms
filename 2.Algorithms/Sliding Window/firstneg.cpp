#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    //code
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k;

        //solution

        int i = 0, j = 0;
        queue<int> q;
        vector<int> ans;

        while (j < n)
        {
            if (arr[j] < 0)
                q.push(arr[j]);
            if ((j - i + 1) < k)
                j++;
            else if ((j - i + 1) == k)
            {
                if (!q.empty())
                    ans.push_back(q.front());
                else
                    ans.push_back(0);

                if (arr[i] == q.front())
                    q.pop();
                i++;
                j++;
            }
        }

        for (auto x : ans)
        {
            cout << x << " ";
        }

        cout << endl;
    }
    return 0;
}
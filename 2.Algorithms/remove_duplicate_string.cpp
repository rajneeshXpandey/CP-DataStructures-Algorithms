#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string v[n];

    for (int i = 0; i < n; i++)
    {string temp ;
      cin>>temp;
    v[i]=temp;}

        set<string> s;

        for (int i = 0; i < n; i++)
        {
            s.insert(v[i]);
          
        }

       for (auto itr = s.begin(); itr != s.end(); itr++)
       {
          cout<<(*itr)<<endl;
       }
    

    return 0;
}

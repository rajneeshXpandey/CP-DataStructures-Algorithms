#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)

using namespace std;
using ll = long long;

double timeConversion(string st)
{
    double hh = stoi(st.substr(0, 2));
    
        if ( (st[6] =='P') && (hh != 0) && (hh != 12))
        {
            hh = hh + 12;
            return hh + pow(10, -2) * stoi(st.substr(3, 2));
        }
        if ((st[6] == 'A') && (hh == 12))
        {
            hh = 0;
            return hh + pow(10, -2) * stoi(st.substr(3, 2));
        }
        return hh + pow(10, -2) * stoi(st.substr(3, 2));
}


int main()
{
    string testcase;
    getline(cin, testcase);
    int t = stoi(testcase);

    while (t--)
    {
        string p;
        getline(cin,p);
        double times = timeConversion(p);

        string line;
        getline(cin, line);
        int n = stoi(line);

        string ans = "";
        for (size_t i = 0; i < n; i++)
        {
          string inter;
          getline(cin, inter);

          double ltime = timeConversion(inter.substr(0,8));
          double rtime = timeConversion(inter.substr(9, 8));

          if(ltime<= times and times <= rtime)
          cout<<1;
          else 
          cout<<0;
        
         }       
            cout<<endl;
    }
    return 0;
}
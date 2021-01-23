#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string bst;
        cin>>bst;
        string ast = "1";
        for (int i = 0; i < n-1; i++)
        {
            if(bst[i]=='0' and bst[i+1]=='0')
            {
               if(ast[i]=='0')
               {
                   ast += "1";
               }
               else
               {
                  ast += '0';  
               }
               
            }
            else if (bst[i]=='0' and bst[i+1]=='1')
            {
                if (ast[i] == '0')
                {
                    ast += "1";
                }
                else
                {
                    ast += "1";
                }
            }
            else if (bst[i] == '1' and bst[i + 1] == '0')
            {
                if (ast[i] == '0')
                {
                    ast += '0';
                }
                else
                {
                    ast += "1";
                }
            }
            else if (bst[i] == '1' and bst[i + 1] == '1')
            {
                if (ast[i] == '0')
                {
                    ast += "1";
                }
                else
                {
                    ast += '0';
                }
            }
        }
        cout<<ast<<endl;
    }
    return 0;
}
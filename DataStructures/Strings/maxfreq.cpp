#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s = "ajfdbsiduvgbbvsjvndlfhwod";
    
    int freq[26];
    for (size_t i = 0; i < 26; i++)
    {
        freq[i]=0;
    }
    for(auto c:s){
        freq[c-'a']++;
    }
    
    char ans = 'a';
    int count = 0;
    for (size_t i = 0; i < 26; i++)
    {
        if(count < freq[i])
          {
            count = freq[i];
            ans = 'a'+i;
          }
    }
     cout<<ans<<" "<<count<<endl;

    return 0;
}

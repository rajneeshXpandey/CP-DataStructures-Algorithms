class Solution {
public:
    int expand(string s,int l,int r){
   while(l>=0 and r<s.size() and s[l]==s[r])
    {
        l--;
        r++;
    }
    return (r-l-1);
}
string longestPalindrome(string s) {
        /**
O(N^2) : space and time // using easy dp
using O(N^2) time and O(N) space
*/
    int n = s.size();
    int ans = INT_MIN;
    int start = 0, end = 0;
    int odd=0, even = 0;
    for(int i=0;i<n-1;i++){
        even = expand(s,i,i+1);
        odd = expand(s,i,i);
        if(odd > ans){
            start = i-odd/2;
            end = i+odd/2;
            ans = odd;
        }
        if (even > ans)
        {
            start = i - even / 2 + 1;
            end = i + even / 2;
            ans = even;
        }
    }
    return s.substr(start,ans);
    }
};

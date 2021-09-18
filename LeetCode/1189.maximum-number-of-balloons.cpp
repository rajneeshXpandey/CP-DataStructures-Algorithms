/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> freq;
        for (char ch : text)
        {
            if (ch == 'b' or ch == 'a' or ch == 'l' or ch == 'o' or ch == 'n')
                freq[ch]++;
        }
        int instance = INT_MAX;
        for (auto p : freq)
        {
            if (p.first == 'l' or p.first == 'o')
                instance = min(instance, p.second / 2);
            else
                instance = min(instance, p.second);
        }
        // for(auto [key,value] : freq){
        //     cout<<key<<' '<<value<<endl;
        // }
        return (instance != INT_MAX and freq.size() == 5) ? instance : 0;
    }
};
// @lc code=end


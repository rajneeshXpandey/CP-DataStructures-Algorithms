/*
 * @lc app=leetcode id=1629 lang=cpp
 *
 * [1629] Slowest Key
 */

// @lc code=start
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int prev = releaseTimes[0], temp;
        int n = releaseTimes.size();
        for (int i = 1; i < n; i++)
        {
            temp = releaseTimes[i];
            releaseTimes[i] = releaseTimes[i] - prev;
            prev = temp;
        }

        int max_press = *max_element(releaseTimes.begin(), releaseTimes.end());

        cout << max_press << ' ';

        set<char> st;
        for (int i = 0; i < n; i++)
        {
            if (releaseTimes[i] == max_press)
                st.insert(keysPressed[i]);
        }

        auto it = st.end();
        it--;
        return *it;
    }
};
// @lc code=end


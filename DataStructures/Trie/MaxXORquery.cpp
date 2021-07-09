#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *child[2];
    bool isEnd;
    TrieNode()
    {
        child[0] = NULL;
        child[1] = NULL;
        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    // insert()
    void insert(int x)
    {
        TrieNode *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            if (!node->child[bit])
                node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
        node->isEnd = true;
    }

    // query() :  max xor with q
    int query(int q)
    {
        TrieNode *node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (q >> i) & 1;
            if (!node->child[bit ^ 1])
            {
                node = node->child[bit];
                // here also we should take the value but will make no changes
            }
            else
            {
                maxXor |= (1 << i); //this will turn on the bit which was 0
                node = node->child[bit ^ 1];
            }
        }

        return maxXor;
    }
};

class Solution
{
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++)
        {
            auto v = queries[i];
            q.push_back({v[1], v[0], i}); //pushing values as needed to be sort
        }
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        int j = 0;
        vector<int> res(queries.size());
        Trie *root = new Trie();
        for (auto p : q)
        {
            int x = p[1];
            int threshold = p[0];
            while (j < nums.size() && nums[j] <= threshold)
            {
                root->insert(nums[j]);
                j++;
            }
            if (j == 0)
                res[p[2]] = -1;
            else
                res[p[2]] = root->query(x); //at index p[2]
        }
        return res;
    }
};
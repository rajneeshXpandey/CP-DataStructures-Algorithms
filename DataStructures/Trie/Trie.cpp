#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    bool isEnd;
    TrieNode *childs[26];

public:
    TrieNode(){
        memset(childs, NULL, sizeof(childs));
        isEnd = false;
    }
    /**  containsKey() | get() | put() | setEnd() | isEnd()    */
    // we can ignore it also
    bool containsKey(char ch){
        return (childs[ch - 'a'] != 0);
    }
    TrieNode *get(char ch){
        return childs[ch - 'a'];
    }
    void put(char ch, TrieNode *node){
        childs[ch - 'a'] = node;
    }
    void setEnd() {
        isEnd = true;
    }
    bool isEnds(){
        return isEnd;
    }
};

class Trie{
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie(){
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word){
        TrieNode *node = root;
        for (auto ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new TrieNode());
            node = node->get(ch);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word){
        TrieNode *node = root;
        for (auto ch : word)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        if (node->isEnds())
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix){
        TrieNode *node = root;
        for (auto ch : prefix)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
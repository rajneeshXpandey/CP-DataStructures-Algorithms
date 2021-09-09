/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
        ListNode* reverseLL(ListNode* head){
        if(!head->next) return head;
        
        auto new_head = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return new_head;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        /* iterative */
        
        /*
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head;
        
        while(nxt){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        
        return prev;
        */
        
        /* recursive */
        // /* 
        auto rev_head = reverseLL(head);
        
        return rev_head;
        // */
    }
};
// @lc code=end


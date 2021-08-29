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
  
    bool isPalindrome(ListNode* head) {
      
      if(!head->next) return true;
      
        ListNode* f = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nxt = head;
        
      while(f and f->next)
      {
        f = f->next->next;
        nxt = nxt->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
      }
      
      if(f) 
        curr = curr->next; 
      
      while(prev and curr)
      {
        if(prev->val != curr->val)
           return false;
        prev =  prev->next;
        curr = curr->next;
      }
      
      return true;
        
    }
};

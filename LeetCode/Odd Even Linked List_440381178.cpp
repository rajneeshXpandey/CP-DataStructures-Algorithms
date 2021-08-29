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
    ListNode* oddEvenList(ListNode* head) {
      
      if(!head)
        return head;
      
      if(!head->next)
       return head;
      
       ListNode* temp = head;
      
       ListNode* newhead = temp;

       ListNode* even = head->next;
         ListNode* evenhead = even;
      
      while(even and even->next)
      {
        temp->next = temp->next->next;
        temp = temp->next;
        even->next = even->next->next;
        even = even->next;
        
      }  
      
      temp->next = evenhead;


      return newhead;
        
    }
};

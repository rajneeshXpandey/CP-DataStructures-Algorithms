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
    ListNode* sortList(ListNode* head) {
         if(!head or !head->next)
            return head;      
         ListNode* getmiddle = mid(head);
         ListNode* left = sortList(head);
         ListNode* right = sortList(getmiddle);
         ListNode* merged =  merge(left,right);      
      return merged;          
    }
ListNode* mid(ListNode* head)
  {
    if(!head) return head;
     ListNode* slow = head;
     ListNode* fast = head->next;
    
    while(fast and fast->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }  
   ListNode* mid = slow->next;
    slow->next = nullptr;
    return mid;     
   }
  
  ListNode* merge(ListNode* l1,ListNode* l2)
  {
     ListNode* dummy = new ListNode(-1);
     ListNode* curr = dummy;
    while(l1 and l2)
    {
      if(l1->val >= l2->val)
      {
        curr->next=l2;
        l2=l2->next;
      }
      else
        {
        curr->next = l1;
        l1=l1->next;
      }
      curr = curr->next;
    }
    curr->next = (l1)?l1:l2;
    
     return dummy->next;
  }
    
};

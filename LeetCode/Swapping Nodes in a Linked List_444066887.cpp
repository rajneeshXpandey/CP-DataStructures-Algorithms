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
    ListNode* swapNodes(ListNode* head, int k) {  
      
      if(head==NULL)
      {
        return head;
      }
      
  ListNode* newhead = head;
  ListNode* p=head;
  ListNode* q = head;
      
   int n=0;
      while(newhead != nullptr)
      {
        n++;
        newhead = newhead->next;
      }
    for(int i=0;i<k-1;i++){
        p = p->next;
      }
    for(int i=0;i<n-k;i++){
        q = q->next;
      }
      
      swap(p->val,q->val);
      
       return  head;
    }
};

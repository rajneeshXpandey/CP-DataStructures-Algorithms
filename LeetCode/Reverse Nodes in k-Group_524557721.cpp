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
    ListNode* Reverse(ListNode* head, ListNode* end){
   if(!head)
     return head;
    
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = head;
    
    while(next!=end)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  
  ListNode* kNodeSwap(ListNode* head,ListNode* end,int k)
  {

   if(head == end)  return head;
      
    ListNode* q = head;
    
    for(int i=0;i<k;i++)
       q = q->next;
   ListNode* rev = Reverse(head,q);
   head->next = kNodeSwap(q,end,k); 
   return rev; 
  }
  
 ListNode* reverseKGroup(ListNode* head, int k) {
   
    if(!head or k==1)
      return head;
      
      ListNode* count = head;
      int n=0;
      while(count)
       { count = count->next;
         n++;        
       }
      count = head;
       n =n- n%k;

    while(n>0)
       { 
        count = count->next; 
         n--;
       }
 
       return  kNodeSwap(head,count,k);
    }
};

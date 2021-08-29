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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *root = nullptr;
        ListNode *last = nullptr;
        
        if(l1 == nullptr && l2 == nullptr){
            return root; 
        }
         else if(l1 != nullptr && l2 == nullptr){
            return l1; 
        }
        else  if(l1 == nullptr && l2 != nullptr){
            return l2; 
        }
        
      if(l1->val <= l2->val){
            root = l1;
            last = l1;
            l1=l1->next;
            last->next = nullptr; 
        }
        else{
            root = l2;
            last = l2;
            l2=l2->next;
            last->next = nullptr; 
        }

        while(l1 != nullptr && l2 != nullptr)
        {
            if(l1->val <= l2->val )
            {    
                
                last->next = l1;
                 last = l1;
                l1 = l1->next;
                last->next = nullptr;
            }
            else 
            {last->next = l2;
                last = l2;
                l2=l2->next;
                last->next = nullptr;
            }
        }
        
        if(l1 != nullptr){
            last->next = l1;
        }
        else if(l2 != nullptr){
            last->next = l2;
        }
        
        return root;
        
    }
};

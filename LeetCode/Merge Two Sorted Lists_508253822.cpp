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
        
        if(!l1 and !l2)
             return NULL;
        if(!l1 and l2) return l2;
        if(l1 and !l2) return l1;
        
        ListNode* a = l1;
        ListNode* b = l2;
        
        ListNode* head = (l1->val<=l2->val)?l1:l2;
        ListNode* temp = NULL;
        while(a and b)
        {
            if(a->val <= b->val)
            {
                while(a->next and a->next->val <= b->val)
                    a = a->next;
                temp = a->next;
                a->next = b;
                a = temp;
            }
           else if(a->val > b->val)
            {
                while(b->next and b->next->val <= a->val)
                    b= b->next;
                temp = b->next;
                b->next = a;
                b = temp;
            }     
        }
          
       return head;   
    }
};

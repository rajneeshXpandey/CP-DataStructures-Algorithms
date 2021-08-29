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
    
        if(!head or !head->next or !head->next->next)
                return head;        
        ListNode* oddH = head;
        ListNode* odd = head;
        ListNode* eveH = head->next;
        ListNode* eve = head->next;
        bool switc = 1;
        while(eve and eve->next)
        {
            if(switc)
            {
                odd->next = eve->next;
                odd = odd->next;
                switc = !switc; 
             }
            else {
                eve->next = odd->next;
                eve = eve->next;
                switc = !switc;
            }
        }
        
         odd->next = eveH;
        
        return oddH;
        
        
    }
};

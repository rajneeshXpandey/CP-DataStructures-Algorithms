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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = nullptr;
        ListNode* q = nullptr;
        
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        p = head;
        q = head->next;
        while(q != nullptr){
            if(p->val != q->val){
                p = q;
                q = q->next;
            }
            else{
               p->next = q->next;
               q = q->next;           
            }
        }
        
        return head;
        
    }
};

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
    int getDecimalValue(ListNode* head) {
        
        ListNode *last, *first = head;
        int numNode = 0;
        long long int value = 0;
        
        while(last != nullptr)
            {last = last->next;
            numNode++;}
        while(numNode != 0){
            
            numNode--;
            value += (first->val)*pow(2,numNode);
            first = first->next;       
            
        }
        
        
        return value;
        
        
    }
};

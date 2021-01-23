// Remove Duplicates from Sorted List

 #include <bits/stdc++.h>

 using namespace std;
//Definition for singly-linked list.
class ListNode{
public:
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
                //important
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

int main(){

    //  Input: 1->1->2
    //  Output: 1->2

    //  Input: 1->1->2->3->3
    // Output: 1->2->3
            
 }
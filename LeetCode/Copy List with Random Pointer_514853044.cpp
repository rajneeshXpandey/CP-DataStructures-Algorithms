/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    
    Node* copyRandomList(Node* head) {
        
        if(!head) return head;
      
//        <----------------Using map O(N) space------------------>
//         unordered_map<Node*,Node*> mp;
        
//         Node* p = head;
        
//         while(p)
//         {
//            Node* temp = new Node(p->val);
//            mp.insert({p,temp});
//            p = p->next; 
//         }
//         p = head;
//         while(p)
//         {
//            Node* clonedNode = mp[p];
//            clonedNode->next = mp[p->next];
//            clonedNode->random = mp[p->random];
//            p = p->next; 
//         }
//        return mp[head];
        
//   <---------------------Using O(1) space------------------->     
       
        Node* curr = head;
        Node* next = head->next;
        while(curr)
        {
            Node* temp = new Node(curr->val);
            curr->next = temp;
            temp->next = next;
            curr = next;
            if(next)
             next = curr->next;
        }
        curr = head;
        while(curr)
        {
    curr->next->random = (curr->random!=NULL)?curr->random->next
        :NULL; 
    curr = curr->next->next;
        }
        Node* newHead = new Node(-1);
        
        newHead->next = head->next;
        
        curr = head;
        next = head->next;
        while(curr and next)
        {
            curr->next = curr->next->next;
            if(next->next)
                next->next = curr->next->next;
            curr = curr->next; 
            next = next->next;    
        }
        
        return newHead->next;



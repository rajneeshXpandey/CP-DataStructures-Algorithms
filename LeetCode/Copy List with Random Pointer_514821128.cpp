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
        unordered_map<Node*,Node*> mp;
        
        Node* p = head;
        
        while(p)
        {
           Node* temp = new Node(p->val);
           mp.insert({p,temp});
           p = p->next; 
        }
        p = head;
        while(p)
        {
           Node* clonedNode = mp[p];
           clonedNode->next = mp[p->next];
           clonedNode->random = mp[p->random];
           p = p->next; 
        }
       return mp[head];
        
//   <---------------------Using O(1) space------------------->     
       
         
    }


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
    int numComponents(ListNode* head, vector<int>& G) {      
     ListNode* temp = head;
      int n = 0;      
      while(temp)
      {
        n++;
        temp = temp->next;
      }
      int arr[n] ;
      
      memset(arr,0,sizeof(arr));
      
      for(int x:G)
      {
        arr[x]=1;
      }

      int ans = 0;
      
      bool flag = 1;
      
      while(head){
        
        if(arr[head->val] != 1)
        {
          flag = 1;
        }
        else{
          if(flag)
            ans++;
          flag = 0;
        }
        
        head = head->next;
      }
      
      return ans;     
    }
};

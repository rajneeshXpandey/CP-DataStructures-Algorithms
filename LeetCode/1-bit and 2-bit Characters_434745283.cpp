class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
     
      
      int c = 0,s = bits.size()-2;
      
      for(int i=0;i<bits.size();i++)
      {
        if(i == bits.size()-1)
           return true;
        
        if(bits[i]==1)
           i++;
       
      }
  
         return false;     
      
    }
};



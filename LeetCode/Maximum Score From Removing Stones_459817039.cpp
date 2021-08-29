class Solution {
public:
    int maximumScore(int a, int b, int c) {
       int score=0;
       priority_queue<int> mxheap;      
       mxheap.push(a);
       mxheap.push(b);
       mxheap.push(c);
       
       while(mxheap.size()>1){         
         int f = mxheap.top();
         mxheap.pop();
         int s = mxheap.top();
         mxheap.pop();         
          if(f-1 != 0)
            mxheap.push(f-1);
          if(s-1 != 0)
            mxheap.push(s-1);         
         score++;
       }
      
      return score;
    }
};

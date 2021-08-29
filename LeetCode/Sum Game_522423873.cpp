class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int lsum=0,rsum=0,lq=0,rq=0;
        for(int i=0;i<(n/2);i++)
            { 
              if(num[i]!='?')
                 lsum += num[i]-'0';
              else if(num[i]=='?') lq++; 
              if(num[i+n/2]!='?')
                 rsum += num[i+n/2]-'0';
              else if(num[i+n/2]=='?') rq++;
            }
         // case 2: ?..? sum | (empty) --> always return true
        if((lsum>rsum and lq>=rq) || (lsum<rsum and lq<=rq))
             return true;
            // case 1: ?..? | sum
        else{
            if(lsum>rsum) swap(lsum,rsum);
            int sum = rsum-lsum;
            if(rq>lq) swap(lq,rq);
            int q = lq-rq;
            if(double(q*(double)9/2) == double(sum))
                return false;
            else 
                return true;
        }
     }
};

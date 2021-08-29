class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int farthest = 0;
        int n = s.size();
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int currIdx = q.front();
            q.pop();
            int start = max(currIdx+minJump,farthest+1);
            for(int i=start;i<=min(n-1,currIdx+maxJump);i++){
                if(s[i]=='0'){
                    q.push(i);
                    if(i==n-1)
                        return true;
                }
            }
            farthest = currIdx+maxJump;
        }
        
        return false;
    }
};

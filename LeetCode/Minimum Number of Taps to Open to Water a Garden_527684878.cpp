class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int far = 0,start = 0,open=0;
        while(far<n)
        {
            for(int i=0;i<ranges.size();i++){
                if(i-ranges[i]<=start and i+ranges[i]>far){
                    far = i+ranges[i];
                }
            }
            if(far==start) return -1;
            open++;
            start = far;
        }
        return open;
    }
};

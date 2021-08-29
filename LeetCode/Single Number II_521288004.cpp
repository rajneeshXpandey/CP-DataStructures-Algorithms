class Solution {
public:
    int singleNumber(vector<int>& nums) {
    vector<long long > bitplace(64,0);
    for(int i=0;i<64;i++){
        for(auto &n : nums){
            long long m = n;
            if((m>>i)&1)
              bitplace[i]++;
        }
    }
    long long  num = 0;
    for(int i=0;i<64;i++){
        if(bitplace[i]%3!=0)
          num |= (1LL<<i);
    }
        return (int)num;
    }
};

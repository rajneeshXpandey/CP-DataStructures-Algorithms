class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> dist(num_people,0);
        /**    
        1 ... k    = s
        k+1 ..2k   = s + k*k
        2k+1..3k   = s + 2k*k 
        1       2       3       ...................r
        s  + (s + k2) + (s + 2k2) ........... s + (r-1)k2  => r*s+(r(r
            -1)/2)*k2
        => rk/2 + r2k2/2  =  rk(1 + rk)/2;  
        */
        int candy = 1;
        int i=0;
        while(candy<=candies){
            dist[i%num_people] += candy;
            candies -= candy;
            candy++;
            i++;
        }
    
        if(candies>0){
            dist[i%num_people] += candies;
        }

        return dist;
    }
};

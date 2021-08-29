class Solution {
public:
    int findNthDigit(int n) {
        long long len = 1;
        long long  count = 9;
        /**
        1...9      = 9 * 1    = 9
        10....99   = 90 * 2   = 180
        100....999 = 900 * 3  = 2700
        */
        while(n>(len*count)){
            n = n-(len*count);
            len++;
            count *= 10;
        }
        
        long long rem = n%len;
        long long num = n/len + pow(10,len-1);
         // cout<<len<<' '<<rem<<' '<<num<<endl;
        if(rem==0)
            return ((num%10)+9)%10;
       
        long long arr[len];
        for(int i=len-1;i>=0;i--){
            arr[i] = num%10;
            num /= 10;
        }
        
        return arr[rem-1];
    }
};

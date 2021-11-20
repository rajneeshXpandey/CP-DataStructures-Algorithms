//Binary expo calculate power of a^n in O(log(n)) time 

int power(int a,int n)
 {
     int res = 1;
     while(n>0)
      {
        if(n%2)
            res *= a;
        a *= a;
        n /= 2; 
      }
      return res;
 }
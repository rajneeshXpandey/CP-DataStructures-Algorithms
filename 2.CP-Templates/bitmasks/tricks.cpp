/* 1. RESET the right-most SET bit in a number n */
    int n;
    n = n&(n-1);

/* 2. Counting number of set bits (Brian Kernighan’s algorithm.) */
        int cnt = 0;
        while(n){
            cnt += 1;
            n &= (n-1);
        }

3. /* Checking if given 32 bit integer is power of 2 
 
       * *All the power of 2 have only single bit set e.g. 16 (00010000). 
         *If we minus 1 from this, all the bits from LSB to set bit get toggled,
         *i.e., 16-1 = 15 (00001111). Now if we AND x with (x-1)
         *the result is 0 then we can say that x is power of 2 otherwise not.
         *We have to take extra care when x = 0.
    */
        int isPowerof2(int x)
        {
            return (x && !(x & x-1));
        }

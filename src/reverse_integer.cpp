class Solution {
public:
    // 溢出的话返回 0
    int reverse(int x) {
        if(x == -2147483648) return 0;  // INT_MIN
        
        int flag = (x < 0) ? ( x = -x , 1) : 0;
        int num = 0;
        
        int q, r, t;
        while(x) {
           q = x/10;
           r = x%10;
           t = num;
           // num = num*10 + r;	// overflow!!!
    		   for(int i = 0; i < 9; i++) {
    			   num += t;
    			   if(num < 0) {
    				   num = 0;
    				   goto ret;
    			   }
    		   }
    		   if((num += r) < 0) { num = 0; goto ret; }
    		   x = q;
        }
        
        if(flag) num = -1 * num;
        
        ret:
		      return num;
    }
};
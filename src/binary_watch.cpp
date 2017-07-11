class Solution {
public:
	int n;
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        n = num;
		
        solve(ret, 9, 0, 0);
        
        return ret;
    }
    
    void solve(vector<string>& v, int num, int bits, int count) {
        // early return.
		if(count == n) {
			
			int hour = bits >> 6;
			int minute = bits & 0x3f;
			
			if(hour>11 || minute > 59)
				return;
			
			string h, m;
			if(hour < 10) {
				h = hour + '0';
			} else {
				h = '1';
				h += (hour-10) + '0';
			}
			
			m = (minute/10) + '0';
			m += (minute%10) + '0';
			
			string ret = h + ':' + m;
			
			v.push_back(ret);
			
			return;
		}
		
        if(num >= 0) {
            for(int i = 0; i < 2; i++) {
                bits |= i << num;
                solve(v, num-1, bits, count+i);
            }
        }
    }
};
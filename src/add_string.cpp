class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        ret.reserve(5100);
        
        int sz1 = num1.size()-1;
        int sz2 = num2.size()-1;
        
        int carryOut = 0, val;
        while(sz1 >= 0 || sz2 >= 0) {
            if(sz1 == -1) {
                val = num2[sz2]-'0' + carryOut;
                carryOut = 0;
                if(val > 9) { carryOut = 1; val -= 10; }
                ret.push_back(val+'0');
                --sz2;
            }
            else if(sz2 == -1) {
                val = num1[sz1]-'0' + carryOut;
                carryOut = 0;
                if(val > 9) { carryOut = 1; val -= 10; }
                ret.push_back(val+'0');
                --sz1;
            }
            else {
                val = num1[sz1] + num2[sz2] - '0' - '0' + carryOut;
                carryOut = 0;
                if(val > 9) { carryOut = 1; val -= 10; }
                ret.push_back(val+'0');
                --sz1;
                --sz2;
            }
        }
        if(carryOut) {
            ret.push_back('1');
        }
        
        cout << ret << endl;
        
        std::reverse(ret.begin(), ret.end());
        
        cout << ret << endl;
        
        return ret;
    }
};
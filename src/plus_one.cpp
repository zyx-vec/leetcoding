class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::reverse(digits.begin(), digits.end());
        
        int carryOut = 1;
        
        for(int i = 0; i < digits.size(); i++) {
            digits[i] += carryOut;
            carryOut = 0;
            if(digits[i] > 9) {
                digits[i] -= 10;
                carryOut = 1;
                continue;
            }
            break;
        }
        
        if(carryOut) digits.push_back(1);
        
        std::reverse(digits.begin(), digits.end());
        
        return digits;
    }
};
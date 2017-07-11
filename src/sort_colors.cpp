class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        onePass(nums);
        
        return;
        
        
        vector<int> v(3, 0);
        
        for(int i = 0; i < nums.size(); i++) {
            v[nums[i]]++;
        }
        
        int c = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < v[i]; j++) {
                nums[c++] = i;
            }
        }
    }
    
    void onePass(vector<int>& nums) {
        int i, j, l;
        i = 0, j = 0, l = 0;
        
        for(int k = 0; k < nums.size(); k++) {
            switch(nums[k]) {
                case 0: nums[l++] = nums[j]; nums[j++] = nums[i]; nums[i++] = 0;
                    break;
                case 1: nums[l++] = nums[j]; nums[j++] = 1;
                    break;
                case 2: nums[l++] = 2;
                    break;
            }
        }
    }
};
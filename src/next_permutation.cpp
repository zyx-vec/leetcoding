class Solution {
public:
    // implement it in yourself!!!
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        
        int index = findLast(nums);
        // next_permutation(nums.begin(), nums.end());
        
        if(index == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            int target = findMinLarger(index, nums);
            cout << index << ' ' << target << endl;
            int tmp = nums[index];
            nums[index] = nums[target];
            nums[target] = tmp;
            
            reverseLastPart(nums, index+1, nums.size()-1);  // 1 1
        }
    }
    
    int findLast(vector<int>& nums) {
        int i = nums.size()-1;
        
        while(i > 0 && nums[i-1] >= nums[i]) {
            i--;
        }
        
        return (i-1);
    }
    
    int findMinLarger(int n, vector<int>& nums) {
        int i = nums.size()-1;
        // duplication must considered here.
        while(nums[i] <= nums[n]) {
            i--;
        }
        
        return i;
    }
    
    void reverseLastPart(vector<int>& nums, int l, int r) {
        int tmp;
        while(l < r) {
            tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        }
    }
};
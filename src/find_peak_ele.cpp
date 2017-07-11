class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return impl(nums, 0, nums.size()-1);       
    }
    
    int impl(vector<int>& nums, int l, int r) {
        if(l == r) {
            return l;
        } else {
            int mid = (l+r) / 2;
            if(mid < nums.size()-1 && nums[mid] > nums[mid+1]) {
                return impl(nums, l, mid);
            } else {
                return impl(nums, mid+1, r);
            }
        }
    }
};
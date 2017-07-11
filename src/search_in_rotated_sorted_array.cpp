class Solution {
public:
	int t;
    int search(vector<int>& nums, int target) {
		
        t = target;
		
		int res = bSearch(nums, 0, nums.size()-1);
		
		return res;
    }
	
	int bSearch(vector<int>& nums, int l, int r) {
		if(l > r) return -1;
		
		int mid = l/2 + r/2 + (l%2+r%2)/2;
		
		if(nums[l] <= nums[mid]) {
			if(t < nums[mid]) {
				if(t > nums[l]) {
					return bSearch(nums, l, mid-1);
				} else if(t < nums[l]) {
					return bSearch(nums, mid+1, r);
				} else {
					return l;
				}
			} else if(t > nums[mid]) {
				return bSearch(nums, mid+1, r);
			} else {
				return mid;
			}
		} 
		else if(nums[mid] <= nums[r]){
			if(t > nums[mid]) {
				if(t > nums[r]) {
					return bSearch(nums, l, mid-1);
				} else if(t < nums[r]) {
					return bSearch(nums, mid+1, r);
				} else {
					return r;
				}
			} else if(t < nums[mid]) {
				return bSearch(nums, l, mid-1);
			} else {
				return mid;
			}
		} else {
		    return -1;   
		}
	}
};
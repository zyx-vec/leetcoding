class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = biSearch(nums, 0, nums.size(), target);

		return i;
	}

	int biSearch(vector<int>& nums, int low, int high, int target) {
		if(low > high) {
			cout << low << ' ' << high << endl;
			if(low <= 0) return 0;
			else if(high >= nums.size()) return nums.size();
			else if(nums[low] >= target) return low;
			else return high;
		}

		int mid = (low+high) / 2;

		if(nums[mid] > target) {
			return biSearch(nums, low, mid-1, target);
		} else if(nums[mid] < target) {
			return biSearch(nums, mid+1, high, target);
		} else {
			return mid;
		}
	}
};
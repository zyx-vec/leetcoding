#include <iostream>
#include <vector>


class Solution {
public:
	int solve(const std::vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		std::vector<int> table(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					table[i] = std::max(table[i], table[j]+1);
				}
			}
		}

		int result = table[0];
		for (int i = 1; i < table.size(); i++) {
			if (table[i] > result)
				result = table[i];
		}
		return result;
	}
};

int main() {

	Solution sol;

	std::vector<int> nums = {1,3,6,7,9,4,10,5,6};

	std::cout << sol.solve(nums) << std::endl;


	return 0;
}
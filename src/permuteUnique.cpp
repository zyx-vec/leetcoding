#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		res.push_back(nums);
		// while(std::next_permutation(nums.begin(), nums.end())) {
		while(next_permutation(nums)) {
			res.push_back(nums);
		}

		return res;
	}

	bool next_permutation(vector<int>& nums) {
		int i, j;
		for(i = nums.size()-1; i > 0; i--) {
			if(nums[i-1] < nums[i]) break;
		}
		if(i == 0 && nums[0] >= nums[1]) return false;

		for(j = nums.size()-1; j >= i ; j--) {
			if(nums[j] > nums[i-1]) break;
		}
		swap(nums[i-1], nums[j]);

		reverse(nums.begin()+i, nums.end());

		return true;
	}
};

int main() {

	Solution s;

	vector<int> v{2, -1, -1};

	vector<vector<int>> res = s.permuteUnique(v);

	for(auto& list : res) {
		for(auto item : list) {
			cout << item << ' ';
		}
		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Solution {
public:
	vector<vector<int>>









	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> n;

		sort(candidates.begin(), candidates.end());

		solve(res, n, candidates, target);

		return res;
	}

	int solve(vector<vector<int>>& res, vector<int>& n, vector<int>& nums, int target) {
		if(target == 0) {
			vector<int> tmp(n);
			sort(tmp.begin(), tmp.end());
			if(!isIncluded(res, tmp)) {
				res.push_back(tmp);
			}
			return 0;	// equal
		} else if(target < 0) {
			return -1; 	// too big
		} else {
			int ret;
			for(int i = 0; i < nums.size(); i++) {
				n.push_back(nums[i]);
				if((ret = solve(res, n, nums, target-nums[i])) < 0) {
					n.pop_back();
					if(target >= nums[i]) continue;
					else return -1;
				}
				else if(ret == 0) {	// to find the next solution.
					n.pop_back();
					continue;
				}
				else {
					continue;
				}
			}
		}
	}

private:
	bool isIncluded(vector<vector<int>>& res, vector<int>& n) {
		for(auto& list: res) {
			if(list.size() == n.size() && !memcmp(&list[0], &n[0], sizeof(int)*n.size())) {
				return true;
			}
			else continue;
		}
		return false;
	}
};

int main() {

	Solution s;

	vector<int> v{2, 3, 6, 7, 8};
	int target = 30;

	vector<vector<int>> res = s.combinationSum(v, target);

	for(auto& list: res) {
		for(auto& item: list) {
			cout << item << ' ';
		}
		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> isVisited(nums.size(), 0);
        vector<int> n;
        n.reserve(nums.size());
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
        	if(!isVisited[i]) {
        		isVisited[i] = 1;
        		n.push_back(nums[i]);
        		solve(res, nums, isVisited, count+1, n);
        		isVisited[i] = 0;
        		n.pop_back();
        	}
        }

        return res;
    }
private:
	void solve(vector<vector<int>>& res, const vector<int>& nums, vector<int>& isVisited, int count, vector<int>& n) {
		if(count >= nums.size()) {
			res.push_back(n);
			return;
		}

		for(int i = 0; i < nums.size(); i++) {
			if(!isVisited[i]) {
				isVisited[i] = 1;
				n.push_back(nums[i]);
				solve(res, nums, isVisited, count+1, n);
				isVisited[i] = 0;
				n.pop_back();
			}
		}
	}
};

int main() {

	Solution s;
	vector<int> v{1, 2, 3};

	vector<vector<int>> res = s.permute(v);

	for(auto& list : res) {
		for(auto item: list) {
			cout << item << ' ';
		}
		cout << endl;
	}

	return 0;
}
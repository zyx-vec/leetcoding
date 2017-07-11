#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<int>> vv(strs.size(), vector<int>(27, 0));
		vector<vector<string>> ret;
		ret.reserve(strs.size());

		for(int i = 0; i < strs.size(); i++) {
			vv[i][26] = strs[i].size();		// the last item stores the length of this string.
			for(int j = 0; j < strs[i].size(); j++) {
				vv[i][strs[i][j]-'a'] += 1;
			}
		}

		vector<int> v(strs.size(), 0);
		int n = 0;
		int i = 0;
		vector<string> anagram;
		while((i = findNext(v)) < strs.size()) {
			v[i] = 1;
			anagram.push_back(strs[i]);
			for(int j = i+1; j < strs.size(); j++) {
				if(compareVec(vv[i], vv[j])) {
					v[j] = 1;
					anagram.push_back(strs[j]);
				}
			}
			ret.push_back(std::move(anagram));
			anagram.clear();
		}

		return ret;
	}
private:
	bool compareVec(const vector<int>& v1, const vector<int>& v2) {
		if(v1[26] != v2[26]) return false;

		// for(int i = 0; i < 26; i++) {
		// 	if(v1[i] != v2[i]) return false;
		// }

		return !memcmp(&v1[0], &v2[0], sizeof(int)*26);
		return true;
	}

	int findNext(const vector<int>& v) {
		for(int i = 0; i < v.size(); i++) {
			if(v[i] == 0) return i;
		}
		return v.size();
	}
};

int main() {
	Solution s;
	// vector<string> strs{"eat", "tab", "eat", "tea", "tan", "ate", "nat", "bat"};

	// vector<string> strs{"eat", "tab", "tea", "tan", "ate", "nat", "bat"};
	vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

	vector<vector<string>> value = s.groupAnagrams(strs);

	for(const auto& list: value) {
		for(const auto& item: list) {
			cout << item << endl;
		}
		cout << endl;
	}

	return 0;
}
class Solution {
public:
	vector<string> result;
	int maxLevel;
public:

	vector<string> generateParenthesis(int n) {
		maxLevel = n*2;
		string s;
		solve(s , n, 0, 0);
		return result;
	}
	
	void solve(string& s, int l, int r, int level) {
		if(level == maxLevel) {
			result.push_back(s);
		}
		else {
		    // 当前有 l 个左括号可以用，用了一个之后 l-1, r+1
			if(l > 0) {
				s.push_back('(');
				solve(s, l-1, r+1, level+1);
				s.erase(s.end()-1, s.end());
			}
			// 当前有 r 个右括号可以用，用了一个之后 l, r-1
			if(r > 0) {
				s.push_back(')');
				solve(s, l, r-1, level+1);
				s.erase(s.end()-1, s.end());
			}
		}
	}
};
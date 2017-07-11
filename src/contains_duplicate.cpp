class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> tool;
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
            if (++tool[*i] >= 2) return true;
        }
        return false;
    }
};
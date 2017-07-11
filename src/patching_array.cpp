class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int needed = 1, cnt = 0, i = 0;
        long long maximum = 0;
        while(maximum < n) {
            if(i < nums.size() && nums[i] <= maximum+1) {
                maximum += nums[i++];
            } else {
                maximum += maximum + 1;
                cnt++;
            }
        }
        
        return cnt;
    }
};
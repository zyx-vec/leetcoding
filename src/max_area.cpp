#include <iostream>
#include <vector>
using namespace std;

// Given n non-negative integers a1, a2, ..., an, where each
// represents a point at coordinate (i, ai). n vertical lines
// are drawn such that the two endpoints of line i is at 
// (i, ai) and (i, 0). Find two lines, which together with 
// x-axis forms a container, such that the container contains
// the most water.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_val = 0;
        vector<int> stack;
        stack.reserve(height.size());

        stack.push_back(0);
        int i = 1, area = 0;
        for(;;) {
            while(i < height.size() && !stack.empty() && height[stack.back()] < height[i]) {
                area = (i - stack.back()) * height[stack.back()];
                stack.pop_back();
                if(area > max_val) {
                    max_val = area;
                }
            }
            // if(stack.size() == 0) stack.push_back(0);
            stack.push_back(i);
            i++;
            if(i >= height.size()) break;
        }

        cout << max_val << endl;
        for(int i = 0; i < stack.size(); i++) {
            cout << stack[i] << ' ';
        }
        cout << endl;

        int b = stack.back();
        for(int i = 0; i < stack.size()-1; i++) {
            area = (b - stack[i]) * height[b];
            // cout << "area = " << area << endl;
            if(area > max_val) {
                max_val = area;
            }
        }

        return max_val;
    }
};

int main() {
    
    // vector<int> height = {1, 2};
    // vector<int> height = {3, 2, 1, 4, 5, 2};
    vector<int> height = {1, 2};

    Solution s;

    int val = s.maxArea(height);
    cout << val << endl;

    return 0;
}

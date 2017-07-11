#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size()/2; i++) {
            // for(int j = 0; j < i; j++) {
            //     int tmp = matrix[i][j];
            //     matrix[i][j] = matrix[j][i];
            //     matrix[j][i] = tmp;
            // }
            for(int j = 0; j < matrix.size()-1-(i*2); j++) {
            	cycle_run(matrix, j, i);
            }
        }
    }

private:
	// void cycle_run1(vector<vector<int>>& matrix, int i, int size) {
	// 	int x, y, index, level, tmp, tmp1;
	// 	level = (matrix.size() - size) / 2;

	// 	index = i + (size * i) + (size - i) - 1;
	// 	x = index/size, y = index%size;
	// 	tmp = matrix[x][y];
	// 	matrix[x][y] = matrix[level][i];

	// 	index += (size * (size - i - 1)) - i;
	// 	x = index/size, y = index%size;
	// 	tmp1 = matrix[x][y];
	// 	matrix[x][y] = tmp;
	// 	tmp = tmp1;

	// 	index -= i * size + size - 1 - i;
	// 	x = index/size, y = index%size;
	// 	tmp1 = matrix[x][y];
	// 	matrix[x][y] = tmp;
	// 	tmp = tmp1;

	// 	index = index - (size-i-1)*size + i;
	// 	x = index/size, y = index%size;
	// 	tmp1 = matrix[x][y];
	// 	matrix[x][y] = tmp;
	// }

	void cycle_run(vector<vector<int>>& matrix, int i, int level) {
		int x, y, index, size, tmp, tmp1, n, o;
		size = matrix.size() - level*2;
		index = level*matrix.size() + level + i;
		n = matrix.size();
		o = index;

		index += (size * i) + (size - i) - 1 + (level*2)*i;
		x = index / n, y = index % n;
		tmp = matrix[x][y];
		matrix[x][y] = matrix[level][i+level];

		index += (size * (size - i - 1)) - i + (level*2)*(size-i-1);
		x = index / n, y = index % n;
		tmp1 = matrix[x][y];
		matrix[x][y] = tmp;
		tmp = tmp1;

		index -= i * size + size - 1 - i + (level*2)*i;
		x = index / n, y = index % n;
		tmp1 = matrix[x][y];
		matrix[x][y] = tmp;
		tmp = tmp1;

		index = o;
		x = index / n, y = index % n;
		tmp1 = matrix[x][y];
		matrix[x][y] = tmp;
	}
};

// from leetcode
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}

int main() {

	Solution s;

	vector<vector<int>> matrix(10, vector<int>(10, 0));
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = i*matrix.size() + j;
		}
	}

	s.rotate(matrix);

	for(const auto& list: matrix) {
		for(auto i: list) {
			cout << i << '\t';
		}
		cout << endl;
	}

	return 0;
}
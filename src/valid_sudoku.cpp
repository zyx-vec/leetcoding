class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> nums;
        //each row
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (isdigit(board[i][j])) {
                    if (nums.test(board[i][j] - '1')) {
                        return false;
                    } else {
                        nums.set(board[i][j] - '1');
                    }
                }
            }
            nums.reset();
        }
        
        //each col
        for (size_t j = 0; j < board[0].size(); ++j) {
            for (size_t i = 0; i < board.size(); ++i) {
                if (isdigit(board[i][j])) {
                    if (nums.test(board[i][j] - '1')) {
                        return false;
                    } else {
                        nums.set(board[i][j] - '1');
                    }
                }
            }
            nums.reset();
        }
        
        //each block
        for (size_t i = 0; i < 9; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                for (size_t k = 0; k < 3; ++k) {
                    if (isdigit(board[i / 3 * 3 + j][i % 3 * 3 + k])) {
                        if (nums.test(board[i / 3 * 3 + j][i % 3 * 3 + k] - '1')) {
                            return false;
                        } else {
                            nums.set(board[i / 3 * 3 + j][i % 3 * 3 + k] - '1');
                        }
                    }
                }
        	}
        	nums.reset();
        }
        
        return true;
    }
};
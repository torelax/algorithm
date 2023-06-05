#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> h = {};
        unordered_set<int> s;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] <= '9' && board[i][j] >= '0' && s.count(board[i][j]) == 0) {
                    s.insert(board[i][j]);
                    continue;
                }
                else if(board[i][j] == '.')
                    continue;
                return false;
            }
            s.clear();
        }
        for(int i = 0; i < 9; i++) {
            for(int l = 0; l < 9; l++) {
                if(board[l][i] <= '9' && board[l][i] >= '0' && s.count(board[l][i]) == 0) {
                    s.insert(board[l][i]);
                    continue;
                }
                else if(board[l][i] == '.')
                    continue;
                return false;
            }
            s.clear();
        }
        for(int i = 1; i <= 8; i+=3) {
            for(int j = 1; j <= 8; j+=3) {
                for(int x = i-1; x <= i+1; x++) {
                    for(int y = j-1; y <= j+1; y++) {
                        if(board[x][y] <= '9' && board[x][y] >= '0' && s.count(board[x][y]) == 0) {
                            s.insert(board[x][y]);
                            continue;
                        }
                        else if(board[x][y] == '.')
                            continue;
                        return false;
                    }
                }
                s.clear();
            }
        }
        return true;
    }
};
// @lc code=end


#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
public:
    Solution(){}
    ~Solution(){}
    void backtrack(vector<string>& qu ,int m, int n, int pos[]) {
        if (m == n)   {
            res.push_back(qu);  
        }  
        else for (int j = 0; j < n; j++)
        {
            qu[m] = string(n, '.');
            bool flag = true;
            pos[m] = j;
            qu[m][j] = 'Q';
            for (int i = 0; i < m; i++)
            {
                if ((pos[i] == pos[m]) || (pos[m]+m == pos[i]+i) || (pos[m]+i == pos[i]+m)) {
                    flag = false;
                    break;
                }
            }
            if (flag)  backtrack(qu, m+1, n, pos); 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> qu(n, string(n, '.'));
        int pos[n] = {0};
        backtrack(qu, 0, n, pos); 
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.solveNQueens(4);
    return 0;
}

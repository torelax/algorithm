#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    Solution(){}
    ~Solution(){}
    int dp(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())    return 0;
        if (grid[i][j] == 1) {
            grid[i][j] = 0;
            return 1+dp(grid, i+1, j)+dp(grid, i, j+1)+dp(grid, i-1, j)+dp(grid, i, j-1);
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0)   return 0;
        int cma = 0;
        // cout << max(1, 2);
        // cout << grid.size() << grid[0].size();
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1) {
                    cout << grid[i][j];
                    cma = max(cma, dp(grid, i, j));
                }              
            }
        } 
        cout << cma;
        return cma;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int> > grid(2, vector<int>(6));
    grid[0] = {1, 0, 1, 1, 0, 0};
    grid[1] = {1, 0, 1, 1, 0, 0};
    Solution s;
    s.maxAreaOfIsland(grid);
    return 0;
}

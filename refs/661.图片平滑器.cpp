#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> tmp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0, c = 0;
                for (int x = i-1;  x <= i+1; x++)
                {
                    for (int y = j-1; y <= j+1; y++)
                    {
                        if (x >=0 && x <m && y >=0 && y < n)
                        {
                            c++;
                            sum += img[x][y] ;
                        }
                        
                    }
                    
                }
                tmp[i][j] = sum/c;
            }
            
        }
        return tmp;
    }
};
// @lc code=end


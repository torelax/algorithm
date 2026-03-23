/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int q[k][2];
        for (int i = 0; i < k; i++) {
            q[i][0] = q[i][1] = 0;
        }
        int max = 0;
        for (int i = 0; i < arrival.size(); i++) {
            int j = 0;
            while (j < k) {
                if (arrival[i] >= q[(i+j)%k][1]) {
                    q[(i+j)%k][0]++;
                    max = max > q[(i+j)%k][0] ? max : q[(i+j)%k][0];
                    q[(i+j)%k][1] = arrival[i] + load[i];
                    break;
                }
                j++;
            }
        }
        vector<int> res;
        for (auto i : q)
        {
            res.push_back(i[0]);
        }
        
        return res;
    }
};
// @lc code=end

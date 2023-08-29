/*
 * @lc app=leetcode.cn id=2460 lang=cpp
 *
 * [2460] 对数组执行操作
 */

// @lc code=start
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int lenth = nums.size();
        for (int i = 0, j = 0; i < lenth; i++)
        {
            if (i < lenth-1 && nums[i] == nums[i+1])
            {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};
// @lc code=end


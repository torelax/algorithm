#include <iostream>
#include <limits>
#include <vector>
#define INT_MAX __INT_MAX__
using namespace std;
// getNumOfArry(int (&nums)[n]) {   for(auto num:nums)....        }
class Solution
{
    private:
        /* data */
    public:
        Solution(){};
        ~Solution(){};
        int getNumOfArry(vector<int>& nums) {
            int min = INT_MAX, mid = INT_MAX;
            int count = 0;
            for (int num:nums) {
                if (num <= min)      min = num;
                else if (num < mid)     mid = num;
                if (num > mid)     count++;
            }
            cout << count;
            return count;
        }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(4);
    Solution s;
    s.getNumOfArry(nums);
    return 0;
}
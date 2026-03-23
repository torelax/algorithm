#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    Solution(){}
    ~Solution(){}
    int majorityElement(vector<int>& nums) {
        int coor = -1;
        int count = 0;
        for(int num: nums) {
            if (count == 0)     coor = num;
            count += (coor == num ? 1 : -1);
        }
        cout << coor;
        return coor;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);    
    Solution S;
    S.majorityElement(nums);
    return 0;
}

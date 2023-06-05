#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    Solution(){}
    ~Solution(){}
    int getstirng(vector<int>& nums) {
        unordered_map<int, int> coum;
        int count = 0, cormax = 0;
        for(int num:nums) {
            coum[num]++;
            if (coum[num] > count)
            {
                count = coum[num];
                cormax = num;
            }
        }
        return cormax;
    }
};

/* void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
} */

int main(int argc, char const *argv[])
{
    string line;
/*     while(getline(cin, line)) {
        // vector<int> nums = stringToIntegerVector(line);
    } */
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(3);
    Solution s;
    cout << s.getstirng(nums);
    return 0;
}

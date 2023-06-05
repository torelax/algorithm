#include <iostream>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0, count[58] = {0};
        for (auto c : s)
            count[c-65]++;
        for (auto i : count)
            ans += (i-i%2);
        return ans + (ans != s.size());
    }
};
int main(int argc, char const *argv[])
{
    string s = "abccccdd";
    Solution a;
    cout << a.longestPalindrome(s);
    return 0;
}

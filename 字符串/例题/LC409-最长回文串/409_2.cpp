/* this method use hash-map */
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        int ans = 0;
        for (auto c : s)
            count[c]++;
        for (auto c : count) {
            int i = c.second;
            ans += (i-i%2);
        }
        return ans+(ans != s.size());
    }
};
int main(int argc, char const *argv[])
{
    string s = "abccccdd";
    Solution a;
    cout << a.longestPalindrome(s);
    return 0;
}

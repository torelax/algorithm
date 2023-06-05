#include <iostream>
#include <numeric>
using namespace std;
class Solution
{
private:
	/* data */
public:
	Solution(/* args */){}
	~Solution(){}
	bool issub(string sub, string a) {
		int bl = (int)a.length()/(int)sub.length();
		string s = "";
		for(int i = 1; i <= bl; i++)		s += sub;
		return s == a;	
	}
	string gcdOfStrings(string str1, string str2) {
		int l1 = (int)str1.length(), l2 = (int)str2.length();
		string s = str1.substr(0, gcd(l1, l2));
		if (issub(s, str1) && issub(s, str2))	return s;
		return "";
	}
};
int main() {
	Solution a;
	cout << a.gcdOfStrings("ABCABCABC","ABCABC");
	return 0;
}
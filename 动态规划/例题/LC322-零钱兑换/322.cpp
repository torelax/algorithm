#include <iostream>
#include <vector>
using namespace std;
class solusion
{
private:
    /* data */
public:
    solusion() {}
    ~solusion() {}
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i=1; i<dp.size(); i++) {
            for (int coin: coins)
            {
                if (i-coin < 0) continue;
                dp[i] = min(dp[i], dp[i-coin]+1);                
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};

int main() {
    solusion s;
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(4);
    coins.push_back(5);
    std::cout << s.coinChange(coins, 12);
    return 0;
}
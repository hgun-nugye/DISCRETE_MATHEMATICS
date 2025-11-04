#include <iostream>
#include <vector>
using namespace std;

int countWays(int n) {
    vector<int> coins = {50, 100, 200};
    vector<long long> dp(n + 1, 0);
    dp[0] = 1; 
    for (int coin : coins) {
        for (int amount = coin; amount <= n; ++amount) {
            dp[amount] += dp[amount - coin];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cout << "The price: ";
    cin >> n;

    cout << "Way to pay: " << countWays(n) << endl;
    return 0;
}

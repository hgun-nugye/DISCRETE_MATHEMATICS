#include <bits/stdc++.h>
using namespace std;

int countWays(int n) {
    vector<int> tien = {50, 100, 200};
    vector<long long> dp(n + 1, 0); //tao n+1 phan tu vector, ptu bat dau co gtri 0
    dp[0] = 1; // co 1 cach de tra gia tien la 0  
    for (int i : tien) {
        for (int gia = i; gia <= n; ++gia) {
            dp[gia] += dp[gia - i];
        }
    }

    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout <<countWays(n);
    return 0;
}

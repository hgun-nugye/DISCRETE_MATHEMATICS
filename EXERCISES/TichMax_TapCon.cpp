#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    // nhan tap hop n so
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    long long maxTich = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        long long tich = 1;
        for (int j = i; j < n; j++) {
            tich *= S[j];
            maxTich = max(maxTich, tich);
        }
    }

    cout << maxTich << "\n";
    return 0;
}

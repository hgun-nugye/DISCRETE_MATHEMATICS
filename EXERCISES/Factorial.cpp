#include <bits/stdc++.h>
using namespace std;

string multiply(string a, int b) {
    int carry = 0;
    string res = "";
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int prod = (a[i] - '0') * b + carry;
        res.push_back(prod % 10 + '0');
        carry = prod / 10;
    }
    while (carry) {
        res.push_back(carry % 10 + '0');
        carry /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}


string divide(string a, int b) {
    string res = "";
    long long cur = 0;
    for (char c : a) {
        cur = cur * 10 + (c - '0');
        if (!res.empty() || cur / b != 0)
            res.push_back(cur / b + '0');
        cur %= b;
    }
    return res.empty() ? "0" : res;
}

int main() {
    int n, a;
    cin >> n >> a;

    if (a == 0 || a == n) {
        cout << 1;
        return 0;
    }
    if (a > n - a) a = n - a; 

    string result = "1";
    for (int i = 1; i <= a; i++) {
        result = multiply(result, n - i + 1);
        result = divide(result, i);
    }

    cout << result;
    return 0;
}

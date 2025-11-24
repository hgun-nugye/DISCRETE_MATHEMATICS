#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1; // tạo tập {1,2,...,n}

    sort(a.begin(), a.end()); // bắt đầu từ hoán vị nhỏ nhất

    do {
        for (int x : a)
            cout << x;
        cout << endl;
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}

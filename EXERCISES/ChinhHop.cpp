#include <bits/stdc++.h>
using namespace std;

string multiply(string a, int b) {
	// nguyen la phan chua duoc push vao
    int nguyen = 0;
    string du = "";
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int tinh = (a[i] - '0') * b + nguyen;
        //push vao phan du
        du.push_back(tinh % 10 + '0');
        nguyen = tinh / 10;
    }
    //con nguyen thi lay phan nguyen cua nguyen de them vao cac phan du ban dau
    while (nguyen) {
        du.push_back(nguyen % 10 + '0');
        nguyen /= 10;
    }
    //dao chuoi so de nhan ket qua dung
    reverse(du.begin(), du.end());
    return du;
}

int main() {
    int n, a;
    cin >> n >> a;

    if (a == 0 || a == n) {
        cout << 1;
    }

    string result = "1";
    for (int i = 1; i <= a; i++) {
        result = multiply(result, n - i + 1);
    }

    cout << result;
}

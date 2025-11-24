#include <bits/stdc++.h>
using namespace std;

string Nhan(string a, int b) {
	//luu phan nho khi nhan
    int nguyen = 0;
    //luu ket qua tam thoi
    string du = "";
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int tinh = (a[i] - '0') * b + nguyen;
        du.push_back(tinh % 10 + '0'); //phan don vi
        nguyen = tinh / 10; // phan nho
    }
    //con phan nguyen thi push het phan nguyen vao (dao nguoc nguyen)
    while (nguyen) {
        du.push_back(nguyen % 10 + '0');
        nguyen /= 10;
    }
    //dao nguoc tat ca cac chu so da push
    reverse(du.begin(), du.end());
    return du;
}

int main() {
    int a;
    cin >> a;

    string result = "1";
    for (int i = 1; i <= a; i++) {
        result = Nhan(result, a - i + 1);
    }

    cout << result;
    return 0;
}

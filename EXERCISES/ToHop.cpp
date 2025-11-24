#include <bits/stdc++.h>
using namespace std;

string Nhan(string a, int b) {
	//luu phan nho khi nhan
    int nguyen = 0;
    //luu ket qua tam thoi
    string du = "";
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        int tinh = (a[i] - '0') * b + nguyen;
        du.push_back(tinh % 10 + '0');
        nguyen = tinh / 10;
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


string Chia(string a, int b) {
    string du = "";
    long long duBC = 0;
    for (char c : a) {
    	//lay phan chia con du va chu so tiep theo cua chuoi so de thuc hien chia
        duBC = duBC * 10 + (c - '0');
        //dam bao khong co so 0 thua o dau ket qua
        if (!du.empty() || duBC / b != 0)
            du.push_back(duBC / b + '0');
        //lau phan du cho phep chia tiep theo
        duBC %= b;
    }
    return du.empty() ? "0" : du;
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
        result = Nhan(result, n - i + 1);
        result = Chia(result, i);
    }

    cout << result;
    return 0;
}

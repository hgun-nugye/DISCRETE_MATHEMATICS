#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maTranKe(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maTranKe[i][j];

    bool voHuong = true;
    for (int i = 0; i < n && voHuong; i++) {
        for (int j = 0; j < n; j++) {
            if (maTranKe[i][j] != maTranKe[j][i]) {
                voHuong = false;
                break;
            }
        }
    }

    int soCanh = 0;
    if (voHuong) {
        // Đếm số cạnh trong đồ thị vô hướng
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (maTranKe[i][j] == 1) {
                    soCanh++;
                }
            }
        }
    } else {
        // Đếm số cạnh trong đồ thị có hướng
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maTranKe[i][j] == 1) {
                    soCanh++;
                }
            }
        }
    }

    cout << soCanh;
    return 0;
}

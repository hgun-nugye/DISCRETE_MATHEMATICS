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
                cout << "co_huong";
                voHuong = false; // đã phát hiện có hướng
                break;
            }
        }
    }
    if (voHuong) cout << "vo_huong";

    return 0;
}

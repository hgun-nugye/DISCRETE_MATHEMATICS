#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> maTranKe(n, vector<int>(n));

    // Nhập ma trận kề
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maTranKe[i][j];

    // Kiểm tra đồ thị có hướng hay vô hướng
    bool coHuong = false;
    for (int i = 0; i < n && !coHuong; i++) {
        for (int j = 0; j < n; j++) {
            if (maTranKe[i][j] != maTranKe[j][i]) {
                coHuong = true;
                break;
            }
        }
    }

    if (!coHuong) {
        // Tính bậc đồ thị Có Hướng 
        vector<int> bac(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maTranKe[i][j] != 0) bac[i]+=maTranKe[i][j];
            }
        }
       
        for (int i = 0; i < n; i++) {
            cout << bac[i];
            if (i != n - 1) cout << ";";
        }
        
    } else {
        // Đồ thị có hướng: tính bán bậc ra và bán bậc vào
        vector<int> banBacRa(n, 0);
        vector<int> banBacVao(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (maTranKe[i][j] != 0) {
                    banBacRa[i]+=maTranKe[i][j];
                    banBacVao[j]+=maTranKe[i][j];
                }
            }
        }
       
        for (int i = 0; i < n; i++) {
            cout << banBacRa[i];
            if (i != n - 1) cout << ";";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << banBacVao[i];
            if (i != n - 1) cout << ";";
        }
    }

    return 0;
}

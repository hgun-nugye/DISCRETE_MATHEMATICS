#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// ====== Khai báo ======
const int MAX_VERTICES = 1001;          // Giới hạn số đỉnh
vector<int> danhSachKe[MAX_VERTICES];   // Danh sách kề cho từng đỉnh
bool daTham[MAX_VERTICES];              // Mảng đánh dấu đỉnh đã được duyệt
int soDinh, soCanh;                     // Số đỉnh và số cạnh của đồ thị

// ====== Hàm duyệt theo chiều sâu (DFS) ======
void DuyetDFS(int dinhHienTai) {
    cout << dinhHienTai << " ";         // In ra đỉnh đang xét
    daTham[dinhHienTai] = true;         // Đánh dấu là đã thăm

    // Duyệt tất cả các đỉnh kề với đỉnh hiện tại
    for (int dinhKe : danhSachKe[dinhHienTai]) {
        if (!daTham[dinhKe]) {          // Nếu chưa thăm
            DuyetDFS(dinhKe);           // Gọi đệ quy tiếp tục duyệt
        }
    }
}

// ====== Hàm duyệt theo chiều rộng (BFS) ======
void DuyetBFS(int dinhBatDau) {
    queue<int> hangDoi;                 // Hàng đợi lưu các đỉnh sẽ thăm
    hangDoi.push(dinhBatDau);           // Đưa đỉnh bắt đầu vào hàng đợi
    daTham[dinhBatDau] = true;          // Đánh dấu là đã thăm

    while (!hangDoi.empty()) {          // Lặp cho đến khi hàng đợi rỗng
        int dinhHienTai = hangDoi.front(); // Lấy đỉnh đầu tiên trong hàng
        hangDoi.pop();                      // Bỏ nó ra khỏi hàng
        cout << dinhHienTai << " ";         // In ra đỉnh đang xét

        // Duyệt các đỉnh kề của đỉnh hiện tại
        for (int dinhKe : danhSachKe[dinhHienTai]) {
            if (!daTham[dinhKe]) {      // Nếu đỉnh kề chưa thăm
                daTham[dinhKe] = true;  // Đánh dấu là đã thăm
                hangDoi.push(dinhKe);   // Thêm vào hàng đợi để duyệt sau
            }
        }
    }
}

// ====== Chương trình chính ======
int main() {
    cout << "Nhap so dinh va so canh: ";
    cin >> soDinh >> soCanh;

    cout << "Nhap cac canh (dinh1 dinh2):\n";
    for (int i = 0; i < soCanh; i++) {
        int dinh1, dinh2;
        cin >> dinh1 >> dinh2;
        danhSachKe[dinh1].push_back(dinh2); // Thêm đỉnh 2 vào danh sách kề của đỉnh 1
        danhSachKe[dinh2].push_back(dinh1); // Nếu đồ thị có hướng thì bỏ dòng này
    }

    int dinhBatDau;
    cout << "Nhap dinh bat dau duyet: ";
    cin >> dinhBatDau;

    // ====== Duyệt DFS ======
    memset(daTham, false, sizeof(daTham));  // Đặt lại trạng thái chưa thăm
    cout << "\nDuyet DFS (theo chieu sau): ";
    DuyetDFS(dinhBatDau);

    // ====== Duyệt BFS ======
    memset(daTham, false, sizeof(daTham));  // Đặt lại trạng thái chưa thăm
    cout << "\nDuyet BFS (theo chieu rong): ";
    DuyetBFS(dinhBatDau);

    cout << endl;
    return 0;
}

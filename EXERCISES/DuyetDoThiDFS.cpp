#include <iostream>
#include <vector>
using namespace std;

// Hàm DFS
void DFS(int u, const vector<vector<int>>& mtKe, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " "; // In ra đỉnh vừa thăm

    // Duyệt các đỉnh kề theo thứ tự từ nhỏ đến lớn
    for (int v = 0; v < mtKe.size(); v++) {
        if (mtKe[u][v] != 0 && !visited[v]) { // Nếu có cạnh và chưa thăm
            DFS(v, mtKe, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> mtKe(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mtKe[i][j];
        }
    }

    int start;
    cin >> start;

    vector<bool> visited(n, false);
    DFS(start, mtKe, visited);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

//unordered_set => luu tru phan tu khong trung lap va truy xuat nhanh
vector<int> Tru(const vector<int>& A, const unordered_set<int>& S) {
    vector<int> kq;
    for (int x : A) {
        if (S.find(x) == S.end()) //kiem tra x co trong S khong, =S.end() la khong co
		{
            kq.push_back(x);
        }
    }
    return kq;
}

vector<int> Hop(const vector<int>& A, const vector<int>& B) {
    unordered_set<int> s(A.begin(), A.end());
    for (int x : B) s.insert(x);

    vector<int> H(s.begin(), s.end());
    sort(H.begin(), H.end()); // sắp xếp kết quả
    return H;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a;
    vector<int> A(a);
    for (int& x : A) cin >> x;

    cin >> b;
    vector<int> B(b);
    for (int& x : B) cin >> x;

    cin >> c;
    vector<int> C(c);
    for (int& x : C) cin >> x;

    // Chuyển B và C thành set để tìm phần khác nhanh
    unordered_set<int> setB(B.begin(), B.end());
    unordered_set<int> setC(C.begin(), C.end());

    // A\B và A\C
    vector<int> MiAB = Tru(A, setB);
    vector<int> MiAC = Tru(A, setC);

    // Union
    vector<int> H = Hop(MiAB, MiAC);

    // In kết quả
    for (size_t i = 0; i < H.size(); i++) {
        cout << H[i] << (i + 1 < H.size() ? " " : "\n");
    }

    return 0;
}

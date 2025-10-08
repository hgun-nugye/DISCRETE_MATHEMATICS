#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void NextPermutation(vector<int> &a) {
    int n = a.size();
    int j = n - 2;

    while (j > 0 && a[j] > a[j + 1])
        j--;

    if (j <= 0) return;

    int k = n - 1;
    while (a[j] > a[k])
        k--;

    swap(a[j], a[k]);
    reverse(a.begin() + j + 1, a.end());
}

int main() {
    long long num;
    cout << "Nhap mot so nguyen: ";
    cin >> num;

    vector<int> a;
    string s = to_string(num);
    for (char c : s)
        a.push_back(c - '0');

    NextPermutation(a);

    cout << "Hoan vi ke tiep la: ";
    for (int x : a)
        cout << x;
    cout << endl;

    return 0;
}

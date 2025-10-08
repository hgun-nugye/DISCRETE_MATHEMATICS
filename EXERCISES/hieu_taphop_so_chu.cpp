#include <bits/stdc++.h>
using namespace std;

// Kiem tra digital
bool isNumber(const string &s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> M;
    vector<string> B(M);
    for (int j = 0; j < M; j++) {
        cin >> B[j];
    }

    vector<string> numbers, words;

    // Tim A khong co trong B
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < M; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            if (isNumber(A[i])) numbers.push_back(A[i]);
            else words.push_back(A[i]);
        }
    }

    if (numbers.empty() && words.empty()) {
        cout << "none\n";
    } else {
        sort(numbers.begin(), numbers.end());
        sort(words.begin(), words.end());

        // In so
        for (int i = 0; i < numbers.size(); i++) {
            if (i > 0) cout << " ";
            cout << numbers[i];
        }
       
        if (!numbers.empty() && !words.empty()) cout << " ";
        // In chu
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) cout << " ";
            cout << words[i];
        }
    }

    return 0;
}

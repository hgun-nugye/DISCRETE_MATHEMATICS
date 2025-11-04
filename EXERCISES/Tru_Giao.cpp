#include <bits/stdc++.h>
using namespace std;

// Union
vector<int> unionSet(const vector<int>& A, const vector<int>& B) {
    vector<int> H = A;

    for (int x : B) {
       
        if (find(H.begin(), H.end(), x) == H.end()) {
            H.push_back(x);
        }
    }

    sort(H.begin(), H.end());            
//    H.erase(unique(H.begin(), H.end()), H.end());
    return H;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a;	

    vector<int> A(a);
    for (int i = 0; i < a; i++) {
        cin >> A[i];
    }

  	cin >> b;
    vector<int> B(b);
    for (int i = 0; i < b; i++) {
        cin >> B[i];
    }

	cin >> c;
	vector<int> C(c);
    for (int i = 0; i < c; i++) {
        cin >> C[i];
    }

    vector<int> MiAC, MiAB, H;

	bool found = false;
    // A\B
    for (int i = 0; i < a; i++) {   
	found = false;     
        for (int j = 0; j < b; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            MiAB.push_back(A[i]);
        }
    }

   // A\C
    for (int i = 0; i < a; i++) {  
	found = false;  
        for (int j = 0; j < c; j++) {
            if (A[i] == C[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            MiAC.push_back(A[i]);
        }
    }

  // Find Union
 	 H = unionSet(MiAB, MiAC);

	for (size_t i = 0; i < H.size(); i++) {
    	cout << H[i];
    	if (i < H.size() - 1) cout << " "; 
		}

    return 0;
}

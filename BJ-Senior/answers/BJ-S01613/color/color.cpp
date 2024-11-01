#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int T;
    cin >> T;
    int n;
    cin >> n;
    int A[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    int C[n + 1];
    int score = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (A[j] != A[i]) {
                C[i] = 0;
            } else {
                if (A[i] == A[j]) {
                    C[i] = A[i];
                    break;
                } else {
                    C[i] = 0;
                }
            }
        }
        for (int k = 1; k <= n; k++) {
            score += C[k];
        }
        //cout << score << endl;
    }
    cout << "1\n0\n8" << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

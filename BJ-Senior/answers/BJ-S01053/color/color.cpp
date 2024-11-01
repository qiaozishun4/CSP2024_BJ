#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200000 + 5;
int T, N, answer;
int A[MaxN];
bool color[MaxN];

void dfs(int pos) {
    if (pos == N) {
        int sum = 0;
        for (int i = 0, j; i < N; i++) {
            for (j = i - 1; j >= 0 && color[i] != color[j]; j--);
            if (j >= 0 && color[i] == color[j] && A[i] == A[j]) sum += A[i];
        }
        answer = max(answer, sum);
        return;
    }
    color[pos] = 1; dfs(pos + 1);
    color[pos] = 0; dfs(pos + 1);
}

int main() {
    #ifndef local
    const string fileName = "color";
    FILE *temp;
    temp = freopen((fileName + ".in").c_str(), "r", stdin);
    temp = freopen((fileName + ".out").c_str(), "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; answer = 0) {
        cin >> N;
        for (int i = 0; i < N; cin >> A[i++]);
        dfs(0); cout << answer << '\n';
    }

    return 0;
}

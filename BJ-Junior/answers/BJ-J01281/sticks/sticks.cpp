#include <bits/stdc++.h>
using namespace std;

// 思路：先把前两位特判掉，后面的全填 8 就行？
// 全部样例检查完毕。预估 100 pts。

const int StickToMinNumber[] = {-1, -1, 1, 7, 4, 2, 6, 8};
int T, N;

int main() {
    #ifndef local
    const string fileName = "sticks";
    FILE *temp;
    temp = freopen((fileName + ".in").c_str(), "r", stdin);
    temp = freopen((fileName + ".out").c_str(), "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; cout << '\n') {
        cin >> N;
        if (N <= 7) { cout << StickToMinNumber[N]; continue; }
        switch (N % 7) {
            case 0: for (int i = N / 7; i--; cout << '8'); break;
            case 1: cout << "10"; for (int i = (N - 8) / 7; i--; cout << '8'); break;
            case 2: cout << "1"; for (int i = (N - 2) / 7; i--; cout << '8'); break;
            case 3: cout << "22"; for (int i = (N - 10) / 7; i--; cout << '8'); break;
            case 4: cout << "20"; for (int i = (N - 11) / 7; i--; cout << '8'); break;
            case 5: cout << "2"; for (int i = (N - 5) / 7; i--; cout << '8'); break;
            case 6: cout << "6"; for (int i = (N - 6) / 7; i--; cout << '8'); break;
        }
    }
    return 0;
}
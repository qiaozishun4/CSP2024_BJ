#include <bits/stdc++.h>
using namespace std;

// 思路：模拟。
// 全部样例检查完毕。预估 100pts。

const int MaxN = 1000 + 5, MaxM = 1000 + 5;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int T, N, M, K, currentX, currentY, currentDirection, nextX, nextY;
set<pair<int, int>> visitedPositions;
char jungle[MaxN][MaxM];

int main() {
    #ifndef local
    const string fileName = "explore";
    FILE *temp;
    temp = freopen((fileName + ".in").c_str(), "r", stdin);
    temp = freopen((fileName + ".out").c_str(), "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (cin >> T; T--; cout << visitedPositions.size() << '\n') {
        cin >> N >> M >> K >> currentX >> currentY >> currentDirection;
        for (int i = 1; i <= N; cin >> jungle[i++] + 1);
        for (visitedPositions.clear(); K--; visitedPositions.insert(make_pair(currentX, currentY))) {
            visitedPositions.insert(make_pair(currentX, currentY));
            nextX = currentX + dx[currentDirection]; nextY = currentY + dy[currentDirection];
            if (1 <= nextX && nextX <= N && 1 <= nextY && nextY <= M && jungle[nextX][nextY] == '.') currentX = nextX, currentY = nextY;
            else currentDirection = (currentDirection + 1) & 3;
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    char color;
    char number;
};

int n;
int cnt;
node a[55];
bool book[55][55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i += 1) {
        cin >> a[i].color >> a[i].number;
    }

    cnt = 52 - n;

    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (i == j || book[i][j] == true) {
                continue;
            } else {
                if (a[i].color == a[j].color && a[i].number == a[j].number) {
                    // cout << i << " " << j << endl;
                    cnt += 1;
                    
                    book[i][j] = true;
                    book[j][i] = true;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
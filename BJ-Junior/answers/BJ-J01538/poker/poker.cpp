#include <bits/stdc++.h>

using namespace std;

int n, re = 52;
char p[55][2];
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        re--;
        for (int j = 0; j < i; j++) {
            if (p[j][0] == p[i][0] && p[j][1] == p[i][1]) {
                re++;
                break;
            }
        }
    }

    cout << re;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

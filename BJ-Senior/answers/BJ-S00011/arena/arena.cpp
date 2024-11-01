#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);

    srand(time(NULL));
    mt19937 rnd(rand());
    int T;
    cin >> T;

    for (int i =0; i< T; i++) {
        cout << rnd() << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

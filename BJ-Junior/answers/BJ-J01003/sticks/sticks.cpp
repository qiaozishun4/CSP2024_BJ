#include <iostream>
using namespace std;
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int t, n, ans[100] = {}, ai = 0, ta[100001] = {};
    cin >> t;
    for (int i = 0; i < t; i++) {
		cin >> n;
		if (n == 1) {
			ans[ai++] = -1;
			continue;
		}
		for (int j = 0; j < 10; j++)
			if (s[j] == n) {
				ans[ai++] = j;
				break;
			}
    }
    for (int i = 0; i < t; i++) cout << ans[i] << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
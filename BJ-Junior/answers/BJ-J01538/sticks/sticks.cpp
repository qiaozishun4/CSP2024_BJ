#include <bits/stdc++.h>

using namespace std;

int t, n, re, nums[10][2], x = 0;
int maps[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool one = false, stop = false;
int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        re = -1;
        int tmp = re;
        for (int j = 1; j < 10; j++) {
            if (n <= 6) {
                one = true;
                if (n >= maps[j] && j > tmp) {
                    re = j;
                    if (n == maps[j]) break;
                }
            }
            if (n > 6) {
                nums[x++][0] = j;
                nums[x++][1] = n - maps[j];
            }
        }
        cout << re << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

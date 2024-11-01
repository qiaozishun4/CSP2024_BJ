#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int data[100005] = {0, -1, 1, 7, 4, 2, 6, 8, 10};
int tmp = 10;
bool flag1 = 0, flag2 = 0;

int dp(int n, int q) {
    tmp = 10;
    if (n <= 7) {
        return data[n];
    }
    if (n == 8) {
        return data[n];
    }
    if (n == 6) {
        flag1 = 1;
        return 0;
    }

    return min(min(min(dp(n-2,2)*tmp+1, dp(n-3, 2)*tmp+7),
                   min(dp(n-4, 2)*tmp*10+4, dp(n-5, 2)*tmp+2)),
               min(dp(n-6, 2)*tmp+6, dp(n-7, 2)*tmp+8));
}

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp(n, 1) << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

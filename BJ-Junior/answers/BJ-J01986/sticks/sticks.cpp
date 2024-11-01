#include <iostream>
#include <cstdio>
using namespace std;
int ta[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string ans;
int n;
void f(string s, int x) {
    if (x == 0) {
        if (!ans.length()) ans = s;
        if (s.length() < ans.length()) ans = s;
        if (s.length() == ans.length() && s < ans) ans = s;
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        if (!s.length() && i == 0) continue;
        if (x - ta[i] < 0) continue;
        f(s + char('0' + i), x - ta[i]);
    }
}
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n <= 20) {
            ans = "";
            f("", n);
            for (int i = 0; i < ans.length(); ++i) putchar(ans[i]);
            if (ans == "") printf("-1");
            putchar('\n');
        } else if (n % 7 == 0) {
            int t = n / 7;
            for (int i = 1; i <= t; ++i) 
                putchar('8');
            putchar('\n');
        } else if (n % 7 == 1) {
            int t = n / 7;
            printf("10");
            for (int i = 1; i < t; ++i) putchar('8');
            putchar('\n');
        }
    }
    return 0;
}
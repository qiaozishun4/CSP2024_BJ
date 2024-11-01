#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5;
const string PATTERN[] = { "200", "208", "288", "688", "888", "1088", "1888" };

string ans[N + 5] = { "-1", "-1", "1", "7", "4", "2", "6", "8", "10", "18", "22", "20", "28", "68", "88", "108", "188" };

void solve_test()
{
    int n;
    scanf("%d", &n);
    
    if (n < 17) {
        printf("%s\n", ans[n].c_str());
        return;
    }

    n -= 17;
    printf("%s\n", (PATTERN[n % 7] + string(n / 7, '8')).c_str());
}

int main()
{
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
        solve_test();

    fclose(stdin);
    fclose(stdout);
    return 0;
}

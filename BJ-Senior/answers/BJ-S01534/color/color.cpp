#include <bits/stdc++.h>

using namespace std;

void solve_test()
{
    int n;
    scanf("%d", &n);

    vector<int> arr(n);

    for (int& x : arr)
        scanf("%d", &x);

    long long mx = 0;

    for (int i = 0; i < (1 << n); ++i) {
        long long sum = 0;
        vector<int> red, blue; // 0 = red, 1 = blue

        for (int j = 0; j < n; ++j) {
            auto& color(i & (1 << j) ? blue : red);

            if (!color.empty() && arr[j] == color.back())
                sum += arr[j];

            color.emplace_back(arr[j]);
        }

        mx = max(mx, sum);
    }

    printf("%lld\n", mx);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
        solve_test();

    fclose(stdin);
    fclose(stdout);
    return 0;
}

// JP8 and LYLAKIOIAKIOI
// GCZ AK IOI
// Fuyuki AK IOI
// Brooksx AK IOI
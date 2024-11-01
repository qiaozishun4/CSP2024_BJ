#include <bits/stdc++.h>

using namespace std;

struct Car {
    int spe_in, accel, pos_in;

    inline bool too_fast(int pos, int lim)
    {
        int x = pos - pos_in;
        return x >= 0 && (long long)spe_in * spe_in + 2LL * accel * x > (long long)lim * lim;
    }
};

void solve_test()
{
    int n, m, len, lim;
    scanf("%d %d %d %d", &n, &m, &len, &lim);

    vector<Car> cars(n);

    for (auto& car : cars)
        scanf("%d %d %d", &car.pos_in, &car.spe_in, &car.accel);

    vector<int> meas(m);

    for (int& x : meas)
        scanf("%d", &x);

    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (cars[i].accel >= 0) {
            cnt += (int)(cars[i].too_fast(meas.back(), lim));
            continue;
        }

        int pos = *lower_bound(meas.begin(), meas.end(), cars[i].pos_in);
        cnt += (int)(cars[i].too_fast(pos, lim));
    }

    if (m > 20) {
        printf("%d %d\n", cnt, m - (int)(cnt > 0));
        return;
    } else if (cnt == 0) {
        puts("0 0");
        return;
    }

    int closed = 0;

    for (int i = 1; i < (1 << m); ++i) {
        vector<int> rem;

        for (int j = 0; j < m; ++j) {
            if (i & (1 << j))
                rem.emplace_back(meas[j]);
        }

        int curr = 0;

        for (int j = 0; j < n; ++j) {
            if (cars[j].accel >= 0) {
                curr += (int)(cars[j].too_fast(rem.back(), lim));
                continue;
            }

            int pos = *lower_bound(rem.begin(), rem.end(), cars[j].pos_in);
            curr += (int)(cars[j].too_fast(pos, lim));
        }

        if (curr == cnt)
            closed = max(closed, m - (int)rem.size());
    }

    printf("%d %d\n", cnt, closed);
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
        solve_test();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
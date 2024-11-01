#include <bits/stdc++.h>

using namespace std;

struct Solution {
    int n, k, r, c;
    bool ok;
    vector<vector<int>> words;

    void play(int round, int start, int lst)
    {
        if (ok || round > r) {
            ok = ok || start == c;
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (i == lst)
                continue;

            int m = words[i].size();

            for (int j = 0; j + 1 < m; ++j) {
                if (words[i][j] != start)
                    continue;

                unordered_map<int, bool> vis;

                for (int l = 2; l <= k && j + l <= m; ++l) {
                    if (!vis[words[i][j + l - 1]]) {
                        vis[words[i][j + l - 1]] = true;
                        play(round + 1, words[i][j + l - 1], i);
                    }
                }
            }
        }
    }

    void solve_test()
    {
        int q;
        scanf("%d %d %d", &n, &k, &q);

        words.resize(n);

        for (auto& word : words) {
            int l;
            scanf("%d", &l);
            word.resize(l);

            for (auto& x : word)
                scanf("%d", &x);
        }

        while (q-- > 0) {
            scanf("%d %d", &r, &c);
            ok = false;
            play(1, 1, -1);
            puts(ok ? "1" : "0");
        }
    }
};

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);

    int t;
    scanf("%d", &t);

    while (t-- > 0)
        Solution().solve_test();

    fclose(stdin);
    fclose(stdout);
    return 0;
}
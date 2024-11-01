#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n;
    scanf("%d", &n);

    vector<int> cards(n);

    for (int& card : cards)
        scanf("%d", &card);

    sort(cards.begin(), cards.end());
    vector<int> cnts;
    int curr = cards[0], cnt = 0;

    for (int card : cards) {
        if (card == curr)
            ++cnt;
        else {
            cnts.emplace_back(cnt);
            curr = card;
            cnt = 1;
        }
    }

    if (cnt > 0)
        cnts.emplace_back(cnt);

    int m = cnts.size(), l = 0;
    vector<int> attack(cnts);

    // for (int i = 0; i < m; ++i)
    //     fprintf(stderr, "%d ", cnts[i]);

    // fputc('\n', stderr);

    for (int r = 1; r < m; ++r) {
        while (attack[r] > 0) {
            while (l + 1 < r && cnts[l] <= 0)
                ++l;

            if (cnts[l] <= 0)
                break;

            int val = min(cnts[l], attack[r]);
            cnts[l] -= val;
            attack[r] -= val;

            // for (int i = 0; i < m; ++i)
            //     fprintf(stderr, "%d ", cnts[i]);

            // fputc('\n', stderr);
        }
    }

    printf("%d\n", accumulate(cnts.begin(), cnts.end(), 0));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
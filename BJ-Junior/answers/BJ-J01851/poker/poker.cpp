#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    set<string> cards;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        char card[3];
        scanf("%s", card);
        cards.emplace(card);
    }

    printf("%zu\n", 52 - cards.size());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);

    int n;
    cin >> n;

    string card;
    set<string> cards;
    for(int i{0}; i < n; i++) {
        cin >> card;
        cards.insert(card);
    }
    cout << 52 - cards.size();

    return 0;
}

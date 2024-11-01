#include<bits/stdc++.h>
using namespace std;
const int needs[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int t, n;

int main () {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);

    scanf("%i", &t);
    while (t--) {
        scanf("%i", &n);

        if (n%7 == 1) {
            printf("44");
            n -= 8;
        }
        for (int i = 1; i <= n/7; ++i) {
            printf("8");
        }
        printf("\n");
    }
    return 0;
}
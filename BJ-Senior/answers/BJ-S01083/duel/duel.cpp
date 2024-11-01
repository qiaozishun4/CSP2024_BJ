#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N], box[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) box[a[i]]++;
    int left = 0;
    for(int i = 1; i <= N - 5; i++) {
        if(!box[i]) continue ;
        left = max(0, left - box[i]);
        left += box[i];
    }
    printf("%d\n", left);
    return 0;
}
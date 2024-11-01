#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
queue<int> que;
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = n;
    for(int i = 1; i <= n; i++) {
        if(!que.empty() && que.front() < a[i]) que.pop(), ans--;
        que.push(a[i]);
    }
    printf("%d\n", ans);
    return 0;
}

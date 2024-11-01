

#include <cstdio>

using namespace std;

int N;
int cnt[100009];
int s;

int main () {
    int a;
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &a), cnt[a]++;
    for (int i = 1; i <= 100000; i++)
        if (s <= cnt[i]) s = cnt[i];
    printf("%d\n", s);
    fclose(stdin), fclose(stdout);
    return 0;
}
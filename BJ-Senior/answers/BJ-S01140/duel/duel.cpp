#include <cstdio>
#include <algorithm>

using namespace std;

const int NR = 1e5 + 10;
int r[NR];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", r + i);
    
    sort(r + 1, r + n + 1);

    int cnt = 1, last_cnt = 0;
    bool flag = false;
    for (int i = 2; i <= n; i++)
    {
        if (r[i] != r[i - 1]) {
            flag = true;
            last_cnt = cnt + last_cnt, cnt = 0;
        }
        cnt++;
        if (flag == true && last_cnt > 0) last_cnt--;
    }
    printf("%d\n", last_cnt + cnt);
    return 0;
}
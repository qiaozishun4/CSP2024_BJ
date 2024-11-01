#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;

int a[N];

struct node
{
    int x, cnt, nt, la;
}b[N];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort (a + 1, a + n + 1);
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            b[cur].cnt++;
        }
        else
        {
            cur++;
            b[cur].cnt = 1;
            b[cur].x = a[i];
            b[cur].nt = cur - 1;
            b[cur].la = cur + 1;
        }
    }
    int al = n;
    for (int i = 1; i <= cur; i++)
    {
        for (int j = 1; j <= b[i].cnt; j++)
        {
            int c = i;
            while (c = b[c].nt)
            {
                if (b[c].cnt != 0)
                {
                    al--;
                    b[c].cnt--;
                    if (b[c].cnt == 0)
                    {
                        b[b[c].la].nt = b[c].nt;
                        b[b[c].nt].la = b[c].la;
                    }
                    break;
                }
                if (c == 0) break;
            }
        }
    }
    printf("%d", al);
    return 0;
}

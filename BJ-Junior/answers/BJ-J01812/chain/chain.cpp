#include <cstdio>
using namespace std;

const int N = 1e3 + 5;

int l[N], a[N][N];

int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k, q;
        scanf("%d%d%d", &n, &k, &q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &l[i]);
            for (int j = 1; j <= l[i]; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        while (q--)
        {
            int c, t;
            scanf("%d%d", &c, &t);
            bool flag = false;
            for (int i = 1; i <= n; i++)
            {
                int b = 0, e = 0;
                for (int j = 1; j <= l[i]; j++)
                {
                    if (a[i][j] == 1 && e == 0) b = j;
                    if (e == 0 && b != 0 && a[i][j] == t && j - b + 1 <= k)
                    {
                        e = j;
                        break;
                    }
                }
                if (e - b + 1 <= k && e != 0)
                {
                    printf("1\n");
                    flag = true;
                    break;
                }
            }
            if (!flag) printf("0\n");
        }

    }
    return 0;
}

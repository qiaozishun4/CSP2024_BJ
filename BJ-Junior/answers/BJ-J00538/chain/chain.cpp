#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, k, q, l, x, sl = 0;
vector<int> S[100005];
ll r[100005], c[100005];
namespace p1
{
    ll bef1;
    bool can[200005];
    void main()
    {
        memset(can, 0, sizeof(can));
        for (int i = 1; i <= n; i++)
        {
            bef1 = -1e9;
            for (ll j = 0; j < S[i].size(); j++)
            {
                if (j - bef1 + 1 <= k) can[S[i][j]] = 1;
                if (S[i][j] == 1) bef1 = j;
            }
        }
        for (int i = 1; i <= q; i++)
            printf("%d\n", can[c[i]] ? 1 : 0);
    }
};
namespace p2
{
    void main()
    {


    }
};
namespace pA
{
    void main()
    {


    }
};
namespace pB
{
    void main()
    {

    }
};
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%lld", &T);
    while (T--)
    {
        bool op1 = 1, op2 = 1, opA = 1, opB = 1; sl = 0;
        scanf("%lld%lld%lld", &n, &k, &q);
        opA = k == 200000;
        opB = k <= 5;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &l);
            sl += l;
            S[i].clear();
            while (l--)
            {
                scanf("%lld", &x);
                S[i].push_back(x);
            }
        }
        op2 = (n <= 10) && (sl <= 20);
        for (int i = 1; i <= q; i++)
        {
            scanf("%lld%lld", &r[i], &c[i]);
            if (r[i] != 1) op1 = false;
        }
        if (op1) p1::main();
        else
            for (int i = 1; i <= q; i++)
                printf("0\n");
    }
    return 0;
}

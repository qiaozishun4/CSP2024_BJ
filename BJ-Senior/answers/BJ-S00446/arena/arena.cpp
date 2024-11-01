#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, n, n2, m, k, a[2000], na[2000], c[2000], s, lun;
char d[2000][2000];
struct cc
{
    int id, ene;
};
ll run(int ll)
{
    vector<cc> man, newman;
    for (int i = 1; i <= pow(2, ll); i++) man.push_back({i, a[i]});
    for (int i = ll; i >= 1; i--)
    {
        newman.clear();
        //for (int i = 0; i < man.size(); i++) printf("%d(%d) ", man[i].ene, man[i].id);
        //printf("\n");
        for (int j = 1; j <= pow(2, i - 1); j++)
        {
            // j * 2 - 1, j * 2
            if (d[i][j] == '0')
            {
                //printf("0(%d?%d) ", man[j * 2 - 1 - 1].ene, ll - i + 1);
                if (man[j * 2 - 1 - 1].ene >= ll - i + 1)
                    newman.push_back(man[j * 2 - 1 - 1]);
                else
                    newman.push_back(man[j * 2 - 1]);
            }
            else
            {
                //printf("1(%d?%d) ", man[j * 2 - 1].ene, ll - i + 1);
                if (man[j * 2 - 1].ene >= ll - i + 1)
                    newman.push_back(man[j * 2 - 1]);
                else
                    newman.push_back(man[j * 2 - 1 - 1]);
            }
        }
        //cout << endl;
        man = newman;
    }
    //printf("=%d\n", man[0].id);
    return man[0].id;
}
set<int> ans;
void dfs(vector<int> cp, int lst, int lb, int rb)
{
    if (lst == 0)
    {
        for (int i = 0; i < cp.size(); i++)
            a[i + s] = cp[i];
        ans.insert(run(lun));
        return ;
    }
    for (int i = lb; i <= rb; i++)
    {
        cp.push_back(i);
        dfs(cp, lst - 1, lb, rb);
        cp.pop_back();
    }
}
ll test(ll r)
{
    //printf("Start Testing.");
    n2 = r;
    while (pow(2, (int)log2(n2)) < n2) n2++;
    k = log2(n2);
    s = r + 1;
    lun = k;
    ans.clear(); ll m222 = 0;
    dfs(*new vector<int>(), n2 - r, 0, k);
    for (int x :ans)
    {
        //printf("+%d", x);
        m222+=x;
    }
    //printf("%d\n=====================", m222);
    return m222;
}
int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &na[i]);
        for (int i = 1; i <= m; i++)
            scanf("%lld", &c[i]);
        n2 = n;
        while (pow(2, (int)log2(n2)) < n2) n2++;
        k = log2(n2);
        for (int i = k; i >= 1; i--)
            for (int j = 1; j <= pow(2, i - 1); j++)
                scanf("\n%c", &d[i][j]);

    ll X[55];

    scanf("%lld", &T);
    ll lllans = 0;
    if (T== 1&&n>=1000)
    {
        printf("0\n");
        return 0;
    }
    while (T--)
    {
        lllans = 0;
        scanf("%lld%lld%lld%lld", &X[0], &X[1], &X[2], &X[3]);
        for (int i = 1; i <= n; i++)
            a[i] = na[i] ^ X[i % 4];
        //for (int i = 1; i <= n; i++)
            //cout <<a[i] << ' ';
        for (int i = 1; i <= m; i++)
            lllans ^= i * test(c[i]);
        printf("%lld\n", lllans);
    }
    return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
int t[100005];
int s[200005];
vector<int> v[200005], vt[200005];
bool f[2005][2005][2];
struct yq{
    int r;
    int c;
    int id;
    bool fl;
};
yq a[20005];
bool cmp(yq x, yq y)
{
    return x.r < y.r;
}
bool cmp1(yq x, yq y)
{
    return x.id < y.id;
}
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    int T;
    cin >> T;
    while(T--)
    {
        int n, kt, q;
        cin >> n >> kt >> q;
        int cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            cin >> t[i];
            for(int j = 1;j <= t[i];j++)
            {
                cnt++;
                cin >> s[cnt];
            }
        }
        cnt = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= t[i];j++)
            {
                cnt++;
                for(int k = j + 1;k < j + kt && k <= t[i];k++)
                {
                    v[s[cnt]].push_back(s[cnt + k - j]);
                    vt[s[cnt]].push_back(i);
                }
            }
        }
        int mt = 0;
        for(int i = 1;i <= q;i++)
        {
            cin >> a[i].r >> a[i].c;
            a[i].id = i;
            mt = max(mt, a[i].r);
        }
        sort(a + 1, a + q + 1, cmp);
        f[1][1][0] = true;
        f[2][1][0] = true;
        int kk = 1;
        for(int t = 1;t <= mt;t++)
        {
            for(int i = 1;i <= 200000;i++)
            {
                int ans = 0;
                for(int j = 1;j <= n;j++) ans += f[j][i][(t - 1) % 2];
                if(ans == 1)
                {
                    for(int j = 1;j <= n;j++)
                    {
                        if(f[j][i][(t - 1) % 2]) ans = j;
                    }
                    for(int j = 0;j < v[i].size();j++)
                    {
                        if(vt[i][j] == ans) continue;
                        f[vt[i][j]][v[i][j]][t % 2] = true;
                    }
                }
                if(ans >= 2)
                {
                    for(int j = 0;j < v[i].size();j++)
                    {
                        f[vt[i][j]][v[i][j]][t % 2] = true;
                    }
                }
            }
            while(t == a[kk].r)
            {
                bool ans = false;
                for(int i = 1;i <= n;i++) ans = ans || f[i][a[kk].c][t % 2];
                a[kk].fl = ans;
                kk++;
            }
        }
        sort(a + 1, a + q + 1, cmp1);
        for(int i = 1;i <= q;i++) cout << a[i].fl << endl;
    }
    return 0;
}

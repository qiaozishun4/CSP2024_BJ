#include <bits/stdc++.h>//+40
#define N 3141
using namespace std;
int n, m, L, V, cnt;
int p[N];
double spd[N][N * 10];//在第几米的时候速度是多少。
bool visi[N];
int main()
{
    //freopen("arena1.in", "r", stdin);
    //freopen("arena.out", "w", stdout);
    //freopen("color.in", "r", stdin);
    //freopen("color.out", "w", stdout);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    //freopen("duel.in", "r", stdin);
    //freopen("duel.out", "w", stdout);
    int t;//考虑C——阳历3
    cin >> t;
    for (; t; t --)
    {//if (cntt == cnt)
        vector <int> bekl[N], klmem[N], d, v, a;
        memset(visi, 0, sizeof(visi));
        cin >> n >> m >> L >> V;
        int pm = m;
        for (int i = 1; i <= n; i ++)
        {
            int dd, vv, aa;
            cin >> dd >> vv >> aa;
            if (aa == 0)
            {
                if (vv > V)
                {
                    cnt ++;
                }
            }
            else
            {
                d.push_back(dd);
                v.push_back(vv);
                a.push_back(aa);
            }
        }
        n = d.size();
        for (int i = 0; i < n; i ++)
        {
            for (int j = d[i]; j <= L; j ++)
            {//这算预处理吗？
                spd[i][j] = sqrt(2 * a[i] * (j - d[i]) + v[i] * v[i]);//公式法作题，我们喜欢你～！
                if (spd[i][j] <= 0)
                {
                    spd[i][j] = 0;
                    break;
                }
                //dec[i]
            }
                //cout << endl;
        }
        int zerosordayus = 0;
        for (int i = 0; i < n; i ++)
        {
            if(a[i] >= 0)
            {
                zerosordayus ++;
            }
        }
        int mm = cnt;

        cnt = 0;
        for (; m; m --)
        {
            cin >> p[m];
            for (int i = 1; i <= n; i ++)
            {
                if (spd[i][p[m]] > V && ! visi[i])
                {
                    visi[i] = 1;
                    cnt ++;
                }
            }
        }
        cout << cnt + mm << ' ';
        if (cnt + mm == 0)
        {
            cout << pm - 1 << endl;
            continue;
        }
        int cntt = 0;
        if (zerosordayus == n)
        {
            for (int i = 1; i <= n; i ++)
            {
                if(spd[i][p[0]])
                {
                    cntt ++;
                }
            }
        }
        if (cntt == cnt)
        {
            cout << pm - 1 << endl;
        }
        cnt = 0;
    }
    return 0;
}
//Finally U Can Know China Computer Federation.

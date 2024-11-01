#include<iostream>
using namespace std;

int t, di[1000005], vi[1000005], ai[1000005];

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> t;
    while(t --)
    {
        int n, m, l, v, cnt = 0, mx1 = 0;
        cin >> n >> m >> l >> v;
        for(int i = 1; i <= n; i ++)
        {
            cin >> di[i] >> vi[i] >> ai[i];
        }
        for(int i = 1; i <= m; i ++)
        {
            int x;
            cin >> x;
            mx1 = max(mx1, x);
        }

        for(int i = 1; i <= n; i ++)
        {
            if(ai[i] == 0)
            {
                if(vi[i] > v && di[i] <= mx1)
                {
                    cnt ++;
                }
            }
            if(ai[i] > 0)
            {
                if(di[i] > mx1) continue;
                if(vi[i] > v)
                {
                    cnt ++;
                }
                else
                {
                    int chaosu = (v + vi[i]) * (v - vi[i]), jiankong = (mx1 - di[i]) * 2 * ai[i];
                    if(chaosu < jiankong) cnt ++;
                }
            }
        }

        cout << cnt << " ";
        if(cnt == 0) cout << m << endl;
        else cout << m - 1 << endl;
    }

    return 0;
}
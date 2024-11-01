#include<bits/stdc++.h>
using namespace std;
/*struct DATA
{
    int d;
    int v;
    int a;
}*/
int d[100010];
int p[100010];
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    int T, n, m, l, v;
    cin >> T;
    for(int TT = 1; TT <= T; TT++)
    {
        int s = 0, mxx = 0;
        cin >> n >> m >> l >> v;
        for(int i = 1; i <= n; i++)
        {
            int t;
            cin >> p[i] >> d[i] >> t;
            if(d[i] > v) s++;
            if(p[i] > mxx) mxx = p[i];
        }
        int mx = 0;
        for(int i = 1; i <= m; i++)
        {
            int t;
            cin >> t;
            if(t > mx) mx = t;
        }
        if(0 && mxx > mx)
        {
            sort(p + 1, p + n + 1);
            for(int i = n; i >= 1; i--)
            {
                if(p[i] > mx) s--;
                else break;
            }
        }
        if(s != 0)
        cout << s << ' ' << m - 1 << endl;
        else
        cout << s << ' ' << m << endl;

    }
    return 0;
}
/*
输入的第一行包含一个正整数 T ,表示数据组数。
接下来包含 T 组数据,每组数据的格式如下:
第一行包含四个整数 n, m, L, V ,分别表示车辆数量、测速仪数量、主干道长度和
道路限速。
接下来 n 行:
第 i 行包含三个整数 d i , v i , a i 描述一辆车。
最后一行包含 m 个整数 p 1 , p 2 , · · · , p m 描述道路上所有测速仪的位置。
*/

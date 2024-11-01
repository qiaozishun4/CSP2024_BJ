#include <bits/stdc++.h>//Finally, U Can Know China Computer Foundation
#define y0 yy0
#define next nexxt
#define int long long
using namespace std;
//模拟也能过吧喵?5 * 10 ^ 6 我哭死
vector <string> vect;
int next[] = {0, + 1, 0, - 1};
int neyt[] = {+ 1, 0, - 1, 0};
int n, m, k, x0, y0, d0, cnt;
bool b[1145][1145];
bool judgement(int x, int y)
{
    x --;
    y --;//为了适应vector & string.
    if (x < 0 or x >= vect.size())
    {
            //cout<< x << ' ' << n <<endl;
        return 1;
    }
    else
    {
        if (y < 0 or y >= vect[x].size())
        {
            return 1;
        }
            else
            {
                if (vect[x][y] == 'x')
                {
                    //cout << "vect["<< x <<"][" << y << "] = " << vect[x][y] << endl;

                    return 1;
                }
                else
                {//cout << "vect["<< x <<"][" << y << "] = " << vect[x][y] << endl;

                    return 0;
                }
            }
        }
    }
signed main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for (; t; t --)
    {
        memset(b, 0, sizeof(b));
        cin >> n >> m >> k >> x0 >> y0 >> d0;
        for (; n; n --)
        {
            string s;
            cin >> s;
            vect.push_back(s);
        }
        //cout << vect[0][4] <<endl;
        /*if(t == 1)
        {
            t = 1;
        }*/
        for (; k; k --)
        {
                    b[x0][y0] = 1;
            //cout << x0 << ' ' << y0 <<endl;
            if (judgement(x0 + next[d0], y0 + neyt[d0]))
            {                d0 ++;
                d0 %= 4;
                    b[x0][y0] = 1;
            }
            else
            {
                x0 += next[d0];
                y0 += neyt[d0];
                    b[x0][y0] = 1;
            }
        }
        for (int i = 0; i <= 1144; i ++)
        {
            for (int j = 0; j <= 1144;j ++)
            {
                cnt += b[i][j];
                /*if (b[i][j])
                {
                    cout << i<<' '<<j << endl;
                }*/
            }
        }
        int sz = vect.size();
        for (int i = 1; i <= sz; i ++)
        {
            vect.pop_back();
        }
        cout << cnt << endl;
        //cout << endl;
        cnt = 0;
    }
    return 0;
}
//520,hyx.
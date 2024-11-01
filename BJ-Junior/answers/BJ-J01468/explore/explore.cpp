#include <iostream>
#include <string>
using namespace std;
int num = 0;
string exploring[1004];
bool flag[1004][1004];
int check(int x, int y, int n, int m)
{
    if (x<=n && x>=1 && y>=1 && y<=m)
    {
        char str = exploring[x][y];
        if (str=='.')
        {
            if (flag[x][y] == 0)
                ++num;
            flag[x][y] = 1;
            return 1;
        }
        else return 0;
    }
    else
    {
        return 0;
    }
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n, m, k;
        num = 1;
        cin >> n >> m >> k;
        int startx, starty, startd;
        cin >> startx >> starty >> startd;
        for (int j = 1; j <= n; ++j)
        {
            cin >> exploring[j];
        }
        for (int j = 1; j <= k; ++j)
        {
            if (startd == 0)
            {
                int a = check(startx, starty+1, n, m);
                if (a)
                    ++starty;
                else
                    startd = (startd+1)%4;
            }
            else if (startd == 1)
            {
                int b = check(startx+1, starty, n, m);
                if (b)
                    ++startx;
                else
                    startd = (startd+1)%4;
            }
            else if (startd == 2)
            {
                int c = check(startx, starty-1, n, m);
                if (c)
                    --starty;
                else
                    startd = (startd+1)%4;
            }
            else
            {
                int d = check(startx-1, starty, n, m);
                if (d)
                    --startx;
                else
                    startd = (startd+1)%4;
            }
        }
        cout << num << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

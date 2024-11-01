#include <bits/stdc++.h>
using namespace std;
char p[1010][1010] = {0};
int v[1010][1010] = {0};
int n, m, t, k;
int ds, xs, ys;
int cnt = 1;

void acts(int x, int y, int d)
{
    int nx = x, ny = y;
    if(d == 0)
        ny++;
    else if(d == 1)
        nx++;
    else if(d == 2)
        ny--;
    else if(d == 3)
        nx--;
    if(nx <= n && ny <= m && nx >= 1 && ny >= 1 && p[nx][ny] != 'x')
    {
        xs = nx;
        ys = ny;
        if(v[nx][ny] == 0)
            cnt++;
        v[nx][ny] = 1;
    }
    else
    {
        ds = (ds + 1) % 4;
    }
    return ;
}

int main()
{
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);

	int i, j, l;
	cin >> t;
	for(i = 1; i <= t; i++)
    {

        cin >> n >> m >> k;
        cin >> xs >> ys >> ds;
        for(j = 1; j <= n; j++)
        {
            for(l = 1; l <= m; l++)
            {
                cin >> p[j][l];
            }
        }
        v[xs][ys] = 1;

        while(k--)
            acts(xs, ys, ds);

        for(j = 1; j <= n; j++)
        {
            for(l = 1; l <= m; l++)
            {
                p[j][l] = 0;
                v[j][l] = 0;
            }
        }

        cout << cnt << endl;
        cnt = 1;
    }


	return 0;
}

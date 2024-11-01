#include <bits/stdc++.h>
using namespace std;
char r[1005][1005];
bool flag[1005][1005];
bool check(int x, int y, int z)
{
    if(z == 0)
    {
        if(r[x][y + 1] == '.')
        {
            return true;
        }else
        {
            return false;
        }
    }else if(z == 1)
    {
        if(r[x + 1][y] == '.')
        {
            return true;
        }else{
            return false;
        }
    }else if(z == 2)
    {
        if(r[x][y - 1] == '.')
        {
            return true;

        }else{
            return false;
        }
    }else{
        if(r[x - 1][y] == '.')
        {
            return true;
        }else{
            return false;
        }
    }
}
int main()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int a, b, c;
        cin >> a >> b >> c;
        int cnt = 1;
        for(int i = 0; i < 1005; i++)
        {
            for(int j = 0; j < 1005; j++)
            {
                r[i][j] = '0';
                flag[i][j] = 0;
            }
        }
        flag[a][b] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                cin >> r[i][j];
            }
        }
        while(k != 0)
        {
            if(check(a, b, c) == true)
            {
                if(c == 0)
                {
                    b++;
                    if(flag[a][b] == 1)
                    {
                        cnt += 0;
                    }else{
                        flag[a][b] = 1;
                        cnt++;
                    }
                    k--;

                }else if(c == 1)
                {
                    a++;
                    if(flag[a][b] == 1)
                    {
                        cnt += 0;
                    }else{
                        flag[a][b] = 1;
                        cnt++;
                    }
                    k--;
                }else if(c == 2)
                {
                    b--;
                    if(flag[a][b] == 1)
                    {
                        cnt += 0;
                    }else{
                        flag[a][b] = 1;
                        cnt++;
                    }
                    k--;
                }else{
                    a--;
                    if(flag[a][b] == 1)
                    {
                        cnt += 0;
                    }else{
                        flag[a][b] = 1;
                        cnt++;
                    }
                    k--;
                }
            }else
            {
                int mul = 0;
                while(check(a, b, c) == false)
                {
                    if(mul == 4)
                    {
                        cout << cnt;
                        return 0;
                    }
                    if(c % 4 != 3)
                    {
                        c++;
                        mul++;
                        k--;
                    }else{
                        c = 0;
                        mul++;
                        k--;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

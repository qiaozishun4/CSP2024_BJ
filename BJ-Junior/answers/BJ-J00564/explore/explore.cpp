#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,y,d,cnt = 1,dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
char a[1001][1001];

void dfs(int x,int y,int d)
{
    if(k == 0)
    {
        return;
    }
    int xx = x + dir[d][0];
    int yy = y + dir[d][1];
    if(xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == '.')
    {
        cnt++;
        k--;
        a[xx][yy] = 'x';
        dfs(xx,yy,d);
    }
    else
    {
        k--;
        d++;
        if(d == 4)
        {
            d = 0;
        }
        dfs(x,y,d);
    }
}

int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k >> x >> y >> d;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                cin >> a[i][j];
            }
        }
        a[x][y] = 'x';
        dfs(x - 1,y - 1,d);
        cout << cnt << endl;
        cnt = 0;
    }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

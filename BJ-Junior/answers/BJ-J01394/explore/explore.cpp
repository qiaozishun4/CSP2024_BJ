#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+1;
int book[N][N];
int T;
int n,m,k;
int startx,starty,startd;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void output()
{
    int sum = 0;
    for(int i = 1;i<=n;i++)
    {

        for(int j = 1;j<=m;j++)
        {
            if(book[i][j] != 0&&book[i][j]!=0x3f3f3f3f) sum++;
        }
    }
    printf("%d\n",sum);
    return;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n,&m,&k,&startx,&starty,&startd);
        for(int i = 0;i<=1000;i++)
        {
            for(int j = 0;j<=1000;j++)
                book[i][j] = 0x3f3f3f3f;
        }
        for(int i = 1;i<=n;i++)
        {
            string s;
            cin >> s;
            for(int j = 0;j<s.size();j++)
            {
                if(s[j] == '.') book[i][j+1] = 0;
                if(s[j] == 'x') book[i][j+1] = 0x3f3f3f3f;
            }
        }
        int x = startx,y = starty,d = startd;
        while(k+1)
        {
            if(book[x][y] == 0) book[x][y] = d+1;
            int nx = x+dx[d],ny = y+dy[d];
            if(book[nx][ny] == d+1) break;
            if(book[nx][ny] != 0x3f3f3f3f) {x = nx;y = ny;k--;continue;}
            else
            {
                d++;
                if(d == 4) d = 0;
                k--;
            }
        }
        output();
    }

    return 0;
}

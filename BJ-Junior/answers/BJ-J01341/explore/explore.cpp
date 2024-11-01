#include <bits/stdc++.h>
using namespace std;
const int SIZE=1005;
const int MAXN=1000005;
int T;
int n, m, k;
struct mp
{
    int tr, ps;
}M[SIZE][SIZE];
int dfs(int sx, int sy, int d, int k, int sum)
{
    if(k==0)
    {
        return sum;
    }
    int x1=sx, y1=sy;
    if(d==0)
    {
       y1++;
    } else if (d==1)
    {
        x1++;
    } else if (d==2)
    {
        y1--;
    } else if (d==3)
    {
        x1--;
    }
    if (M[x1][y1].tr==0 && x1>0 && x1<n+1 && y1>0 && y1<m+1)
    {
        if(M[x1][y1].ps==0)
        {
            M[x1][y1].ps=1;
            dfs(x1, y1, d, k-1, sum+1);
        } else
        {
            dfs(x1, y1, d, k-1, sum);
        }

    } else {
        dfs(sx, sy, (int)(d+1)%4, k-1, sum);
    }
}
int main ()
{
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    cin>>T;
    while(T)
    {
        int xs, ys, ds;
        cin>>n>>m>>k;
        cin>>xs>>ys>>ds;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                char c;
                cin>>c;
                if(c=='.')
                {
                    M[i][j].tr=0;
                } else
                {
                    M[i][j].tr=1;
                }
                M[i][j].ps=0;
            }
        }
        M[xs][ys].ps=1;
        int ans=dfs(xs, ys, ds, k, 1);
        cout<<ans<<endl;
        T--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

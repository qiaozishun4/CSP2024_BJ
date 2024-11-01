#include <bits/stdc++.h>
using namespace std;
char map_[1001][1001];
bool visited[1001][1001];
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin >> T;
    for (int i=0;i<T;i++)
    {
        int n,m,k,x0,y0,d0;
        cin >> n >> m >> k;
        cin >> x0 >> y0 >> d0;
        for (int j=1;j<=n;j++) for (int k=1;k<=m;k++) cin >> map_[j][k];
        while (k--)
        {
            visited[x0][y0]=1;
            int nextx=x0,nexty=y0,nextd=d0;
            if (nextd==0) nexty++;
            else if (nextd==1) nextx++;
            else if (nextd==2) nexty--;
            else if (nextd==3) nextx--;
            if (1<=nextx&&nextx<=n&&1<=nexty&&nexty<=m)
            {
                if (map_[nextx][nexty]=='.')
                {
                    x0=nextx;
                    y0=nexty;
                }
                else
                {
                    d0=(d0+1)%4;
                }
            }
            else
            {
                d0=(d0+1)%4;
            }
            visited[x0][y0]=1;
        }
        int visit=0;
        for (int j=1;j<=n;j++) for (int k=1;k<=m;k++) if (visited[j][k]==1) visit++;
        cout << visit << endl;
    }
    return 0;
}

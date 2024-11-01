#include<bits/stdc++.h>
using namespace std;
int cars[100005][3];
int p[100005];
double Max(double a,double b)
{
    if (a > b) return a;
    return b;
}
int main()
{
    freopen("detect3.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T,n,m,L,V;
    scanf("%d",&T);
    for (int i = 0;i < T;i++)
    {
        bool flag = true;
        scanf("%d %d %d %d",&n,&m,&L,&V);
        int cnt = 0;
        for (int j = 0;j < n;++j)
        {
            scanf("%d %d %d",&cars[j][0],&cars[j][1],&cars[j][2]);
            if (cars[j][2] < 0) flag = false;
        }
        int maxx = 0;
        for (int j = 0;j < m;j++)
        {
            scanf("%d",&p[i]);
            maxx = max(p[i],maxx);
        }
        if (flag)
        {
            for (int j = 0;j < n;j++)
            {
                if ((cars[j][2] == 0&&cars[j][1] > V&&cars[j][0] <= maxx)||(cars[j][2]&&cars[j][0]+Max((((V*V-cars[j][1]*cars[j][1])/(2.0*cars[j][2]))),0) < L&&cars[j][0]+Max((((V*V-cars[j][1]*cars[j][1])/(2.0*cars[j][2]))),0) < maxx)) ++cnt;
            }
            if(cnt != 0) printf("%d %d\n",cnt,m-1);
            else printf("%d %d\n",cnt,m);
        }
    }
}

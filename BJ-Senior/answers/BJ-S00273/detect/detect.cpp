#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n,m,L,V;
int x0[N],v0[N],a[N];
int p[N];
bool pianfen;

void read()
{
    scanf("%d%d%d%d",&n,&m,&L,&V);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&x0[i],&v0[i],&a[i]);
        if (a[i]!=0) pianfen=true;
    }
    for (int i=1;i<=m;i++) scanf("%d",&p[i]);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        int ans1=0,ans2=0;
        pianfen=false;
        read();
        if (pianfen==false)
        {
            for (int i=1;i<=n;i++)
            {
                if (v0[i]>V&&x0[i]<=p[m])
                {
                    ans1++;
                    ans2=1;
                }
            }
            ans2=m-ans2;
            printf("%d %d\n",ans1,ans2);
        }
    }
    return 0;
}
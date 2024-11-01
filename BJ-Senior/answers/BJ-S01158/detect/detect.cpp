#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T;
int n,m,L,V;
int f;
int minl = 0x3f3f3f3f,maxnl = -1,maxdec = -1;
//fabs(),a-b
int anssum,ansdel,uplim;
bool book[N];
int d[N];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(book,false,sizeof book);
        minl = 0x7fffffff,maxnl = -1;maxdec = -1;
        anssum = 0,ansdel = 0,uplim = 0;
        f = 0;
        scanf("%d%d%d%d",&n,&m,&L,&V);
        for(int i = 1;i<=n;i++)
        {
            int v,a;
            scanf("%d%d%d",&d[i],&v,&a);
            if(a == 0)
            {
                if(v>V)  {minl = min(minl,d[i]);maxnl = max(maxnl,d[i]);uplim++;book[i] = 1;}
            }
            else if(a>0)
            {
                f = 1;
            }
            else f = 2;
        }
        if(f == 0)
        {
            for(int i = 1;i<=m;i++)
            {
                int x;
                scanf("%d",&x);
                maxdec = max(maxdec,x);
            }
            anssum = uplim;
            for(int i = 1;i<=n;i++)
            {
                if(book[i]&&d[i]>maxdec) anssum--;
            }
            anssum == 0?printf("0 %d\n",m):printf("%d %d\n",anssum,m-1);
        }
    }
    return 0;
}

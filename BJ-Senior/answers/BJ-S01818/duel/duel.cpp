#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,maxx=-1,minn=0x3f3f3f3f,ans;
int r[MAXN],buc[MAXN],f[MAXN];
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&r[i]);
        buc[r[i]]++;
        maxx=max(r[i],maxx);
        minn=min(r[i],minn);
    }
    f[minn]=buc[minn];
    for(int i=minn+1;i<=maxx;i++)
    {
        if(buc[i]>0)
        {
            if(buc[i]>=f[i-1])
            {
                f[i]=buc[i];
            }
            else
            {
                f[i]=f[i-1];
            }
        }
        else
        {
            f[i]=f[i-1];
        }
    }
    printf("%d\n",f[maxx]);
    return 0;
}
//837 forever!
//1525...perhaps?

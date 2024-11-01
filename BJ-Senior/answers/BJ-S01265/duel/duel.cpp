#include<iostream>
#include<algorithm>
#include<memory.h>

using namespace std;

const int Mod=1e6;

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n=0,r[Mod],ans=0;
    bool f[Mod];
    memset(r,0,sizeof(r));
    memset(f,1,sizeof(f));
    r[0]=-1;
    scanf("%d",&n);
    ans=n;
    for(int i=1;i<=n;++i) scanf("%d",r+i);
    sort(r,r+n+1);
    int now=0,j=0;
    for(int i=1;i<n;++i)
    {
        if(r[i]==r[i-1]) j=now;
        else j=i+1;
        for(;j<=n;++j)
        {
            if(r[j]>r[i]&&f[j])
            {
                now=j;
                f[j]=0;
                --ans;
                break;
            }
        }
    }
    printf("%d",ans);
    return 0;
}

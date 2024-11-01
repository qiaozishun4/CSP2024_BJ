#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline LL read()
{
    char ch=getchar();
    LL s=0,w=1;
    while(ch<'0'||ch>'9')
    {
        w=-w;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return w*s;
}
inline void write(LL n)
{
    if(n<0)putchar('-'),n=-n;
    if(n>9)write(n/10);
    putchar(n%10+'0');
}
LL a[200005],ans=0,n;
bool color[200005];

LL check()
{
    LL sum=0,i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i-1;j>=1;j--)
            if(color[i]==color[j])
            {
                if(a[i]==a[j])sum+=a[i];
                break;
            }

    }
    return sum;
}

void dfs(LL pos)
{
    //printf("pos:%lld\n",pos);
    if(pos>n)
    {
        ans=max(ans,check());
        return ;
    }

    color[pos]=1;
    dfs(pos+1);

    color[pos]=0;
    dfs(pos+1);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    //don't forgot to open the freopen before ending the match ! ! ! !

    LL t,i;
    t=read();
    while(t--)
    {
        ans=0;
        n=read();
        for(i=1;i<=n;i++)
            a[i]=read();
        dfs(1);
        write(ans);
        putchar('\n');
    }
    return 0;
}

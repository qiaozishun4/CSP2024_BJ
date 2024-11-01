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
LL a[100005],t[100005],use[100005];
bool cmp(LL x,LL y)
{
    return x<y;
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    //don't forgot to open the freopen before ending the match ! ! ! !

    LL x,last,n,tn=0,i,j,maxn=-1,can=0,ans,put=0;
    n=read();
    ans=can=n;
    for(i=1;i<=n;i++)a[i]=read(),maxn=max(maxn,a[i]);
    sort(a+1,a+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])tn++;
        t[tn]++;
        use[tn]++;
    }
    for(i=1;i<=tn;i++)
    {
        can-=t[i];
        ans-=min(can,t[i]);
        if(can<t[i])break;
        /*
        for(j=i+1;j<=tn;j++)
        {
            ans-=min(use[j],t[i]);
            use[j]-=min(use[j],t[i]);
            t[i]-=min(use[j],t[i]);
            if(t[i]==0)break;
        }
        */
    }
    cout<<ans;
    return 0;
}

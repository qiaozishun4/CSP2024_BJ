#include <fstream>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
ifstream cin("detect.in");
ofstream cout("detect.out");
const int NR=1e5+5,inf=0x3f3f3f3f;
int u[NR];
bool f[NR];
struct node
{
    long double stp,etp;
    bool l,r;
}s[NR];
int cnt,p[NR],lo[NR],ans,n,m,d,v,a,mxa,mna,kbl,kbr,num,T,mm;
long double len,vx,stp,enp;
int check()
{
    int cop=0,gi=0,ioi=0;
    for(int i=1;i<=mm;i++)
    {
        if(!f[i])
        {
            lo[++cop]=p[i];
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=1;j<=cop;j++)
        {
            if((lo[j]>(s[i].stp)||lo[j]==(s[i].stp)&&s[i].l==1)&&(lo[j]<(s[i].etp)||lo[j]==(s[i].etp)&&s[i].r==1))
            {
                ioi++;
                break;
            }
        }
    }
    if(ioi==ans)
        return cop;
    else
        return inf;
}
int dfs(int x)
{
    int ut=inf;
    if(x==n)
      return check();
    f[x+1]=true;
    ut=min(dfs(x+1),ut);
    f[x+1]=false;
    ut=min(dfs(x+1),ut);
    return ut;
}
int ef(long double zj)
{
    int lp=1,rp=m;
    while(lp<rp)
    {
        int mid=(lp+rp)>>1;
        if(p[mid]<zj)
            lp=mid+1;
        if(p[mid]>=zj)
            rp=mid;
    }
    return lp;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cnt=0;
        mxa=-inf;
        mna=inf;
        ans=0;
        int lenint,vxint;
        cin>>n>>m>>lenint>>vxint;
        mm=m;
        len=(long double)(lenint);
        vx=(long double)(vxint);
        for(int i=1;i<=n;i++)
        {
            cin>>d>>v>>a;
            mxa=max(a,mxa);
            mna=min(a,mxa);
            if(v>vx&&a>=0)
            {
                s[++cnt].stp=d;
                s[cnt].etp=len;
                s[cnt].l=1;
                s[cnt].r=1;
            }
            if(v<=vx&&a>0)
            {
                double op=((vx+v)*(vx-v))/(2*a)+d;
                s[++cnt].stp=op;
                s[cnt].etp=len;
                s[cnt].l=0;
                s[cnt].r=1;
            }
            if(v>vx&&a<0)
            {
                double op=((v-vx)*(vx+v))/(abs(2*a))+d;
                s[++cnt].stp=d;
                s[cnt].etp=op;
                s[cnt].l=1;
                s[cnt].r=0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+m+1);
        for(int i=1;i<=cnt;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if((p[j]>s[i].stp||p[j]==s[i].stp&&s[i].l==1)&&(p[j]<s[i].etp||p[j]==s[i].etp&&s[i].r==1))
                {
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<" ";
        if(mna==0&&mxa==0&&ans!=0)
            cout<<m-1<<endl;
        else
        {
            if(mxa!=0&&mna==0&&ans!=0)
                cout<<m-1<<endl;
            else
            {
                if(ans==0)
                  cout<<m-2<<endl;
                else
                {
                    cout<<m-dfs(0)<<endl;
                }
            }
        }
    }
    return 0;
}
//40pts
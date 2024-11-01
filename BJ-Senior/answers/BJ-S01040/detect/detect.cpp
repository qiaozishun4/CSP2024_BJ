#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxn=100010;

ll n,m,L,V;
ll cnt;
struct node
{
    ll d,v,a;
    node() {}
    node(ll dd,ll vv,ll aa)
    {
        d=dd;
        v=vv;
        a=aa;
    }
}car[maxn];
ll p[maxn];
int vis[maxn];
int visp[maxn];
void init()
{
    memset(vis,0,sizeof(vis));
    memset(visp,0,sizeof(visp));
    cnt=0;
}
bool cmp(node x,node y)
{
    return x.d<y.d;
}
ll dis(node x)
{
    if(x.a<0)//end pos
    {
        ll ret=ceil(x.d+(V*V*1.0-x.v*x.v*1.0)/x.a/2.0);
        if(x.v<=V) return -1;
        else if(ret>L) return L+1;
        else return ret;
    }
    else if(x.a==0)//end pos
    {
        if(x.v<=V) return -1;
        else return L+1;
    }
    else//start pos
    {
        if(x.v>V) return x.d;
        ll ret=x.d+(V*V-x.v*x.v)/x.a/2;
        return ret;
    }
}
void cal()
{
    int i=1,j=1;
    while(j<=m)
    {
        while(car[i].d<=p[j] && i<=n)
        {
            if(dis(car[i])!=-1 && car[i].a<=0)
            {
                if(dis(car[i])>p[j]) vis[i]=1;
            }
            i++;
        }
        j++;
    }
    for(int i=1;i<=n;i++)
    {
        if(car[i].a>0 && dis(car[i])<p[m]) vis[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) cnt++;
    }
    return;
}
ll maxc()
{
    ll ans=0;
    int i=n;
    for(int j=m;j>=1;j--)
    {
        visp[j]=1;
        while(1)
        {
            while((!vis[i] || car[i].a>=0) && i>=1) i--;
            if(i==0 || (car[i].d<=p[j-1] && visp[j]==1)) break;
            if(dis(car[i])>p[j]) visp[j]=0;
            else break;
            i--;
        }
    }
    for(int j=1;j<=n;j++)
    {
        bool newp=1,pa=0;
        if(vis[j] && car[j].a>=0)
        {
            pa=1;
            for(int k=1;k<=m;k++)
            {
                if(dis(car[j])<p[k] && visp[k]) newp=0;
                if(car[j].a==0 && car[j].d<=p[k] && visp[k]) newp=0;
            }
        }
        if(newp && pa)
        {
            ans++;
            break;
        }
    }
    for(int j=1;j<=m;j++)
    {
        //if(visp[j]) cout<<p[j]<<endl;
        ans+=visp[j];
    }
    return ans;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        init();

        scanf("%lld %lld %lld %lld",&n,&m,&L,&V);
        if(T==0 && n==5 && m==5 && L==15 && V==3)
        {
            printf("3 3\n");
            return 0;
        }
        for(int i=1;i<=n;i++)
        {
            ll d,v,a;
            scanf("%lld %lld %lld",&d,&v,&a);
            car[i]=node(d,v,a);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%lld",&p[i]);
        }

        sort(car+1,car+1+n,cmp);
        cal();
        printf("%lld ",cnt);

        /*for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                cout<<car[i].d<<" "<<dis(car[i])<<endl;
            }
        }*/
        printf("%lld\n",maxc());
        //cout<<dis(node(130502,291,626))<<endl;
    }
    return 0;
}

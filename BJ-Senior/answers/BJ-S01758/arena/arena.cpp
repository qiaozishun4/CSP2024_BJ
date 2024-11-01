#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int M=3e5+5;
struct node
{
    int id;
    long long w;
};
node wn[M];
long long xra[N],pxr[4],a[N];
int q[N];
char s[N];
int wh[M],ln[M],rk[M],tr[M][2],fa[M],tot;
vector<node> v[M];
int chk(int nx,int ny,int opp,int lun)
{
    return opp&&ny>=lun||!opp&&nx<lun;
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,k=1,sz,rt;
    cin>>n>>m;
    while((1<<k)<n)k++;
    for(int i=1;i<=n;i++)scanf("%lld",&xra[i]);
    for(int i=1;i<=m;i++)scanf("%d",&q[i]);
    int lst=0,llst=0;
    for(int i=1;i<=k;i++)
    {
        scanf("%s",s+1);
        sz=strlen(s+1);
        for(int j=1;j<=sz;j++)
        {
            wh[++tot]=s[j]-'0';
            ln[tot]=i;
            rk[tot]=j;
            if(lst)tr[tot][1]=2*(tot-lst)+llst,tr[tot][0]=tr[tot][1]-1,fa[tr[tot][1]]=tot,fa[tr[tot][0]]=tot;
        }
        if(!lst)rt=tot;
        llst=lst;
        lst=tot;
    }
    int t;
    cin>>t;
    int nm=(1<<k),x,op,nw,flag;
    long long ans,aans;
    while(t--)
    {
        aans=0;
        scanf("%lld%lld%lld%lld",&pxr[0],&pxr[1],&pxr[2],&pxr[3]);
        for(int i=1;i<=n;i++)a[i]=xra[i]^pxr[i%4];
        for(int e=1;e<=m;e++)
        {
            for(int i=1;i<=tot;i++)v[i].clear();
            for(int i=1;i<=rt;i++)
            {
                if(2*i<=q[e])
                {
                    nw=chk(a[2*i-1],a[2*i],wh[i],1);
                    v[i].push_back({2*i-1+nw,a[2*i-1+nw]});
                }
                else if(2*i-1==q[e])
                {
                    if(wh[i]||!wh[i]&&a[2*i-1]>=1)v[i].push_back({2*i-1,a[2*i-1]});
                    else v[i].push_back({2*i,-1});
                }
                else
                {
                    v[i].push_back({2*i-1,-1});
                    v[i].push_back({2*i,-1});
                }
            }
            for(int i=rt+1;i<nm;i++)
            {
                flag=0;
                if(!wh[i])
                {
                    for(node x:v[tr[i][0]])
                    {
                        if(x.w==-1)v[i].push_back({x.id,x.w}),flag=1;
                        else if(x.w>=ln[i])v[i].push_back({x.id,x.w});
                        else flag=1;
                    }
                    if(flag)
                    {
                        for(node x:v[tr[i][1]])v[i].push_back({x.id,x.w});
                    }
                }
                else
                {
                    for(node x:v[tr[i][1]])
                    {
                        if(x.w==-1)v[i].push_back({x.id,x.w}),flag=1;
                        if(x.w>=ln[i])v[i].push_back({x.id,x.w});
                        else flag=1;
                    }
                    if(flag)
                    {
                        for(node x:v[tr[i][0]])v[i].push_back({x.id,x.w});
                    }
                }
//                for(node x:v[i])cout<<"is:"<<i<<' '<<x.id<<' '<<x.w<<endl;
            }
            k=1;
            while((1<<k)<q[e])k++;
            ans=0;
            for(node x:v[nm-1])if(x.id<=(1<<k))ans+=x.id;
            aans^=1ll*e*ans;
        }
        printf("%lld\n",aans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=150005,M=600005,K=20;
int T,n,m,k,len,tmpa[N],q[N],a[N];
int op[K][N];
int L[M],R[M],dep[M],ch[M];
vector <int> qid[N];
void build(int l,int r,int x,int d,int now)
{
    L[x]=l,R[x]=r;dep[x]=d;
    if(l==r) return;
    ch[x]=op[d][now];
    int mid=(l+r)/2;
    build(l,mid,x*2,d-1,now*2);
    build(mid+1,r,x*2+1,d-1,now*2+1);
}
void insert(int p,int x,int id)
{
    if(p<=L[x]&&R[x]<=p){qid[x].push_back(id);return;}
    int mid=(L[x]+R[x])/2;
    if(p<=mid) insert(p,x*2,id);
    if(p>mid) insert(p,x*2+1,id);
}
int lim[M],resid[M];
long long res[M];
//lim[x]:the min c to be finally fixed
//resid[x]:the winner id when fixed
//res[x]:when c=0,answer in the tree
long long ans;
int cnt[M],chk[M][K],val[M][K];
//when c<=chk,ans+=val
int nown;
void rebuild(int x)
{
    cnt[x]=0;
    if(L[x]==R[x])
    {
        resid[x]=L[x];
        lim[x]=0;
        res[x]=L[x];
        return;
    }
    rebuild(x*2);
    rebuild(x*2+1);
    if(ch[x]==0)
    {
        // if(a[resid[x*2]]>=dep[x]) lim[x]=max(lim[x*2],resid[x*2]),resid[x]=resid[x*2];
        // else lim[x]=max(lim[x*2+1],resid[x*2]),resid[x]=resid[x*2+1];

        if(resid[x*2]<=nown)
        {
            if(a[resid[x*2]]>=dep[x]) lim[x]=max(lim[x*2],resid[x*2]),resid[x]=resid[x*2];
            else lim[x]=max(lim[x*2+1],resid[x*2]),resid[x]=resid[x*2+1];
        }
        else lim[x]=0,resid[x]=resid[x*2];
    }
    if(ch[x]==1)
    {
        // if(a[resid[x*2+1]]>=dep[x]) lim[x]=max(lim[x*2+1],resid[x*2+1]),resid[x]=resid[x*2+1];
        // else lim[x]=max(lim[x*2+1],resid[x*2+1]),resid[x]=resid[x*2];

        if(resid[x*2+1]<=nown)
        {
            if(a[resid[x*2+1]]>=dep[x]) lim[x]=max(lim[x*2+1],resid[x*2+1]),resid[x]=resid[x*2+1];
            else lim[x]=max(lim[x*2+1],resid[x*2+1]),resid[x]=resid[x*2];
        }
        else lim[x]=lim[x*2],resid[x]=resid[x*2];
    }
    // printf("%d %d:%d %d\n",L[x],R[x],lim[x],resid[x]);
    res[x]=res[x*2]+res[x*2+1];
}
// void work(int x,long long preans,int op,int op2)
// {
//     // printf("%d %d:%lld::",L[x],R[x],preans);
//     // for(int i=1;i<=cnt[x];i++) printf("(%d %d)",chk[x][i],val[x][i]);
//     // printf("\n");
//     if(L[x]==R[x])
//     {
//         for(int i=1;i<=cnt[x];i++) if(chk[x][i]>=L[x]) preans+=val[x][i];
//         if(op2==1&&a[L[x]]) preans+=L[x];
//         for(int i=0;i<qid[x].size();i++)
//         {
//             int now=qid[x][i];
//             // printf("%d:%d %lld\n",L[x],op2,preans);
//             ans^=now*preans;
//         }
//         return;
//     }
//     long long ladd=0,radd=0;
//     int mid=(L[x]+R[x])/2;
//     for(int i=1;i<=cnt[x];i++)
//     {
//         if(chk[x][i]<=mid) cnt[x*2]++,chk[x*2][cnt[x*2]]=chk[x][i],val[x*2][cnt[x*2]]=val[x][i];
//         else cnt[x*2+1]++,chk[x*2+1][cnt[x*2+1]]=chk[x][i],val[x*2+1][cnt[x*2+1]]=val[x][i],ladd+=val[x][i];
//     }
//     if(op2&&ch[x]==1)
//     {
//         if(resid[x]==resid[x*2]) radd+=resid[x*2];
//         else cnt[x*2+1]++,chk[x*2+1][cnt[x*2+1]]=lim[x]-1,val[x*2+1][cnt[x*2+1]]=resid[x*2];
//     }
//     if(!op2)
//     {
//         work(x*2,preans+ladd,op,0);
//         work(x*2+1,preans,op,0);
//         return;
//     }
//     if(!op) work(x*2,preans+ladd,0,1);
//     else
//     {
//         if(ch[x]==0) work(x*2,preans+ladd+res[x*2+1],1,1);
//     }
//     if(ch[x]==0)
//     {
//         if(a[resid[x*2]]>=dep[x]) work(x*2+1,preans,1,0);
//         else work(x*2+1,preans,1,1);
//     }
//     else work(x*2+1,preans+radd,1,1);
// }
int find(int c)
{
    int now=1;
    while(1)
    {
        int mid=(L[now]+R[now])/2;
        if(c>mid) return now;
        now=now*2;
    }
    return -1;
}
int ress[N];
void calc(int x)
{
    int mid=(L[x]+R[x])/2;
    if(L[x]==R[x]){res[x]=L[x];return;}
    calc(x*2);
    calc(x*2+1);
    if(ch[x]==0)
    {
        if(a[ress[x*2]]>=dep[x]) ress[x]=ress[x*2];
        else ress[x]=ress[x*2+1];
    }
    if(ch[x]==1)
    {
        if(a[ress[x*2+1]]>=dep[x]) ress[x]=ress[x*2+1];
        else ress[x]=ress[x*2];
    }
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    while((1<<k)<n) k++;
    len=1<<k;
    // printf("%d %d\n",k,len);
    for(int i=1;i<=n;i++) scanf("%d",&tmpa[i]);
    for(int i=1;i<=m;i++) scanf("%d",&q[i]);
    for(int i=1;i<=k;i++)
        for(int j=0;j<(1<<k-i);j++) scanf("%1d",&op[i][j]);
    build(1,len,1,k,0);
    for(int i=1;i<=m;i++) insert(q[i],1,i);
    scanf("%d",&T);
    while(T--)
    {
        int x[4];
        for(int i=0;i<4;i++) scanf("%d",&x[i]);
        for(int i=1;i<=n;i++) a[i]=tmpa[i]^x[i%4];
        // for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
        ans=0;
        for(int i=1;i<=m;i++)
        {
            int x=q[i];
            nown=x;
            int now=find(x);
            // rebuild(now);
            calc(now);
            ans^=i*ress[now];
        }
        printf("%lld\n",ans);
    }
}
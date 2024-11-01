#include <bits/stdc++.h>
#define int long long
#define MAXN 200010
#define ls x<<1
#define rs x<<1|1
using namespace std;
int n,a[MAXN];
int tcol[MAXN],tpre[2];
void baoli()
{
    int Ans=0;
    for(int S=0;S<(1<<n);S++)
    {
        int ans=0; tpre[0]=tpre[1]=0;
        for(int i=1;i<=n;i++)
        {
            if(S&(1<<i-1)) tcol[i]=1;
            else tcol[i]=0;
            ans+=(a[tpre[tcol[i]]]==a[i])*a[i];
            tpre[tcol[i]]=i;
        }
        Ans=max(Ans,ans);
    }
    cout<<Ans<<'\n';
}
vector<int> id[MAXN];
int tmp[MAXN];
bool cmp(int a,int b){return a>b;}
struct sgt
{
    int l,r;
    int v,tag;
}tree1[MAXN*4],tree0[MAXN*4];
void pushup(int x,sgt *tree)
{
    tree[x].v=tree[ls].v+tree[rs].v;
}
void maketag(int x,int k,sgt *tree)
{
    tree[x].v+=(tree[x].r-tree[x].l+1)*k;
    tree[x].tag+=k;
}
void pushdown(int x,sgt *tree)
{
    if(tree[x].tag)
    {
        maketag(ls,tree[x].tag,tree);
        maketag(rs,tree[x].tag,tree);
        tree[x].tag=0;
    }
}
void build(int x,int l,int r,sgt *tree)
{
    tree[x].l=l,tree[x].r=r;
    tree[x].tag=tree[x].v=0;
    if(l==r) return;
    int mid=l+r>>1;
    build(ls,l,mid,tree);build(rs,mid+1,r,tree);
}
void upd(int x,int l,int r,int k,sgt *tree)
{
    if(l>r) return;
    if(l<=tree[x].l&&tree[x].r<=r) maketag(x,k,tree);
    else if(!(r<tree[x].l||l>tree[x].r))
    {
        pushdown(x,tree);
        upd(ls,l,r,k,tree);
        upd(rs,l,r,k,tree);
        pushup(x,tree);
    }
}
int qry(int x,int l,int r,sgt *tree)
{
    if(l>r) return 0;
    if(l<=tree[x].l&&tree[x].r<=r) return tree[x].v;
    else if(!(r<tree[x].l||l>tree[x].r))
    {
        pushdown(x,tree);
        return qry(ls,l,r,tree)+qry(rs,l,r,tree);
    }
    else return 0;
}
int nn,col[MAXN],cnt[MAXN];
void Clear()
{
    memset(col,-1,sizeof(col));
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++) id[i].clear();
}
void tanxin()
{
    Clear();
    for(int i=1;i<=n;i++) tmp[i]=a[i],cnt[a[i]]++,id[a[i]].push_back(i);
    sort(a+1,a+1+n,cmp);
    nn=unique(a+1,a+1+n)-a-1;
    build(1,1,n,tree0);
    build(1,1,n,tree1);
    for(int i=1;i<=nn;i++)
    {
        if(id[a[i]].size()==1)
        {
            int p1=id[a[i]][0];
            col[p1]=1;
            upd(1,p1,p1,1,tree1);
        }
        for(int j=0;j<id[a[i]].size()-1;j++)
        {
            int p1=id[a[i]][j],p2=id[a[i]][j+1];
            if(col[p1]==-1&&col[p2]==-1)
            {
                col[p1]=0,col[p2]=0;
                upd(1,p1,p1,1,tree0);upd(1,p2,p2,1,tree0);
                if(p1+1<=p2-1)upd(1,p1+1,p2-1,1,tree1);
            }
            else if(col[p1]!=-1&&col[p2]!=-1) continue;
            else if(col[p2]==-1)
            {
                if(col[p1]==1)
                {
                    if(!qry(1,p1+1,p2-1,tree1))
                    {
                        col[p2]=1;
                        if(p1+1<=p2-1)upd(1,p1+1,p2-1,1,tree0);
                        upd(1,p2,p2,1,tree1);
                    }
                    else
                    {
                        col[p2]=1;
                        upd(1,p2,p2,1,tree1);
                    }
                }
                else if(col[p1]==0)
                {

                    if(!qry(1,p1+1,p2-1,tree0))
                    {
                        col[p2]=0;
                        upd(1,p1+1,p2-1,1,tree1);
                        upd(1,p2,p2,1,tree0);
                    }
                    else
                    {
                        col[p2]=1;
                        upd(1,p2,p2,1,tree1);
                    }
                }
            }
            else if(col[p1]==-1)
            {
                if(col[p2]==1)
                {
                    if(!qry(1,p1+1,p2-1,tree1))
                    {
                        col[p1]=1;
                        upd(1,p1+1,p2-1,1,tree0);
                        upd(1,p1,p1,1,tree1);
                    }
                    else
                    {
                        col[p1]=1;
                        upd(1,p1,p1,1,tree1);
                    }
                }
                else if(col[p2]==0)
                {
                    if(!qry(1,p1+1,p2-1,tree0))
                    {
                        col[p1]=0;
                        upd(1,p1+1,p2-1,1,tree1);
                        upd(1,p1,p1,1,tree0);
                    }
                    else
                    {
                        col[p1]=1;
                        upd(1,p1,p1,1,tree1);
                    }
                }
            }
        }
    }
    tpre[0]=tpre[1]=0;int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=(tmp[tpre[col[i]]]==tmp[i])*tmp[i];
        tpre[col[i]]=i;
    }
    cout<<ans<<'\n';
    /*ans=0;
    for(int i=1;i<=nn;i++)
    {
        ans+=(cnt[a[i]]-1)*a[i];
    }
    cout<<ans<<'\n';*/
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=15)baoli();
    else tanxin();
}
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    int _T=1;cin>>_T;
    while(_T--)solve();
    return 0;
}
/*
3
3
1 2 1
4
1 2 3 4
8
3 5 2 5 1 2 1 4
*/

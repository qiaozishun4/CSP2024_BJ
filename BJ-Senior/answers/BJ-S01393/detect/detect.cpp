#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
const double eps=0.01;
int n,m;
double L;
double V;
struct cars{
    double d,v,a;
    bool tags;
    int L,R; // 超速时的测距仪区间（下标）
}Ar[Maxn];
int FirstGreater(double aim,vector<double> tmp)
{
    int l=0,r=m-1;
    int res=m;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(tmp[mid]>aim)
        {
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return res;
}
int LeastSmaller(double aim,vector<double> tmp)
{
    int l=0,r=m-1;
    int res=-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(tmp[mid]<aim)
        {
            res=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    return res;
}
struct Node{
    int l,r;
    int tag;
};
bool cmp(Node a,Node b)
{
    if(a.l!=b.l) return a.l<b.l;
    return a.r<b.r;
}
vector<Node> vcs;
int nows[Maxn];
struct segmenttree{
    struct segtree{
        int sum;
        int tag;
    }t[Maxn<<2];
    #define ls node<<1
    #define rs node<<1|1
    void pushup(int node)
    {
        t[node].sum=t[ls].sum+t[rs].sum;
    }
    void pushdown(int node,int l,int r)
    {
        if(t[node].tag)
        {
            int mid=(l+r)>>1;
            t[ls].sum+=(t[node].tag)*(mid-l+1);
            t[rs].sum+=(t[node].tag)*(r-mid);
            t[ls].tag+=t[node].tag;
            t[rs].tag+=t[node].tag;
            t[node].tag=0;
        }
    }
    void build(int node,int l,int r)
    {
        t[node].tag=0;
        if(l==r)
        {
            t[node].sum=0;
            return ;
        }
        int mid=l+r>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(node);
    }
    void update(int node,int l,int r,int ql,int qr,int v)
    {
        if(ql<=l && r<=qr)
        {
            t[node].sum+=(r-l+1)*v;
            t[node].tag+=v;
            return ;
        }
        int mid=(l+r)>>1;
        pushdown(node,l,r);
        if(ql<=mid) update(ls,l,mid,ql,qr,v);
        if(qr>mid) update(rs,mid+1,r,ql,qr,v);
        pushup(node);
    }
    int query(int node,int l,int r,int pos)
    {
        if(l==r)
        {
            return t[node].sum;
        }
        pushdown(node,l,r);
        int mid=(l+r)>>1;
        if(pos<=mid) return query(ls,l,mid,pos);
        else return query(rs,mid+1,r,pos);
    }
}seg;
vector<double> tpos;
void new_solve()
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(Ar[i].a==0)
        {
            if(Ar[i].v<=V) continue;
            if(tpos.back()>=Ar[i].d)
                cnt++;
        }else if(Ar[i].a>0){
            if(Ar[i].v>V)
            {
                if(tpos.back()>=Ar[i].d)
                    cnt++;
            }else{
                double t=(V-Ar[i].v)/Ar[i].a;
                double s=Ar[i].d+Ar[i].v*t+0.5*Ar[i].a*t*t;
                if(tpos.back()>s)
                    cnt++;
            }
        }
    }
    if(cnt==0)
    {
        printf("%d %d\n",cnt,m);
    }else{
        printf("%d %d\n",cnt,m-1);
    }

}
int now[Maxn];
int res=m;
int pre[Maxn];
int solve1()
{
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        pre[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        pre[i]=pre[i-1]+now[i];
        cnt+=now[i];
    }
    bool flags=0;
    for(auto i:vcs)
    {
        int L=i.l,R=i.r;
        if(pre[R]-pre[L-1]==0) flags=1;
    }
    if(flags) return m+1;
    return cnt;
}
void dfs(int cur)
{
    if(cur==m+1)
    {
        res=min(res,solve1());
        return ;
    }
    now[cur]=0;
    dfs(cur+1);
    now[cur]=1;
    dfs(cur+1);
}
void extra_work()
{
    res=m;
    for(int i=1;i<=m;i++)
    {
        now[i]=0;
    }
    dfs(1);
    printf("%d %d\n",vcs.size(),m-res);
}
void work()
{
    scanf("%d%d%lf%lf",&n,&m,&L,&V);
    bool flag1=1,flag2=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&Ar[i].d,&Ar[i].v,&Ar[i].a);
        if(Ar[i].a!=0) flag1=0;
        if(Ar[i].a<=0) flag2=0;
        Ar[i].tags=Ar[i].L=Ar[i].R=0;
    }
    tpos.clear();
    for(int i=1;i<=m;i++)
    {
        double x;
        scanf("%lf",&x);
        tpos.push_back(x);
    }
    if(flag1 || flag2)
    {
        new_solve();
        return ;
    }
    //cout<<"------"<<endl;
    //for(auto i:tpos)
    //{
    //    cout<<i<<" ";
    //}
    //cout<<endl;
    //cout<<"back:"<<tpos.back()<<endl;
    //cout<<"V="<<V<<endl;
    for(int i=1;i<=n;i++)
    {
        if(Ar[i].a==0)
        {
            if(Ar[i].v<=V) continue;
            Ar[i].L=FirstGreater(Ar[i].d-eps,tpos);
            Ar[i].R=LeastSmaller(L+1,tpos);
            Ar[i].tags=1;
        }else if(Ar[i].a>0){
            if(Ar[i].v>V)
            {
                Ar[i].L=FirstGreater(Ar[i].d-1,tpos);
                Ar[i].R=LeastSmaller(L+1,tpos);
                Ar[i].tags=1;
            }else{
                double t=(V-Ar[i].v)/Ar[i].a;
                double s=Ar[i].d+Ar[i].v*t+0.5*Ar[i].a*t*t;
                Ar[i].L=FirstGreater(s,tpos);
                Ar[i].R=LeastSmaller(L+1,tpos);
                Ar[i].tags=1;
            }
        }else{ // a<0
            if(Ar[i].v<=V)
            {
                continue;
            }else{
                double t=(V-Ar[i].v)/Ar[i].a;
                double s=Ar[i].d+Ar[i].v*t+0.5*Ar[i].a*t*t;
                bool flag=1;

                Ar[i].tags=1;
                Ar[i].L=FirstGreater(Ar[i].d-1,tpos);
                Ar[i].R=LeastSmaller(s,tpos);
            }
        }
    }
    vcs.clear();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(Ar[i].tags)
        {
            if(Ar[i].L>Ar[i].R) Ar[i].tags=0;
            if(Ar[i].tags)
            {
                cnt++;
                vcs.push_back((Node){Ar[i].L+1,Ar[i].R+1,1});
            }
        }
    }
    sort(vcs.begin(),vcs.end(),cmp);
    if(m<=20)
    {
        extra_work();
        return ;
    }
    int need=cnt,res=0;
    seg.build(1,1,m);
    for(int i=0;i<vcs.size();i++)
    {
        //cout<<vcs[i].l<<" "<<vcs[i].r<<endl;
        seg.update(1,1,m,vcs[i].l,vcs[i].r,1);
    }
    while(need)
    {
        res++;
        int mx=-1,mxpos=-1;
        for(int i=1;i<=m;i++)
        {
            if(seg.query(1,1,m,i)>mx)
            {
                mx=seg.query(1,1,m,i);
                mxpos=i;
            }
        }
        for(int i=0;i<vcs.size();i++)
        {
            if(vcs[i].tag==0) continue;
            if(vcs[i].l<=mxpos && vcs[i].r>=mxpos)
            {
                need--;
                vcs[i].tag=0;
                seg.update(1,1,m,vcs[i].l,vcs[i].r,-1);
            }
        }
    }
    printf("%d %d\n",cnt,m-res);
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int Case=1;Case<=T;Case++)
    {
        work();
    }
    return 0;
}

// 多组数据题记得清空
// 可能有精度问题？记得用 double 和 eps

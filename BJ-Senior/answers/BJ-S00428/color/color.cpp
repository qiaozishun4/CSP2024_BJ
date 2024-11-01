#include <fstream>
#define lson x*2
#define rson x*2+1
using namespace std;
ifstream cin ("color.in");
ofstream cout ("color.out");
using i64 = long long int;
const int MAXN = 2e5+10,MAXM=1e6+10;
struct Tree
{
    struct Node
    {
        i64 ma,lzy;
    }tr[4*MAXN];
    void add (int x,i64 v)
    {
        tr[x].ma+=v;
        tr[x].lzy+=v;
    }
    void pushup (int x)
    {
        tr[x].ma=max(tr[lson].ma,tr[rson].ma);
    }
    void pushdown (int x)
    {
        if (tr[x].lzy)
        {
            add(lson,tr[x].lzy);
            add(rson,tr[x].lzy);
            tr[x].lzy=0;
        }
    }
    void build (int x,int l,int r)
    {
        tr[x].ma=tr[x].lzy=0;
        if (l==r)
        {
            return;
        }
        int mid = (l+r)/2;
        build(lson,l,mid);
        build(rson,mid+1,r);
    }
    void add (int x,int l,int r,int L,int R,i64 v)
    {
        if (L<=l and r<=R)
        {
            add(x,v);
            return;
        }
        int mid = (l+r)/2;
        pushdown(x);
        if (L<=mid)
        {
            add(lson,l,mid,L,R,v);
        }
        if (R>mid)
        {
            add(rson,mid+1,r,L,R,v);
        }
        pushup(x);
    }
    i64 query (int x,int l,int r,int L,int R)
    {
        if (L<=l and r<=R)
        {
            return tr[x].ma;
        }
        int mid = (l+r)/2;
        i64 res = 0;
        pushdown(x);
        if (L<=mid)
        {
            res=max(res,query(lson,l,mid,L,R));
        }
        if (R>mid)
        {
            res=max(res,query(rson,mid+1,r,L,R));
        }
        return res;
    }
}T;
int a[MAXN];
long long int ma[MAXM];
int main ()
{
    cin.tie(0);
    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        int M = 0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            M = max(M,a[i]);
        }
        for (int i=0;i<=M;i++)
        {
            ma[i]=-1;
        }
        ma[a[1]]=1;
        T.build(1,0,n);
        for (int i=1;i<n;i++)
        {
            i64 t = T.query(1,0,n,0,n);
            if (ma[a[i + 1]] != -1)
            {
                t = max (t, T.query(1,0,n,ma[a[i+1]],ma[a[i+1]]) + a[i+1]);
            }
            T.add(1,0,n,i,i,t);
            if (a[i]==a[i+1])
            {
                T.add(1,0,n,0,i-1,a[i]);
            }
            if (ma[a[i]]==-1 or t>=T.query(1,0,n,ma[a[i]],ma[a[i]]))
            {
                ma[a[i]]=i;
            }
            // for (int j=0;j<=n;j++)
            // {
            //     cerr<<T.query(1,0,n,j,j)<<' ';
            // }
            // cerr<<endl;
        }
        cout<<T.query(1,0,n,0,n)<<'\n';
    }
}
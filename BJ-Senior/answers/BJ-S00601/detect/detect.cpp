#include<bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define nit int

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int read()
{
    static int x,sgn,c;
    x=0,sgn=1,c=getchar();
    while ((c<48||c>57)&&c!='-') c=getchar();
    if (c=='-') sgn=-1,c=getchar();
    while (c>=48&&c<=57) x=x*10+c-48,c=getchar();
    return x*sgn;
}

const ll N=1e5+233;
ll n,m,l,v;
struct car
{
    ll d,v,a,id;
    inline bool operator<(car c)
    {
        return d<c.d;
    }
}c[N];
ll p[N];
const double eps=1e-6;
vector<nit> vec;
struct data
{
    double val;
    int id;
    inline bool operator<(data z)
    {
        return val<z.val;
    }
    inline bool operator==(data z)
    {
        return val==z.val;
    }
};
struct fhq_treap
{
    struct node
    {
        node *l,*r;
        data val;
        int sz;
        inline void pushup()
        {
            sz=1+(l?l->sz:0)+(r?r->sz:0);
        }
    }*rt;
    fhq_treap():rt(0){}
    inline void split(node *p,data val,node *&x,node *&y)
    {
        if (!p) return x=y=0,void();
        if (val<p->val) y=p,split(p->l,val,x,p->l);
        else x=p,split(p->r,val,p->r,y);
        p->pushup();
    }
    inline node* merge(node *p,node *q)
    {
        if (!p||!q) return p?p:q;
        if (rand()<rand()) return p->r=merge(p->r,q),p->pushup(),p;
        return q->l=merge(p,q->l),q->pushup(),q;
    }
    inline void ins(data val)
    {
        node *x,*y,*p=new node;
        p->l=p->r=0,p->sz=1,p->val=val;
        split(rt,val,x,y);
        rt=merge(merge(x,p),y);
    }
    inline void del(node *&p)
    {
        if (!p) return;
        del(p->l),del(p->r);
        vec.pb(p->val.id);
        delete p,p=0;
    }
    inline nit udtless(data val)
    {
        node *x,*y;
        val.val-=eps; //
        split(rt,val,x,y);
        nit ans=(x?x->sz:0);
        del(x),rt=y;
        return ans;
    }
    inline int udtgreater(data val)
    {
        node *x,*y;
        split(rt,val,x,y);
        nit ans=(y?y->sz:0);
        del(y),rt=x;
        return ans;
    }
    inline int udtleq(data val)
    {
        node *x,*y;
        split(rt,val,x,y);
        nit ans=(x?x->sz:0);
        del(x),rt=y;
        return ans;
    }
    inline void clr()
    {
        del(rt);
    }
}t1,t2,t3;
struct segm
{
    nit l,r;
    inline bool operator<(segm s)
    {
        return r!=s.r?r<s.r:l<s.l;
    }
}s[N];
inline void _main()
{
    cin>>n>>m>>l>>v;
    for (int i=1;i<=n;i++)
        c[i].d=read(),c[i].v=read(),c[i].a=read(),s[i]={0,0},c[i].id=i;
    sort(c+1,c+1+n);
    int ans1=0;
    for (int i=1,k=1;i<=m;i++)
    {
        p[i]=read();
        while (k<=n&&c[k].d<=p[i])
        {
            if (c[k].a>0) t1.ins({(v*v-c[k].v*c[k].v)/(2.0*c[k].a)+c[k].d,c[k].id});
            if (c[k].a==0) t2.ins({c[k].v,c[k].id});
            if (c[k].a<0) t3.ins({(v*v-c[k].v*c[k].v)/(2.0*c[k].a)+c[k].d,c[k].id});
            k++;
        }
        vec.clear(),ans1+=t1.udtless({p[i],0});
        for (auto u:vec) s[u]={i,m};
        vec.clear(),ans1+=t2.udtgreater({v,0});
        for (auto u:vec) s[u]={i,m};
        vec.clear(),ans1+=t3.udtgreater({p[i],0});
        for (auto u:vec) s[u].l=i;
    }
    t1.clr(),t2.clr(),t3.clr();
    cout<<ans1<<' ';
    p[m+1]=1e16;
    for (int i=1,k=1;i<=m+1;i++)
    {
        while (k<=n&&c[k].d<=p[i])
        {
            if (c[k].a<0) t3.ins({(v*v-c[k].v*c[k].v)/(2.0*c[k].a)+c[k].d,c[k].id});
            k++;
        }
        vec.clear(),t3.udtleq({p[i],0});
        for (auto u:vec) s[u].r=i-1;
    }
    t3.clr();
    vector<segm> vc;
    for (int i=1;i<=n;i++)
        if (s[i].l&&s[i].l<=s[i].r) vc.pb(s[i]);
    sort(vc.begin(),vc.end());
    int ans2=0;
    for (int i=0;i<vc.size();)
    {
        int j=i+1;
        while (j<vc.size()&&vc[j].l<=vc[i].r) j++;
        ans2++,i=j;
    }
    cout<<m-ans2<<endl;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    srand(time(0));
    nit t;
    for (cin>>t;t;t--) _main();

    return 0;
}
//orz to nzhtl1477
//rp++

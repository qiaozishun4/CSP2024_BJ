#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
ll n,m,len,vl;
ll d[N],v[N],a[N],p[N],sp[N];
struct seg
{
    ll l,r;
}s[N];
ll scnt;
void calc(ll id)
{
    if(a[id]==0)
    {
        if(v[id]>vl)
        {
            s[++scnt]={d[id],len};
        }
        return;
    }
    ll pos=floor((long double)(vl*vl-v[id]*v[id])/(2*a[id]));
    //cout<<"calc "<<id<<": "<<(vl*vl-v[id]*v[id])<<"/"<<(2*a[id])<<"="<<pos<<endl;
    if(a[id]<0)
    {
        if(sqrt(v[id]*v[id]+2*(pos)*a[id])<=vl)
            pos--;
        if(sqrt(v[id]*v[id]+2*(pos+1)*a[id])>vl)
            pos++;
        pos+=d[id];
        if(pos>=d[id])
            s[++scnt]={d[id],min(pos,len)};
    }
    if(a[id]>0)
    {
        if(sqrt(v[id]*v[id]+2*(pos)*a[id])<=vl)
            pos++;
        if(sqrt(v[id]*v[id]+2*(pos-1)*a[id])>vl)
            pos--;
        pos+=d[id];
        if(pos<=len)
            s[++scnt]={max(1ll,pos),len};
    }
}
bool cmp1(seg x,seg y)
{
    return x.l>y.l;
}
bool cmp2(seg x,seg y)
{
    return x.l<y.l;
}

ll t[N];
inline ll lowbit(const ll &x){return x&-x;}
void add(ll p,ll x)
{
    for(ll i=p;i<=len;i+=lowbit(i))
        t[i]+=x;
}
ll ask(ll p)
{
    ll res=0;
    for(ll i=p;i;i-=lowbit(i))
        res+=t[i];
    return res;
}

void init()
{
    scnt=0;
    memset(sp,0,sizeof(sp));
    memset(t,0,sizeof(sp));
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll T;
    cin>>T;
    while(T--)
    {
        init();
        cin>>n>>m>>len>>vl;
        len++;
        for(ll i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            d[i]++;
            calc(i);
        }
        for(ll i=1;i<=m;i++)
        {
            cin>>p[i];
            p[i]++;
            sp[p[i]]++;
        }
        /*
        cout<<scnt<<endl;
        for(ll i=1;i<=scnt;i++)
            cout<<s[i].l<<" "<<s[i].r<<endl;
        */
        sort(p+1,p+m+1);
        for(ll i=1;i<=len;i++)
            sp[i]=sp[i-1]+sp[i];
        for(ll i=1;i<=scnt;i++)
        {
            if(sp[s[i].r]-sp[s[i].l-1]==0)
                s[i]={len+1,len+1};
        }
        /*
        cout<<scnt<<endl;
        for(ll i=1;i<=scnt;i++)
            cout<<s[i].l<<" "<<s[i].r<<endl;
        */
        ll res=0;
        sort(s+1,s+scnt+1,cmp1);
        for(ll i=1;i<=scnt;i++)
        {
            if(s[i].l==len+1)
                continue;
            else
                res++;
            if(ask(s[i].r))
                s[i]={len+1,len+1};
            else
                add(s[i].r,1);
        }
        cout<<res<<" ";
        sort(s+1,s+scnt+1,cmp2);
        ll last=0,ans=0;
        for(ll i=1;i<=scnt;i++)
        {
            if(s[i].l==len+1)
                break;
            if(p[last]<s[i].l)
            {
                while(p[last+1]<=s[i].r)
                    last++;
            }
            ans++;
        }
        cout<<m-ans<<endl;
    }
    return 0;
}

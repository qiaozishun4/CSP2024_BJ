#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+5;

int q;
int n,m,l;
int last;
ll mv;
ll d[maxn],v[maxn],a[maxn];
ll t[maxn];
int p[maxn];
int s;
int ans;

int ls[maxn],rs[maxn];

struct nd{
    int l,r;
}g[maxn];

bool cmp(nd a,nd b){
    if(a.l==b.l)return a.r<b.r;
    return a.l<b.l;
}

void ff(int i){
    //ai>0
    ll v1=2ll*a[i]*(p[m]-d[i])+v[i]*v[i];
    if(v1<=mv*mv){
        ls[i]=rs[i]=-1;
        t[i]=-1;
        return;
    }
    int l=1,r=m,mid;
    while(l<r){
        //01
        mid=(l+r)>>1;
        if(p[mid]<d[i]){
            l=mid+1;
            continue;
        }
        v1=2ll*a[i]*(p[mid]-d[i])+v[i]*v[i];
        if(v1>mv*mv)r=mid;
        else l=mid+1;
    }
    v1=2ll*a[i]*(p[r]-d[i])+v[i]*v[i];
    if(p[r]>=d[i]&&v1>mv*mv)ls[i]=t[i]=r,rs[i]=m;
    else ls[i]=rs[i]=t[i]=-1;
}

void fl(int i){
    //ai<=0
    if(v[i]<=mv){
        ls[i]=rs[i]=t[i]=-1;
        return;
    }
    int l=1,r=m,mid;
    ll v1;
    while(l<r){
        //01
        mid=(l+r)>>1;
        if(p[mid]<d[i])l=mid+1;
        else r=mid;
    }
    v1=2ll*a[i]*(p[r]-d[i])+v[i]*v[i];
    if(p[r]>=d[i]&&v1>mv*mv)ls[i]=t[i]=r;
    else ls[i]=rs[i]=t[i]=-1;
}

void fr(int i){
    //ai<0 get_r
    if(!a[i])return;
    int l=1,r=m,mid;
    while(l<r){
        //10
        mid=(l+r+1)>>1;
        if(p[mid]<d[i])l=mid;
        else if(-2ll*a[i]*(p[mid]-d[i])>v[i]*v[i])r=mid-1;
        else{
            ll v1=2ll*a[i]*(p[mid]-d[i])+v[i]*v[i];
            if(v1>mv*mv)l=mid;
            else r=mid-1;
        }
    }
    ll v1=2ll*a[i]*(p[l]-d[i])+v[i]*v[i];
    if(p[l]>=d[i]&&v1>mv*mv)rs[i]=l;
    else rs[i]=-1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>q;
    while(q--){
        memset(t,0,sizeof t);
        cin>>n>>m>>l>>mv;
        s=n;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>p[i];
        sort(p+1,p+1+m);
        for(int i=1;i<=n;i++){
            if(a[i]>0)ff(i);
            else if(!a[i]){
                fl(i);
                if(v[i]>mv)rs[i]=m;
                else rs[i]=-1;
            }
            else{
                fl(i);
                fr(i);
            }
            g[i]=nd{ls[i],rs[i]};
        }
        for(int i=1;i<=n;i++)if(t[i]==-1)s--;
        cout<<s<<' ';
        sort(g+1,g+1+n,cmp);
        ans=0;
        last=1;
        while(last<=n&&g[last].l==-1)last++;
        int pl=g[last].l,pr=g[last].r;
        for(int i=last+1;i<=n;i++){
            if(g[i].l<=pr)pl=g[i].l,pr=min(pr,g[i].r);
            else{
                ans++;
                pl=g[i].l,pr=g[i].r;
            }
        }
        if(s)cout<<m-ans-1<<'\n';
        else cout<<m<<'\n';

    }
    return 0;
}


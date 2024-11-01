#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;
const int N=1e5+5,H=1e6+5;
int t,n,m,l,v,x,p[N],h[H],sz,cur,mx,o,f[N],ans,g[H],s[H];
struct T {
    int d,v,a;
}c[N];
struct TT {
    int l,r;
}a[N];
bool cmp(TT x,TT y){
    return x.l<y.l;
}
priority_queue<int,vector<int>,greater<int> > q;
bool ck(int x,int y){
    return (h[y]-h[x-1]>0);
}
int lowbit(int x){return x&-x;}
void mod(int x,int d){
    while(x<H){
        s[x]+=d;
        x+=lowbit(x);
    }
}
int qry(int x){
    int re=0;
    while(x>0){
        re+=s[x];
        x-=lowbit(x);
    }
    return re;
}
void modd(int x,int d){
    while(x<H){
        g[x]+=d;
        x+=lowbit(x);
    }
}
int qryy(int x){
    int re=0;
    while(x>0){
        re+=g[x];
        x-=lowbit(x);
    }
    return re;
}
signed main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
        sz=0;
        for(int i=1;i<=n;i++)
            scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
        for(int i=1;i<=1e6;i++)
            h[i]=0;
        for(int i=1;i<=m;i++){
            scanf("%lld",&p[i]);
            h[p[i]]++;
        }
        for(int i=1;i<=1e6;i++)
            h[i]+=h[i-1];
        for(int i=1;i<=n;i++){
            if(c[i].a>=0){
                if(c[i].v>v){
                    if(ck(c[i].d,l))
                        a[++sz]=(TT){c[i].d,l};
                }
                else{
//                    cout<<(v*v-c[i].v*c[i].v)/(c[i].a*2)<<endl;
                    if(c[i].a!=0&&c[i].d+((v*v-c[i].v*c[i].v)/(2*c[i].a)+1)<=l){
                        if(ck(c[i].d+(v*v-c[i].v*c[i].v)/(2*c[i].a)+1,l))
                            a[++sz]=(TT){c[i].d+(v*v-c[i].v*c[i].v)/(2*c[i].a)+1,l};
//                        cout<<i<<endl;
                    }
                }
            }
            else{
                if(c[i].v>v){
                    c[i].a=abs(c[i].a);
//                cout<<i<<" "<<(c[i].v*c[i].v-v*v+2*c[i].a-1)/(2*c[i].a)-1<<endl;
                    if((c[i].v*c[i].v-v*v+2ll*c[i].a-1)/(2ll*c[i].a)-1>=0){
                        if(ck(c[i].d,c[i].d+(c[i].v*c[i].v-v*v+2*c[i].a-1)/(2*c[i].a)-1))
                            a[++sz]=(TT){c[i].d,c[i].d+(c[i].v*c[i].v-v*v+2*c[i].a-1)/(2*c[i].a)-1};
//                        cout<<i<<endl;
                    }
                }
            }
        }
        sort(a+1,a+1+sz,cmp);
        o=0;
        ans=0;
        for(int i=0;i<=1e6;i++)
            g[i]=s[i]=0;
        for(int i=1;i<=sz;i++){
            modd(a[i].r,1);
//            cout<<a[i].l<<" "<<a[i].r<<" "<<qry(a[i].r)<<endl;
        }
        for(int i=1;i<=sz;i++){
            modd(a[i].r,-1);
            if(qry(a[i].r)-qry(a[i].l-1)>0) continue;
            if(qryy(a[i].r)>0) continue;
//            cout<<"==="<<qry(a[i].r)<<endl;
            while(p[o+1]<=a[i].r&&o+1<=m){
                o++;
            }
            mod(p[o],1);
            ans++;
//
//            if(i!=n&&a[i+1].l<=a[i].r){
//                if(a[i+1].r>a[i].r){
//                }
//            }
//            else{
//                ans++;
//            }
        }
        printf("%lld %lld\n",sz,m-ans);
    }
    return 0;
}

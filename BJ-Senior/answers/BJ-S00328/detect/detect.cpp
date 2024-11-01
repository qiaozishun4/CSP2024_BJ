#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
inline void read(int &x){
    x=0;bool f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=0;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    x=f?x:-x;
}
struct node{
    int d,v,a;
    bool f;
}a[100005];
struct line{
    int l,r;
};
int p[100005],sum[100005],c[100005];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    read(t);
    while(t--){
        int n,m,l,v,ans1=0,ans2=0,now=0,nowm;
        read(n),read(m),read(l),read(v);
        nowm=m;
        vector<line>vec;
        rep(i,1,n){
            read(a[i].d),read(a[i].v),read(a[i].a);
        }
        rep(i,1,m) read(p[i]);
        rep(i,1,n){
            //v1=v0+t*a
            if(a[i].a>0){
                int v1=(a[i].v*a[i].v+2*a[i].a*(p[m]-a[i].d));
                if(v1<=v) continue;
                a[i].f=1,ans1++,ans2=1;
            }else if(a[i].a==0){
                if(a[i].v>v&&a[i].d<=p[nowm]){
                    ans1++,a[i].f=1;
                    int np=lower_bound(p+1,p+m+1,a[i].d)-p;
                    vec.push_back({p[np],p[m]});
                }
            }else{
                if(a[i].v<v) continue;
                int np=lower_bound(p+1,p+m+1,a[i].d)-p;
                int v2=sqrt(a[i].v*a[i].v+2*a[i].a*(p[np]-a[i].d));
                if(v2<=v) continue;
                int s=ceil(a[i].d+(1.0*v*v-a[i].v*a[i].v)/(2.0*a[i].a));
                int cand=lower_bound(p+1,p+m+1,s)-p;
                if(cand>m) continue;
                vec.push_back({p[np],p[cand]-1});
                a[i].f=1,ans1++;
            }
        }
        cout<<ans1<<' ';
        for(int i=0;i<vec.size();i++){
            if(vec[i].l>now) now=vec[i].r,ans2++;
        }
        cout<<n-ans2<<'\n';
        /*ans1=0;
        p[1]=p[m];m=1;
        rep(i,1,n){
            //v1=v0+t*a
            if(a[i].a>0){
                int s=ceil((a[i].d+1.0*v*v-a[i].v*a[i].v)/(2.0*a[i].a));
                if(s>=l) continue;
                int cand=lower_bound(p+1,p+m+1,s)-p;
                if(cand>m) continue;
                a[i].f=1,ans1++,ans2=1;
            }else if(a[i].a==0){
                if(a[i].v>v&&a[i].d<=p[m]) ans1++,ans2=1,a[i].f=1;
            }else{
                if(a[i].v<v) continue;
                int np=lower_bound(p+1,p+m+1,a[i].d)-p;
                int v2=sqrt(a[i].v*a[i].v+2*a[i].a*(p[np]-a[i].d));
                if(v2<v) continue;
                int s=ceil(a[i].d+(1.0*v*v-a[i].v*a[i].v)/(2.0*a[i].a));
                int cand=lower_bound(p+1,p+m+1,s)-p;
                if(cand>m) continue;
                vec.push_back({p[np],p[cand]-1});
                a[i].f=1,ans1++;
            }
        }
        cout<<ans1<<'\n';*/
    }
    return 0;
}

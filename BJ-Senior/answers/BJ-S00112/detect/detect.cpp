#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+5;
int n,m,T,ans1,ans2,cnt,st,en;
double p[N],L,V;
struct car{
    double d,v,a;
    int lp,rp;
    bool f;
}c[N];
struct line{
    int l,r;
    bool sign;
}b[N];
bool cmp(line x,line y){
    if(x.l!=y.l)return x.l<y.l;
    else return x.r<y.r;
}
int deal(double x){
    int l=1,r=m;
    while(l<r){
        int mid=l+r>>1;
        if(p[mid]>=x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    while(p[l]>=x)l--;
    return l;
}
int deal1(double x){
    int l=1,r=m;
    while(l<r){
        int mid=l+r>>1;
        if(p[mid]>=x){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    while(p[l]<x)l++;
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >> T;
    while(T--){
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        cin>>n>>m>>L>>V;
        ans1=n,ans2=0,cnt=0;
        for(int i=1;i<=n;i++)cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            if(c[i].d>p[m]){ans1--;c[i].f=1;continue;}
            if(c[i].v<=V&&c[i].a<=0){ans1--;c[i].f=1;continue;}
            if(c[i].a>0&&c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a)>=p[m]){ans1--;c[i].f=1;continue;}
            if(c[i].a>0)c[i].lp=deal1(c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a)),c[i].rp=m;
            else if(c[i].a==0)c[i].lp=deal1(c[i].d),c[i].rp=m;
            else {
                c[i].rp=deal(c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a)),c[i].lp=deal1(c[i].d);
                if((p[c[i].lp]<c[i].d&&p[c[i].rp]>=c[i].d+(V*V-c[i].v*c[i].v)/(2.0*c[i].a))){ans1--;c[i].f=1;continue;}
            }
            if(c[i].lp>c[i].rp){ans1--;c[i].f=1;continue;}
        }
        cout << ans1<<" ";
        for(int i=1;i<=n;i++){
            if(c[i].f)continue;
            b[++cnt].l=c[i].lp,b[cnt].r=c[i].rp;
        }
        sort(b+1,b+cnt+1,cmp);
        st=1,en=cnt;
        line x=b[st];
        st++;
        while(st<=en){
            if(x.r<b[st].l){
                x=b[st];
                b[st].sign=1;
                st++;
                ans2++;
            }else if(x.r>=b[st].l){
                int nx=max(x.l,b[st].l),ny=min(x.r,b[st].r);
                x={nx,ny,0};
                b[st].sign=1;
                st++;
            }
        }
        for(int i=1;i<=cnt;i++){
            if(b[i].sign==0)ans2++;
        }
        cout << m-ans2<<endl;
    }
    return 0;
}



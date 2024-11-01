#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct infor{int d,v,flag1,flag2;long double a;};
int t,n,m,L,R,V,ans,cnt,p[N];
infor car[N];
inline void file(){freopen("detect.in","r",stdin),freopen("detect.out","w",stdout);}
inline void calc(int k){
    if(car[k].a<0){
        if(car[k].v<=V){car[k].flag1=car[k].flag2=-1,++cnt;return;}
        else{
            int l(1),r(m);
            long double mem((V*V-car[k].v*car[k].v)/(2*car[k].a));
            while(l<r){
                car[k].flag1=l+r>>1;
                if(p[car[k].flag1]<car[k].d) l=car[k].flag1+1;
                else r=car[k].flag1;
            }
            if(p[l]>=car[k].d) car[k].flag1=l;
            else{car[k].flag1=car[k].flag2=-1,++cnt;return;}
            l=1,r=m;
            while(l<r){
                car[k].flag2=l+r+1>>1;
                if(p[car[k].flag2]>=mem+car[k].d) r=car[k].flag2-1;
                else l=car[k].flag2;
            }
            if(p[l]<mem+car[k].d) car[k].flag2=l;
            else{car[k].flag1=car[k].flag2=-1,++cnt;return;}
            if(car[k].flag1>car[k].flag2){car[k].flag1=car[k].flag2=-1,++cnt;return;}
        }
    }
    else if(car[k].a>0){
        if(car[k].v>V){
            if(car[k].d>p[m]){car[k].flag1=car[k].flag2=-1,++cnt;return;}
            car[k].flag2=m;
            int l(1),r(m);
            while(l<r){
                car[k].flag1=l+r>>1;
                if(p[car[k].flag1]<car[k].d) l=car[k].flag1+1;
                else r=car[k].flag1;
            }
            car[k].flag1=l;
        }
        long double mem((V*V-car[k].v*car[k].v)/(2*car[k].a));
        if(mem+car[k].d>=p[m]){car[k].flag1=car[k].flag2=-1,++cnt;return;}
        else{
            car[k].flag2=m;
            int l(1),r(m);
            while(l<r){
                car[k].flag1=l+r>>1;
                if(p[car[k].flag1]<=mem+car[k].d) l=car[k].flag1+1;
                else r=car[k].flag1;
            }
            car[k].flag1=l;
        }
    }
    else{
        if(car[k].v<=V){car[k].flag1=car[k].flag2=-1,++cnt;return;}
        else{
            if(car[k].d>p[m]){car[k].flag1=car[k].flag2=-1,++cnt;return;}
            car[k].flag2=m;
            int l(1),r(m);
            while(l<r){
                car[k].flag1=l+r>>1;
                if(p[car[k].flag1]<car[k].d) l=car[k].flag1+1;
                else r=car[k].flag1;
            }
            car[k].flag1=l;
        }
    }
}
inline bool cmp(infor x,infor y){
    if(x.flag1==-1) return 0;
    if(y.flag1==-1) return 1;
    if(x.flag2!=y.flag2) return x.flag2<y.flag2;
    return x.flag1>y.flag1;
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> t;
    while(t--){
        cin >> n >> m >> L >> V,cnt=ans=R=0;
        for(int i(1);i<=n;++i) cin >> car[i].d >> car[i].v >> car[i].a;
        for(int i(1);i<=m;++i) cin >> p[i];
        for(int i(1);i<=n;++i) calc(i);
        cnt=n-cnt,cout << cnt << ' ';
        sort(car+1,car+n+1,cmp);
        for(int i(1);i<=cnt;++i) if(R<car[i].flag1) ++ans,R=car[i].flag2;
        cout << m-ans << '\n';
    }
    return 0;
}
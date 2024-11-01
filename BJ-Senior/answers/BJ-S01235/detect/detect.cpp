#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N];
struct node{
    int l,r;
} f[N];
//int d[N],v[N],a[N];
bool cmp(node x,node y){
    if (x.r!=y.r) return x.r<y.r;
    return x.l<y.l;
}
int solve1(double d){
    if (d==int(d)) return d+1;
    return ceil(d);
}
int solve2(double d){
    if (d==int(d)) return d-1;
    return floor(d);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int q;
    cin>>q;
    while (q--){
        memset(p,0,sizeof p);
        memset(f,0,sizeof f);
        //memset(d,0,sizeof d);
       // memset(v,0,sizeof v);
      //  memset(a,0,sizeof a);
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        int cur=0;
        for (int i=1;i<=n;i++){
            int d,v,a;
            cin>>d>>v>>a;
            //cout<<d<<' '<<v<<' '<<a<<endl;
            if (a>0){
                if (v>V){
                    f[++cur].l=d;
                    f[cur].r=l;
                }
                else{
                    if (sqrt(v*v+2*a*(l-d))>V){
                        double t=1.0*(V-v)/a;
                        f[++cur].l=solve1(d+v*t+a*t*t/2);
                        f[cur].r=l;
                    }
                }
            }
            if (a==0){
                if (v>V){
                    f[++cur].l=d;
                    f[cur].r=l;
                }
            }
            if (a<0){
                if (v>V){
                    double t=1.0*(V-v)/a;
                    //cout<<t<<' ';
                    f[++cur].l=d;
                    f[cur].r=min(solve2(d+v*t+a*t*t/2),l);
                }
            }
        }
        for (int i=1;i<=m;i++){
            cin>>p[i];
        //    cout<<p[i]<<' ';
        }
        //cout<<endl;
        sort(p+1,p+m+1);
        p[m+1]=2e9;
        int ans1=0;
        for (int i=1;i<=cur;i++){

            int pos=lower_bound(p+1,p+m+1,f[i].l)-p;
            if (p[pos]<=f[i].r) ans1++;
            else f[i].l=2e9,f[i].r=2e9;
        }
        sort(f+1,f+cur+1,cmp);
        //for (int i=1;i<=cur;i++){
        //   cout<<f[i].l<<' '<<f[i].r<<endl;
        //}
        int ans2=0,lm=-2e9;//last machine
        for (int i=1;i<=cur;i++){
            if (f[i].l==2e9) break;
            if (lm>=f[i].l&&lm<=f[i].r) continue;
            int pos=lower_bound(p+1,p+m+1,f[i].r)-p;
            if (p[pos]>f[i].r) pos--;
            ans2++;
            lm=p[pos];
            //cout<<lm<<' '<<i<<endl;
        }
        cout<<ans1<<' '<<m-ans2<<endl;
    }
    return 0;
}

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct st{
    int s,t;
}a[100001],b[100001];
int tt,n,m,l,bv,ans1,ans2,cnt,sa,d[100001],v[100001],aa[100001],p[100001],dp[1000001];
bool h[1000001];
bool cmp(st st1,st st2) {
    if(st1.t==st2.t) return st1.s>st2.s;
    else return st1.t<st2.t;
}
int main() {
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>tt;
    while(tt--) {
        cin>>n>>m>>l>>bv;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>aa[i];
        for(int i=0;i<=1000000;i++) h[i]=false;
        for(int i=1;i<=m;i++) {
            cin>>p[i];
            h[p[i]]=true;
        }
        for(int i=1;i<=n;i++) {
            a[i].s=a[i].t=-1;
            if(v[i]>bv && aa[i]>=0) {
                a[i].s=d[i];
                a[i].t=l;
            }
            if(v[i]>bv && aa[i]<0) {
                a[i].s=d[i];
                int tmp1=bv*bv-v[i]*v[i],tmp2=2*aa[i];
                if(tmp1%tmp2==0) a[i].t=d[i]+tmp1/tmp2-1;
                else a[i].t=d[i]+tmp1/tmp2;
                if(a[i].t>l) a[i].t=l;
            }
            if(v[i]<=bv && aa[i]>0) {
                int tmp1=bv*bv-v[i]*v[i],tmp2=2*aa[i];
                if(tmp1%tmp2==0) a[i].s=d[i]+tmp1/tmp2+1;
                else a[i].s=d[i]+tmp1/tmp2;
                a[i].t=l;
                if(a[i].s>a[i].t || (a[i].s==a[i].t && tmp1%tmp2!=0)) a[i].s=a[i].t=-1;
            }
        }
        dp[0]=-1;
        for(int i=0;i<=l;i++) {
            if(h[i]) dp[i]=i;
            else dp[i]=dp[max(i-1,0)];
        }
        ans1=0;
        for(int i=1;i<=n;i++) {
            if(a[i].t==-1) continue;
            if(dp[a[i].t]>=a[i].s) b[++ans1]=a[i];
        }
        sort(b+1,b+ans1+1,cmp);
        sa=dp[b[1].t];
        if(ans1) ans2=1;
        else ans2=0;
        for(int i=1;i<=ans1;i++) {
            if(b[i].s>sa) {
                sa=dp[b[i].t];
                ans2++;
            }
        }
        cout<<ans1<<" "<<m-ans2<<endl;
    }
    return 0;
}
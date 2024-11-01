#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct dp{
    ll x,y,h;
}s[100005];
ll T,n,m,l,v,d[100005],u[100005],a[100005],p[100005];
bool cmp(dp w,dp e){
    return w.x>e.x;
}
ll ty(ll cnt){
    ll l=1,r=m,j=m;
    while(l<=r){
        ll mid=(l+r)/2;
        if(p[r]>cnt){
            j=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return j;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    //cout<<(ll)4.9;
    while(T--){
        ll ans=0,mm=-1,k=0;
        memset(d,0,sizeof(d));
        memset(u,0,sizeof(u));
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>u[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        sort(p+1,p+1+m);
        for(int i=1;i<=n;i++){
            if(a[i]>0){
                double x=(v*v-u[i]*u[i])/(2*a[i]);
                ll f=(ll)x;
                f++;
                f+=d[i];
                if(d[i]<=p[n]&&u[i]+a[i]>v&&f<=p[n]){
                    //cout<<i;
                    ans++;
                    mm=max(mm,f);
                }
            }else if(a[i]==0){
                if(d[i]<=p[n]&&u[i]>v){
                    //cout<<i;
                    ans++;
                    mm=max(mm,d[i]);
                }
            }else{
                double x=(v*v-u[i]*u[i])/(2*a[i]);
                ll f=(ll)x;
                f++;
                f+=d[i];
                if(d[i]<=p[n]&&u[i]>v&&f>p[ty(d[i])]){
                    //cout<<f<<" \n"<<ty(d[i])<<" \n"<<d[i]<<"\n";
                    ans++;
                    k++;
                    s[k].x=d[i];
                    s[k].y=f-1;
                }
            }
        }
        cout<<ans<<" ";
        sort(s+1,s+k+1,cmp);
        s[0].h=11111111199111111111;
        bool f=0;
        ll ans2=0;
        for(int i=1;i<=k;i++){
            if(s[i-1].h<=s[i].y&&s[i-1].h>=s[i].x){
                s[i].h=s[i-1].h;
            }else{
                ll op=ty(s[i].x);
                if(op>mm){
                    f=1;
                }
                ans2++;
                s[i].h=op;
            }

        }
        if(f==0){
            ans2++;
        }
        cout<<m-ans2<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
ll L,V;
ll d[100005],v[100005],a[100005];
ll pl[100005];
int ans2,ln;
struct nd{
    int i,l,r;
}f[100005];
int fr[100005],to[100005];
bool ck(ll s,ll a0,ll v0){
    return v0*v0+2*a0*s>V*V;
}
ll getsp(int h,int p){
    return v[h]*v[h]+2*a[h]*(pl[p]-d[h]);
}
ll sm[100005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++)cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++)cin>>pl[i];
        for(int i=1;i<=n;i++){
            int l=lower_bound(pl+1,pl+m+1,d[i])-pl,r=m,lf,rt,mid,an;
            if(pl[m]<d[i])continue;
            if(a[i]==0){
                if(v[i]>V)f[++ln]={i,l,r};
            }else if(a[i]<0){
                if(v[i]>V){
                    if(!ck(pl[l]-d[i],a[i],v[i]))continue;
                    lf=l;
                    while(l<=r){
                        mid=l+r>>1;
                        if(ck(pl[mid]-d[i],a[i],v[i])){
                            l=mid+1;
                            an=mid;
                        }else{
                            r=mid-1;
                        }
                    }
                    if(ck(pl[an]-d[i],a[i],v[i])){
                        f[++ln]={i,lf,an};
                    }
                }
            }else{
                if(v[i]<=V){
                    rt=r;
                    while(l<=r){
                        mid=l+r>>1;
                        if(ck(pl[mid]-d[i],a[i],v[i])){
                            r=mid-1;
                            an=mid;
                        }else {
                           l=mid+1;
                        }
                    }
                    if(ck(pl[an]-d[i],a[i],v[i])){
                        f[++ln]={i,an,rt};
                    }
                }else f[++ln]={i,l,r};
            }
        }
        cout<<ln<<' ';
        for(int i=1;i<=ln;i++){
            fr[i]=i-1;
            to[i-1]=i;
        }
        while(ln){
            for(int i=to[0];i;i=to[i]){
                sm[f[i].l]++;
                sm[f[i].r+1]--;
            }
            int mx=0;
            for(int i=1;i<=m;i++)sm[i]+=sm[i-1];
            for(int i=1;i<=m;i++){
                if(sm[i]>=sm[mx])mx=i;
            }
            for(int i=to[0];i;i=to[i]){
                if(f[i].l<=mx&&f[i].r>=mx){
                    ln--;
                    fr[to[i]]=fr[i];
                    to[fr[i]]=to[i];
                }
            }
            for(int i=1;i<=m;i++)sm[i]=0;
            ans2++;
        }
        cout<<m-ans2<<'\n';
        for(int i=1;i<=m;i++)fr[i]=to[i]=0;
        ln=ans2=0;
    }
    return 0;
}

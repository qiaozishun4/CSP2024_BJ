#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int T,n,m,L,V,d[maxn],v[maxn],a[maxn],p[maxn];
bool flag[maxn];
struct NODE{
    int l,r;
} t[maxn];
bool cmp(NODE x,NODE y){
    if(x.r!=y.r) return x.r<y.r;
    return x.l<y.l;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=1;i<=m;i++) cin>>p[i];
        for(int i=1;i<=n;i++){
            flag[i]=0;
            t[i].l=1e9;
            t[i].r=0;
            //for(int j=1;j<=m;j++) f[i][j]=0;
        }
        for(int i=1;i<=n;i++){
            int L=1,R=m;
            while(L<=R){
                int mid=(L+R)/2;
                if(p[mid]<d[i]) L=mid+1;
                else{
                    if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])<0) R=mid-1;
                    else{
                        double v0=sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
                        //cout<<i<<" "<<j<<" "<<v0<<" "<<d[i]<<" "<<p[j]<<'\n';
                        if(v0>V){
                            flag[i]=1;
                            R=mid-1;
                        }else L=mid+1;
                    }
                }
            }
            L=1,R=m;
            while(L<=R){
                int mid=(L+R)/2;
                if(p[mid]<d[i]) L=mid+1;
                else{
                    if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])<0) R=mid-1;
                    else{
                        double v0=sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
                        //cout<<i<<" "<<j<<" "<<v0<<" "<<d[i]<<" "<<p[j]<<'\n';
                        if(v0>V){
                            t[i].l=min(t[i].l,p[mid]);
                            R=mid-1;
                        }else R=mid-1;
                    }
                }
            }
            L=1,R=m;
            while(L<=R){
                int mid=(L+R)/2;
                if(p[mid]<d[i]) L=mid+1;
                else{
                    if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])<0) R=mid-1;
                    else{
                        double v0=sqrt(v[i]*v[i]+2*a[i]*(p[mid]-d[i]));
                        //cout<<i<<" "<<j<<" "<<v0<<" "<<d[i]<<" "<<p[j]<<'\n';
                        if(v0>V){
                            flag[i]=1;
                            t[i].r=max(t[i].r,p[mid]);
                            L=mid+1;
                        }else R=mid-1;
                    }
                }
            }

            //cout<<t[i].l<<" "<<t[i].r<<'\n';
            /*
            for(int j=1;j<=m;j++){
                if(p[j]<d[i]) continue;
                //if(a[i]==0) f[i][j]=(a[i]>V);
                if(v[i]*v[i]+2*a[i]*(p[j]-d[i])<0) break;
                double v0=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
                cout<<i<<" "<<j<<" "<<v0<<" "<<d[i]<<" "<<p[j]<<'\n';
                if(v0>V){
                    flag[i]=1;
                    t[i].l=min(t[i].l,p[j]);
                    t[i].r=max(t[i].r,p[j]);
                }
            }
            //cout<<t[i].l<<" "<<t[i].r<<'\n';*/
        }
        //cout<<'\n';
        sort(t+1,t+n+1,cmp);
        int cnt1=0,cnt2=0,right=0;
        for(int i=1;i<=n;i++) if(flag[i]) cnt1++;
        for(int i=1;i<=n;i++){
            //cout<<t[i].l<<" "<<t[i].r<<" "<<'\n';
            if(t[i].l==1000000000) continue;
            if(t[i].l<=right&&t[i].r>=right) continue;
            right=t[i].r;
            cnt2++;
        }
        cout<<cnt1<<" "<<m-cnt2<<'\n';
    }
    return 0;
}


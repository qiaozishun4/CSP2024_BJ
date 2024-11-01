#include<bits/stdc++.h>
using namespace std;
struct St{
    int L,R;
}st[100005];
int T;
int n,m,l,V;
int d[100005],v[100005],a[100005];
int p[100005];
int cnt,ans,k;
bool cmp(St a,St b){
    if(a.R==b.R){
        return a.L<b.L;
    }
    return a.R<b.R;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&l,&V);
        cnt=0,ans=0,k=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++){
            int ll=1,rr=m,tt=m+1;
            while(ll<=rr){
                int mid=(ll+rr)/2;
                if(p[mid]>=d[i]){
                    rr=mid-1;
                    tt=mid;
                }else{
                    ll=mid+1;
                }
            }
            if(a[i]>=0){
                int l=tt,r=m,t=m+1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(p[mid]<d[i]){
                        l=mid+1;
                        continue;
                    }
                    if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V){
                        r=mid-1;
                        t=mid;
                    }else{
                        l=mid+1;
                    }
                }
                if(t<=m){
                    st[i]=St{t,m};
                    cnt++;
                }else{
                    st[i]=St{1,m+1};
                }
            }else{
                int l=tt,r=m,t=m+1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(v[i]*v[i]+2*a[i]*(p[mid]-d[i])>V*V){
                        l=mid+1;
                        t=mid;
                    }else{
                        r=mid-1;
                    }
                }
                if(t<=m){
                    st[i]=St{tt,t};
                    cnt++;
                }else{
                    st[i]=St{1,m+1};
                }
            }
        }
        sort(st+1,st+1+n,cmp);
        for(int i=1;i<=n;i++){
            if((st[i].L<=k&&st[i].R>=k)||st[i].R==m+1){
                continue;
            }else{
                ans++;
                k=st[i].R;

            }
        }
        printf("%d %d\n",cnt,m-ans);
    }
    return 0;
}

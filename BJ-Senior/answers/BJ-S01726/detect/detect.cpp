#include <bits/stdc++.h>
using namespace std;
int n,m;
long long L,V,d[100005],c[100005],a[100005],qwq[100005],cnt[1000005];
vector<int> v[3005];
bool vis[3005];
pair<int,int> p[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%lld%lld",&n,&m,&L,&V);
        bool f=1;
        for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&d[i],&c[i],&a[i]),f&=(a[i]==0);
        int ans1=0,ans2=0;
        for(int i=1;i<=m;i++) scanf("%lld",&qwq[i]);
        f=1;
        for(int i=1;i<=n;i++){
            int k=lower_bound(qwq+1,qwq+m+1,d[i])-qwq;
            int l=k,r=m,mid;
            if(a[i]<0){
                double TT=0-(double)c[i]*c[i]/(2.0*a[i])+d[i];
                while(l<=r){
                    mid=(l+r)/2;
                    if(TT-qwq[mid]>-1e7&&c[i]*c[i]+2*a[i]*(qwq[mid]-d[i])>V*V) l=mid+1;
                    else r=mid-1;
                }
                if(r<k) ans1++;
                p[i].first=k,p[i].second=r;
                f=0;
            }else{
                while(l<=r){
                    mid=(l+r)/2;
                    if(c[i]*c[i]+2*a[i]*(qwq[mid]-d[i])>V*V) r=mid-1;
                    else l=mid+1;
                }
                if(l>m) ans1++;
                p[i].first=l,p[i].second=m;
            }
        }
        if(f){
            printf("%d %d\n",n-ans1,m-(n-ans1==0?0:1));
            continue;
        }
        if(n<=3000&&m<=3000){
            memset(vis,0,sizeof(vis));
            memset(cnt,0,sizeof(cnt));
            for(int i=1;i<=m;i++) v[i].clear();
            sort(p+1,p+n+1);
            for(int i=1;i<=n;i++) for(int j=p[i].first;j<=p[i].second;j++) v[j].push_back(i),cnt[j]++;
            for(int i=1;i<=n;i++){
                if(p[i].first>p[i].second||vis[i]) continue;
                int maxid=0;
                for(int j=p[i].first;j<=p[i].second;j++) if(cnt[j]>cnt[maxid]) maxid=j;
                ans2++;
                for(auto pp:v[maxid]){
                    if(vis[pp]) continue;
                    vis[pp]=1;
                    for(int K=p[pp].first;K<=p[pp].second;K++) cnt[K]--;
                }
            }
            printf("%d %d\n",n-ans1,m-ans2);
        }
    }
    return 0;
}

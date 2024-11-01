#include<bits/stdc++.h>
using namespace std;
int t;
bool cmp(vector<int>x,vector<int>y){
    return x.size()<y.size();
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int t,n,m,l,v;
        scanf("%d%d%d%d",&n,&m,&l,&v);
        int p[100005];
        int d[100005],cv[100005],a[100005],f[100005];
        memset(f,0,sizeof(f));
        vector<int> cnt[100005];
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&cv[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]<d[i])
                    continue;
                long long car=1LL*2*(p[j]-d[i])*a[i]+cv[i]*cv[i];
                if(car>1LL*v*v)
                    cnt[j].push_back(i),f[i]++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(f[i])
                ans++;
        }
        printf("%d ",ans);
        sort(cnt+1,cnt+m+1,cmp);
        ans=0;
        for(int i=1;i<=m;i++){
            bool flag=true;
            for(int j=0;j<cnt[i].size();j++){
                f[cnt[i][j]]--;
                if(f[cnt[i][j]]==0){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans++;
            else
                for(int k=0;k<cnt[i].size();k++)
                    f[cnt[i][k]]++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int T;
int n,m,L,V;
int d[maxn],v[maxn],a[maxn];
int sur[maxn];
struct P{
    int l,r;
}p[maxn];
int nxt[maxn*10];
int vis[maxn];
int tot;
bool cmp(P a,P b){
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        tot=0;
        memset(p,0,sizeof(p));
        for(int i=1;i<=L;i++)nxt[i]=0;
        int op1=1,op2=1;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
            if(a[i]!=0)op1=0;
            if(a[i]<0)op2=0;
        }
        for(int i=1;i<=m;i++)scanf("%lld",&sur[i]);
        if(op1){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(v[i]>V&&d[i]<=sur[m])ans++;
            }
            if(ans==0)printf("%lld %lld\n",ans,m);
            else printf("%lld %lld\n",ans,(long long)m-1);
        }else if(op2){
            int ans=0;
            for(int i=1;i<=n;i++){
                if(d[i]>sur[m])continue;
                double vk=sqrt(2*a[i]*(sur[m]-d[i])+v[i]*v[i]);
                if(vk>V){
                    ans++;
                }
            }
            if(ans==0)printf("%lld %lld\n",ans,m);
            else printf("%lld %lld\n",ans,(long long)m-1);
        }else if(n<=3000){
            int lst=0;
            for(int i=1;i<=m;i++){
                for(int j=lst;j<=sur[i];j++){
                    nxt[j]=i;
                }
                lst=sur[i]+1;
            }
            for(int i=sur[m];i<=L;i++)nxt[i]=m;
            int ans=0;
            for(int i=1;i<=n;i++){
                if(d[i]>sur[m])continue;
                if(a[i]==0){
                    if(v[i]>V){
                        ans++;
                        p[++tot].l=nxt[d[i]];
                        p[tot].r=m;
                    }
                }else if(a[i]>0){
                    double vk=sqrt(2*a[i]*(sur[m]-d[i])+v[i]*v[i]);
                    if(vk>V){
                        ans++;
                        if(V<v[i]){
                            p[++tot].l=nxt[d[i]];
                        }else{
                            int x=d[i]+ceil((double)(V*V-v[i]*v[i])/(double)(2*a[i]));
                            if(x>=L)p[++tot].l=m;
                            else p[++tot].l=nxt[x]-1;
                        }
                        p[tot].r=m;
                    }
                }else{
                    int k=sur[nxt[d[i]]];
                    double vk=sqrt(2*a[i]*(k-d[i])+v[i]*v[i]);
                    if(vk>V){
                        ans++;
                        p[++tot].l=nxt[d[i]];
                        int x=d[i]+ceil((double)(V*V-v[i]*v[i])/(double)(2*a[i]));
                        if(x>=L)p[tot].r=m;
                        else p[tot].r=nxt[x]-1;
                    }
                }
            }
            printf("%lld ",ans);
            sort(p+1,p+tot+1,cmp);
            /*
            cout<<endl;
            for(int i=1;i<=tot;i++)cout<<sur[p[i].l]<<' '<<sur[p[i].r]<<"  ";
            cout<<endl;
            cout<<endl;*/
            int cnt=0;
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=tot;i++){
                if(vis[i])continue;
                if(p[i].r==0)continue;
                vis[i]=1;
                int L=p[i].l;
                int R=p[i].r;
                for(int j=1;j<=tot;j++){
                    if(vis[j])continue;
                    if(p[j].l<=R){
                        vis[j]=1;
                    }
                }
                cnt++;
            }
            printf("%lld\n",m-cnt);
        }
    }


    return 0;
}
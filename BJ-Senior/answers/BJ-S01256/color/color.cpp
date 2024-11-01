#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+1;
int a[2005];
int sit[2005];
int maxx=0;
int n;
void dfs(int k){
    if(k==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(a[i]==a[j]&&sit[i]==sit[j]){cnt+=a[i];break;}
            }
        }
        maxx=max(maxx,cnt);
       return;
    }
    sit[k]=0;
    dfs(k+1);
    sit[k]=1;
    dfs(k+1);
}
struct P{
    int l,r,v;
    vector<int> N;
    vector<int> Y;
    int add=0;
}p[maxn];
int tot;
bool cmp(P a,P b){
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
int vis[maxn];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        maxx=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=15){
            dfs(1);
            cout<<maxx<<"\n";
        }else{
            int ans=0;
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=n;i++){
                for(int j=i-1;j>0;j--){
                    if(vis[i]||vis[j])continue;
                    if(a[i]==a[j]){
                        ans+=a[i];
                        vis[i]=1;
                        vis[j]=1;
                        break;
                    }
                }
            }
            printf("%lld\n",ans);
        /*  for(int i=1;i<=n;i++){
                for(int j=i-1;j>0;j--){
                    if(a[i]==a[j]){
                        p[++tot].l=j;
                        p[tot].r=i;
                        p[tot].v=a[i];
                        p[tot].add=a[i];
                        break;
                    }
                }
            }
            sort(p+1,p+tot+1,cmp);
            for(int i=1;i<=tot;i++){
                for(int j=1;j<=tot;j++){
                    if(i==j)continue;
                    if(p[i].l<p[j].l&&p[j].r<p[i].r){
                        p[i].Y.push_back(j);
                        p[i].add+=p[j].v;
                    }else if(p[i].l<p[j].l||p[j].r<p[i].r){
                        p[i].N.push_back(j);
                    }
                }
            }
            for(int i=1;i<=tot;i++){

            }*/
        }
    }

    return 0;
}
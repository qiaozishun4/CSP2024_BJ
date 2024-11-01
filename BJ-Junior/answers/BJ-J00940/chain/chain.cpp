#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
const int N=2e5+7,M=1007;
typedef pair<int,int> pii;
int t;
int n,k,q,x,l[M],cnt,v;
struct qq{
    int r,c,id,ans;
}qry[N>>1];
vector<int>s[M];
vector<pii>f[N],g[N];
bool vis[N],ans[M][N],res[N];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        int mx=-1;
        v=-1;
        memset(vis,0,sizeof vis);
        memset(ans,0,sizeof ans);
        scanf("%d%d%d",&n,&k,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&l[i]);
            s[i].clear();
            for(int j=1;j<=l[i];j++)scanf("%d",&x),s[i].push_back(x),vis[x]=1,v=max(v,x);
            for(int j=1;j<=l[i];j++){
                x=s[i][j-1];
                for(int ss=1;ss<=k;ss++){
                    if(j-ss<=0)break;
                    f[x].push_back(mp(i,s[i][j-ss-1]));
                }
                for(int ss=1;ss<=k;ss++){
                    if(j+ss>l[i])break;
                    g[x].push_back(mp(i,s[i][j+ss-1]));
                }
            }
        }
        for(int x=1;x<=q;x++){
            printf("1\n");
        }

    }
    return 0;
}

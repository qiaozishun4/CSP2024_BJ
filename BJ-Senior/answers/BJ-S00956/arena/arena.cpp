#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+5;
const int M=20;
int n,m,k,_;
int a[N],b[N],q[N],x[N],Log[N],val[N];
int op[N];
vector<int> merge(vector<int> a,vector<int> b,int op,int r){
    vector<int> c;
    for(auto x:a){
        for(auto y:b){
            if(op==0&&(val[x]>=r||val[x]==-1)){
                c.push_back(x);
                break;
            }
            if(op==1&&(val[y]<r||val[y]==-1)){
                c.push_back(x);
                break;
            }
        }
    }
    for(auto y:b){
        for(auto x:a){
            if(op==0&&(val[x]<r||val[x]==-1)){
                c.push_back(y);
                break;
            }
            if(op==1&&(val[y]>=r||val[y]==-1)){
                c.push_back(y);
                break;
            }
        }
    }
    return c;
}
vector<int> dfs(int u,int r){
    if(!r) return vector<int>{u-(1<<k)+1};
    return merge(dfs(u*2,r-1),dfs(u*2+1,r-1),op[u],r);
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=m;i++) scanf("%d",&q[i]);
    int K=Log[n-1]+1;
    int now=(1<<K)-1;
    for(int i=K-1;i>=0;i--){
        for(int j=now-(1<<i)+1;j<=now;j++) scanf("%1d",&op[j]);
        now-=(1<<i);
    }
    scanf("%d",&_);
    for(int o=1;o<=_;o++){
        for(int i=0;i<=3;i++) scanf("%d",&x[i]);
        for(int i=1;i<=n;i++) a[i]=b[i]^x[i%4];
        LL _ans=0;
        for(int i=1;i<=m;i++){
            k=Log[q[i]-1]+1;
            for(int j=1;j<=q[i];j++) val[j]=a[j];
            for(int j=q[i]+1;j<=(1<<k);j++) val[j]=-1;
            vector<int> ans=dfs(1,k);
            LL sum=0;
            for(auto x:ans) sum+=x;
            _ans^=(i*sum);
        }
        printf("%lld\n",_ans);
    }
    return 0;
}

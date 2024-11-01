#include<bits/stdc++.h>
using namespace std;
int n;
int maxn=-1;
int a[200005];
int vis[200005];
void dfs(int x){
    if(x>n){
        int lar=0,lab=0,sum=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                if(a[lar]==a[i]){
                    sum+=a[i];
                }
                lar=i;
            }else{
                if(a[lab]==a[i]){
                    sum+=a[i];
                }
                lab=i;
            }
        }
        maxn=max(maxn,sum);
        return ;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        dfs(1);
        cout<<maxn<<'\n';
        maxn=-1;
    }
    return 0;
}

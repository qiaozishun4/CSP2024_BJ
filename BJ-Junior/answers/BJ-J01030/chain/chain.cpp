#include<bits/stdc++.h>
using namespace std;
int n,k,q,m[100005];
vector<int> a[100005];
bool flag;
void dfs(int x,int bg,int fa,int c,int r){
    if(flag)return;
    if(x>r){
        if(bg==c)flag=true;
        return;
    }
    for(int i=1;i<=n;i++){
        if(i==fa)continue;
        for(int j=1;j<=m[i];j++){
            if(a[i][j]==bg){
                for(int z=1;z<=k-1;z++){
                    dfs(x+1,a[i][j+z],i,c,r);
                }
            }
        }
    }
}
void solve(){
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&m[i]);
        a[i].clear();
        a[i].push_back(-1);
        for(int j=1;j<=m[i];j++){
            int x;
            scanf("%d",&x);
            a[i].push_back(x);
        }
    }
    while(q--){
        int r,c;
        scanf("%d%d",&r,&c);
        flag=false;
        if(r==1){
            for(int i=1;i<=n;i++){
                int f=0;
                for(int j=1;j<=m[i];j++){
                    if(a[i][j]==1)f=j;
                    if(a[i][j]==c){
                        if(f==0)continue;
                        else{
                            if(j-f+1<=k){
                                flag=true;
                                break;
                            }
                        }
                    }
                }
                if(flag)break;
            }
            if(flag)printf("1\n");
            else printf("0\n");
            continue;
        }
        dfs(1,1,-1,c,r);
        if(flag)printf("1\n");
        else printf("0\n");
    }

}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[1005][2005];
struct node{
    int r,c;
};
vector<node> adj[200005];
bool dfs(int cur,int k,int pre,int last,int maxs){
    if(cur>k){
        if(pre==1){
            return 1;
        }
        return 0;
    }
    for(auto x:adj[pre]){
        int r=x.r,c=x.c;
        if(r==last){
            continue;
        }
        for(int len=2;len<=maxs;len++){
            int l=c-len+1;
            if(l<1){
                break;
            }
            if(dfs(cur+1,k,a[r][l],r,maxs)){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i=1;i<=200000;i++){
            while(!adj[i].empty()){
                adj[i].pop_back();
            }
        }
        int n,k,q,r,c;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>a[i][0];
            for(int j=1;j<=a[i][0];j++){
                cin>>a[i][j];
                adj[a[i][j]].push_back({i,j});
            }
        }
        while(q--){
            cin>>r>>c;
            bool f=dfs(1,r,c,0,k);
            cout<<f<<endl;
        }
    }
    return 0;
}

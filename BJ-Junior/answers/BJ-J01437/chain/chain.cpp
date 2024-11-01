#include <bits/stdc++.h>

using namespace std;

struct edge{
    int idx,to;
};
vector<edge> v[2005];
int a[2005];
int r,c;
int ans[100][2005];
bool flag;

void dfs(int round,int x,int place){
    if(round!=-1)
        ans[round][x]=1;
    if(round==10)return;
    for(auto xx:v[x]){
        if(xx.idx==place)continue;
        dfs(round+1,xx.to,xx.idx);
        if(flag)return;
    }
}

int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                cin>>a[j];
                if(a[j]==1)v[0].push_back({i,1});
            }
            for(int j=1;j<l;j++){
                for(int m=j+1;m<=min(l,j+k-1);m++){
                    v[a[j]].push_back({i,a[m]});
                }
            }
        }
        dfs(-1,0,0);
        while(q--){
            cin>>r>>c;
            cout<<ans[r][c]<<endl;
        }
    }
    return 0;
}

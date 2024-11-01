#include<bits/stdc++.h>
using namespace std;
int t,f=1;
int c,r;
int n,m,q;
vector<int> v[200005];
int dis[25][25][25][25];
void dfs(int lastnum,int lastid,int step){
    if(step==r+1){
        f=1;
        return;
    }
    for(int i=1;i<=n;i++){
        if(lastid==i)continue;
        for(int j=0;j<v[i].size();j++){
            if(dis[lastid][lastnum][i][j]){
                for(int k=j;k<=j+m-1;k++){
                    dfs(k,i,step+1);
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            v[i].clear();
            int l;cin>>l;
            for(int j=1;j<=l;j++){
                int x;cin>>x;
                v[i].push_back(x);
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<v[i].size();j++){
                for(int k=i+1;k<=n;k++){
                    if(i==k)continue;
                    for(int s=0;s<v[k].size();s++){
                        if(v[i][j]==v[k][s])dis[i][j][k][s]=1;
                    }
                }
            }
        }
        f=0;
        for(int i=1;i<=q;i++){
            cin>>c>>r;
            for(int j=1;j<=n&&!f;j++){
                for(int k=0;k<v[j].size()&&!f;k++){
                    if(v[j][k]==c)dfs(k,j,1);
                }
            }
        }
        cout<<f<<endl;

    }
    return 0;
}

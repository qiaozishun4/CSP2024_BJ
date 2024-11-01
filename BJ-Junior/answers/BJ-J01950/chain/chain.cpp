#include<bits/stdc++.h>
using namespace std;
int n,k,q,t,l[100005];
vector<int> v[100005];
int r,c;
vector<bool> p[100005];
bool dfs(int now,int val,int fa){
    //cout<<now<<' '<<val<<'\n';
    if(now==r){
        if(val==c) return true;
        return false;
    }
    for(int i=1;i<=n;i++){
        if(i==fa) continue;
        for(int j=0;j<l[i];j++){
            if(v[i][j]==val){
                for(int f=j+1;f<=min(int(v[i].size())-1,j+k-1);f++){
                    if(dfs(now+1,v[i][f],i)) return true;
                }
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            p[i].clear();
            for(int j=1;j<=l[i];j++){
                cin>>r;
                v[i].push_back(r);
            }
        }
        while(q--){
            cin>>r>>c;
            cout<<int(dfs(0,1,0))<<'\n';
        }
    }
    return 0;
}

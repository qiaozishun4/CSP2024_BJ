#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
#define pii pair<int,int>
ll n,q,k;
set<int>v[200005];
set<int>s[105];
void dfs(int x,int cnt){
    if(cnt>100)return;
    s[cnt].insert(x);
    for(int i:v[x]){
        dfs(i,cnt+1);
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;cin>>T;
    while(T--){
        memset(v,0,sizeof v);
        for(int i=1;i<=100;i++)s[i].clear();
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            vector<int>sh;
            sh.pb(0);
            cin>>l;
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
                sh.pb(x);
                for(int m=max(j-k,(ll)1);m<j;m++){
                    v[sh[m]].insert(sh[j]);
                }
            }
            return 0;
        }
        dfs(1,0);
        while(q--){
            int r,c;
            cin>>r>>c;
            if(s[r].count(c)>0)cout<<1<<'\n';
            else cout<<"0\n";
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int r,c;
bool ans=false;
const int N=1e5+5;
vector<int>s[N];
void dfs(int have_vis,int last,int cannot){
    if(have_vis==r){
      if(last!=c) return;
      ans=true;
      return;
    }
    if(ans) return;
    for(int now=1;now<=n;now++){
        if(ans) return;
        if(now==cannot) continue;
        for(int i=0;i<s[now].size();i++){
            if(s[now][i]==last){
                for(int j=1;j<k&&i+j<s[now].size();j++){
                    dfs(have_vis+1,s[now][i+j],now);
                    if(ans) return;
                }
            }
        }
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        ans=false;
        for(int i=0;i<N;i++)s[i].clear();
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
                s[i].push_back(x);
            }
        }
        while(q--){
            ans=false;
            cin>>r>>c;
            dfs(0,1,0);
            cout<<ans<<endl;
            ans=false;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,k,q,r[100005],c[100005],ans=0;
vector<int> s(100005);
void dfs(int a,int b,int step,int o,int p){
    if(step>o){
        if(s[a][b]==p){
            ans=1;
        }
        return;
    }
    for(int i=b+1;i<=b+k-1;i++){
        for(int j=1;j<=n;j++){
            if(j==a) continue;
            for(int k=1;k<=s[j].size()-1;k++){
                if(s[j][k]==s[a][i]){
                    dfs(l,k,step+1,o,p);
                }
            }
        }
    }
}
void solve(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        s[i].push_back(-1);
        for(int j=1;j<=l;j++){
            int user;
            cin>>user;
            s[i].push_back(user);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i]>>c[i];
    }
    for(int g=1;g<=q;g++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=s[i].size()-1;j++){
                if(s[i][j]==1){
                    dfs(i,j,1,r[g],c[g]);
                }
            }
        }
        if(ans) cout<<1<<endl;
        else cout<<0<<endl;
        ans=0;
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
    fclose(stdin);
    fclose(stdout);
    return 0;
}
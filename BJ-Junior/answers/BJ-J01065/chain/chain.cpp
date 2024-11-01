#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k,q,l[1010],s[1010][2010],r[1010],c[1010];
bool ok=false;
void dfs(int round,int idx,int lastp,int lastc){
    if(ok)return;
    if(round>r[idx]){
        if(lastc==c[idx]){
            ok=true;
        }
        return;
    }
    for(int p=1;p<=n;p++){
        if(p==lastp)continue;
        for(int i=1;i<=l[p];i++){
            if(s[p][i]==lastc)
            for(int len=2;len<=k&&i+len-1<=l[p];len++){
                int ed=i+len-1;
                dfs(round+1,idx,p,s[p][ed]);
                if(ok)return;
            }
        }
        
    }
}
void solve(){
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        cin>>l[i];
        for(int j=1;j<=l[i];j++){
            cin>>s[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r[i]>>c[i];
        dfs(1,i,-1,1);
        cout<<ok<<"\n";
        ok=0;
    }
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int t,n,k,q;
int s[10010][10010];
int l[10010];
int r[10010],c[10010];
bool dfs(int ql,int nn,int rr,int cc){
    if(rr==0&&ql==cc){
        return true;
    }else if(rr==0&&ql!=cc){
        return false;
    }
    bool ans=false;
    for(int i=1;i<=n;i++){
        if(i!=nn){
            for(int j=1;j<=l[i];j++){
                if(s[i][j]==ql){
                    for(int ij=j+1;ij<=min(l[i],j+k);ij++){
                        ans=ans||dfs(s[i][ij],i,rr-1,cc);
                    }
                }
            }
        }
    }
    return ans;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r[i]>>c[i];
            cout<<dfs(1,10001,r[i],c[i]);
        }
    }
    return 0;
}

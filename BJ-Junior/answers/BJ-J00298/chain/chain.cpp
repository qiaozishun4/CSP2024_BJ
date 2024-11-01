#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c;
vector<int> a[200000];
bool ans=0;
void dfs(int id,int cnt,int la){
    if(cnt==r+1){
        if(la==c){
            ans=1;
        }
        return;
    }
    if(ans) return;
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            if(a[i][j]==la && i!=id){
                for(int len=2;len<=k && j+len-1<a[i].size();len++){
                    dfs(i,cnt+1,a[i][j+len-1]);
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
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
                a[i].push_back(x);
            }
        }
        while(q--){
            cin>>r>>c;
            ans=0;
            dfs(-1,0,1);
            cout<<ans<<endl;
        }
    }

    return 0;
}


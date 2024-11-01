#include<bits/stdc++.h>
using namespace std;
vector<int>v[200050];
int r,c,mp[1005][2050];
int  ans=0;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(mp,0,sizeof mp);
        int n,m,q;
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
                v[i].push_back(x);
            }
        }
        for(int i=1;i<=n;i++){
            int p=0;
            for(int j=0;j<v[i].size();j++){
                if(p>0){
                    p--;
                    mp[i][j]=1;
                }
                if(v[i][j]==1){
                    p=m-1;
                }
            }
        }
        while(q--){
            cin>>r>>c;
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<v[i].size();j++){
                    if(v[i][j]==c){
                        if(mp[i][j]){
                            ans=1;
                            break;
                        }
                    }
                }
                if(ans)break;
            }
            cout<<ans<<endl;
        } 
    }
    return 0;
}
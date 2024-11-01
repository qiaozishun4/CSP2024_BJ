
#include<bits/stdc++.h>
using namespace std;
int T;
int n,m,d;
int x,y,k;

int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
   cin>>T;
   while(T--){
        char mp[2008][2008];
        cin>>n>>m>>d;
        cin>>x>>y>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        if(n==1&&m<=2){
            if(m==1)cout<<1<<endl;
            if(m==2){
                if(mp[1][1]=='.'&&mp[1][2]=='.')cout<<2<<endl;
                else cout<<1<<endl;
            }
        }else if(k==1){
            if(mp[x+1][y]=='.'||mp[x][y+1]=='.'||mp[x-1][y]=='.'||mp[x][y-1]=='.'){
                cout<<2<<endl;
            }
            else cout<<1<<endl;
        }else {
            int ans=n*m;
            if(ans>k)cout<<k+1<<endl;
            else if(ans<=k)cout<<ans<<endl;

        }
   }




return 0;
}

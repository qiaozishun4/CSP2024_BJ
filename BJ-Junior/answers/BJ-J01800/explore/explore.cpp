#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int ans[100005];
    int t;
    cin>>t;
    for(int o=0;o<t;o++){
            int n,m,k,x,y,d;
            char a[1005][1005];
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        ans[o]=1;
        while(k--){
        if(d==0&&y+1<=m&&a[x][y+1]=='.'){
            ans[o]++;
            y++;
            }else if(d==1&&x+1<=n&&a[x+1][y]=='.'){
            ans[o]++;
            x++;
            }else if(d==2&&a[x][y-1]=='.'){
            ans[o]++;
            y--;
            }else if(d==3&&a[x-1][y]=='.'){
            ans[o]++;
            x--;
            }else{
                d=(d+1)%4;
            }
        }
    }
    for(int i=0;i<t;i++){
        cout<<ans[i]<<"\n";
    }

return 0;
}

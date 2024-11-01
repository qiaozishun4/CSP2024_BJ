#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,k,x,y,d;
char a[1005][1005];
bool f[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        int ans=1;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                f[i][j]=false;
            }
        }
        f[x][y]=true;
        while(k--){
            if(d==0){
                if(y+1<=m&&a[x][y+1]!='x'){
                    y++;
                    if(!f[x][y]){
                        ans++;
                        f[x][y]=true;
                    }
                }else d=(d+1)%4;
            }else if(d==1){
                if(x+1<=n&&a[x+1][y]!='x'){
                    x++;
                    if(!f[x][y]){
                        ans++;
                        f[x][y]=true;
                    }
                }else d=(d+1)%4;
            }else if(d==2){
                if(y-1>=1&&a[x][y-1]!='x'){
                    y--;
                    if(!f[x][y]){
                        ans++;
                        f[x][y]=true;
                    }
                }else d=(d+1)%4;
            }else if(d==3){
                if(x-1>=1&&a[x-1][y]!='x'){
                    x--;
                    if(!f[x][y]){
                        ans++;
                        f[x][y]=true;
                    }
                }else d=(d+1)%4;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

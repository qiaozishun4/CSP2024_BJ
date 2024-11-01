#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x,y,d;
    char a[1005][1005];
    cin>>t;
    while(t--){
        int ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
        while(k--){
            a[x][y]='1';
            if(d==0&&a[x][y+1]!='x'&&y+1<=m){
                y++;
                a[x][y]='1';
            }
            else if(d==1&&a[x+1][y]!='x'&&x+1<=n){
                    x++;
                    a[x][y]='1';
            }
            else if(d==2&&a[x][y-1]!='x'&&y-1>=1){
                    y--;
                    a[x][y]='1';
            }
            else if(d==3&&a[x-1][y]!='x'&&x-1>=1){
                    x--;
                    a[x][y]='1';
            }
            else d=(d+1)%4;
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]=='1')ans++;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

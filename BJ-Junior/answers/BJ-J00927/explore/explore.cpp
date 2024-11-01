#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int ci;cin>>ci;
    while(ci--){
        int n,m,k;
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            char s[1005];cin>>s;
            for(int j=1;j<=m;j++){
                if(s[j-1]=='.')dp[i][j]=0;
                if(s[j-1]=='x')dp[i][j]=1;
            }
        }
        for (int i=1;i<=k;i++){
            dp[x][y]=2;
            if(d==0&&y+1<=m&&dp[x][y+1]!=1){y+=1;continue;}
            else if(d==1&&x+1<=n&&dp[x+1][y]!=1){x+=1;continue;}
            else if(d==2&&y-1>=1&&dp[x][y-1]!=1){y-=1;continue;}
            else if(d==3&&x-1>=1&&dp[x-1][y]!=1){x-=1;continue;}
            else d=(d+1)%4;
        }
        dp[x][y]=2;
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(dp[i][j]==2)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

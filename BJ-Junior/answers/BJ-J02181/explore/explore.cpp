#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,zhi,zou[4][4]={{0,1},{1,0},{0,-1},{-1,0}};
bool f[1003][1003];
string s[1003];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d);
        zhi=0;
        for(int j=0;j<n;j++){
            cin>>s[j];
        }
        if(f[x][y]==0){
                f[x][y]=1;
                zhi++;
        }
        for(int j=0;j<k;){
            int sh=0;
            while(1){
                if(sh>=5)break;
                if(x+zou[d][0]<=n&&x+zou[d][0]>=1&&y+zou[d][1]>=1&&y+zou[d][1]<=m){
                    if(s[x+zou[d][0]-1][y+zou[d][1]-1]=='.')break;
                }
                d=(d+1)%4;sh++;
            }
            if(sh>=5)break;if(j+sh+1>k)break;j+=sh;
            x+=zou[d][0];y+=zou[d][1];
            if(f[x][y]==0){
                f[x][y]=1;
                zhi++;
            }j++;
        }
        printf("%d\n",zhi);
        for(int j=1;j<=n;j++){
            for(int o=1;o<=m;o++)f[j][o]=0;
        }
    }
    return 0;
}
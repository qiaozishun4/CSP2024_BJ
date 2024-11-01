#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,x,y,d,ans;
char a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%s",a[i][j]);
            }
        }
        for(int i=1;i<=k;i++){
            a[x][y]='x';
            if(d==0){
                if(x<=n&&y+1<=m&&a[x][y+1]!='x'){
                    y+=1;
                    ans++;
                }else{
                    d=(d+1)%4;
                }
            }else if(d==1){
                if(x+1<=n&&y<=m&&a[x+1][y]!='x'){
                    x+=1;
                    ans++;
                }else{
                    d=(d+1)%4;
                }

            }else if(d==2){
                if(x<=n&&y-1<=m&&a[x][y-1]!='x'){
                    y-=1;
                    ans++;
                }else{
                    d=(d+1)%4;
                }

            }else if(d==3){
                if(x-1<=n&&y<=m&&a[x-1][y]!='x'){
                    x-=1;
                    ans++;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        printf("%d",ans);
    }
    return 0;
}
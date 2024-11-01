#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k;
char a[1010][1010];
bool ismove[1010][1010];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        long long x,y,d,x1,y1;
        cin>>x>>y>>d;
        memset(a,0,sizeof(a));
        memset(ismove,0,sizeof(ismove));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        long long ans=0;
        while(k--){
            x1=x;y1=y;
            ismove[x][y]=1;
            if(d==0){
                y1++;
            }if(d==1){
                x1++;
            }if(d==2){
                y1--;
            }if(d==3){
                x1--;
            }
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&a[x1][y1]=='.'){
                x=x1;y=y1;
                ismove[x][y]=1;
            }else{
                d=(d+1)%4;
            }


        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(ismove[i][j]){
                        ans++;
                    }
                }
            }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
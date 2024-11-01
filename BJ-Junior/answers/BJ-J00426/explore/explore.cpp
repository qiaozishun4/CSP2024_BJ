#include<bits/stdc++.h>
using namespace std;
int t,m,n,k,x,y,d;
char ma[1005][1005];
bool f[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        memset(f,0,sizeof(f));
        int ans=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        f[x][y]=1;
        for(int j=1;j<=n;j++){
            for(int s=1;s<=m;s++){
                cin>>ma[j][s];
            }
        }
        for(int a=1;a<=k;a++){
			int x1=x,y1=y;
            if(d==0){
                y1++;
            }
            if(d==1){
                x1++;
            }
            if(d==2){
                y1--;
            }
            if(d==3){
                x1--;
            }
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&ma[x1][y1]=='.'){
                x=x1;
                y=y1;
                f[x][y]=1;
            }else{
                d=(d+1)%4;
            }
        }
        for(int b=1;b<=n;b++){
            for(int c=1;c<=m;c++){
                if(f[b][c]==1){
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
 }


#include <bits/stdc++.h>
using namespace std;
using l=long long;
l T,n,m,k,x,y,d,ans;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int lun=1;lun<=T;lun++){
        l x1=0,y1=0;
        ans = 0;
        bool t[1005][1005]={};
        bool a[1005][1005]={};
        cin>>n>>m>>k>>x>>y>>d;
        a[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char charin;
                cin>>charin;
                if(charin == '.')t[i][j]=1;
                else t[i][j]=0;
            }
        }
        for(int i=1;i<=k;i++){
            if(d==0){
                x1=x;y1=y+1;
                if(t[x1][y1]==0)d = (d+1)%4;
                else{
                    x = x1;y = y1;
                }
            }
            else if(d==1){
                x1=x+1;y1=y;
                if(t[x1][y1]==0)d = (d+1)%4;
                else{
                    x = x1;y = y1;
                }
            }
            else if(d==2){
                x1=x;y1=y-1;
                if(t[x1][y1]==0)d = (d+1)%4;
                else{
                    x = x1;y = y1;
                }
            }
            else if(d==3){
                x1=x-1;y1=y;
                if(t[x1][y1]==0)d = (d+1)%4;
                else{
                    x = x1;y = y1;
                }
            }
            a[x][y] = 1;
            //cout<<d<<endl;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //cout<<a[i][j];
                if(a[i][j])ans++;
            }//cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}

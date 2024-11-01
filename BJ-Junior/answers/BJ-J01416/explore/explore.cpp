#include <iostream>
using namespace std;
int T,n,m,k,x,y,d,ans;
bool v[1145][1145],mp[1145][1145];
char c;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>c;
                if(c=='x')mp[j][k]=1;
            }
        }
        v[x][y]=1;
        for(int j=1;j<=k;j++){
            if(d==0){
                if(y+1<=m&&mp[x][y+1]==0)
                    y+=1;
                else
                    d=1;
            }else if(d==1){
                if(x+1<=n&&mp[x+1][y]==0)
                    x+=1;
                else
                    d=2;
            }else if(d==2){
                if(y-1>=1&&mp[x][y-1]==0)
                    y-=1;
                else
                    d=3;
            }else if(d==3){
                if(x-1>=1&&mp[x-1][y]==0)
                    x-=1;
                else
                    d=0;
            }
            v[x][y]=1;
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(v[i][j])ans++;
            }
        }cout<<ans<<endl;
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mp[i][j]=v[i][j]=0;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char c[1010][1010];
int s[1010][1010];
int dx[10]={0,1,0,-1};
int dy[10]={1,0,-1,0};
int n,m,k,ans;
int x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    for(int e=1;e<=T;e++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
             for(int l=1;l<=m;l++){
                cin>>c[j][l];
                s[j][l]=0;
            }
        }
        while(k--){
            for(int i=1;i<=4;i++,d=(d+1)%4){
                int tx=x+dx[d],ty=y+dy[d];
                if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&c[tx][ty]!='x'){
                    x=tx,y=ty;
                    if(!s[tx][ty])ans++;
                    s[tx][ty]=1;
                    break;
                }else{
                    k--;
                    if(k==0)break;
                }
            }
        }
        cout<<ans+1;
        ans=0;
    }
    return 0;
}


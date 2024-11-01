#include<bits/stdc++.h>
using namespace std;
map<string,bool> m;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        int x,y,d;
        scanf("%d%d%d",&n,&m,&k);
        scanf("%d%d%d",&x,&y,&d);
        bool a[1005][1005]={};
        bool l[1005][1005]={};
        char s;
        l[x][y]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
               cin>>s;
               if(s=='.')a[i][j]=0;
               else a[i][j]=1;
            }
        }
        int ans=1;
        for(int i=1;i<=k;i++){
            if(d==0){
                if(y+1>m||a[x][y+1]==1)d=(d+1)%4;
                else{
                    if(l[x][y+1]==0){
                        l[x][y+1]=1;
                        ans++;
                    }
                    y++;
                }
            }
            else if(d==1){
                if(x+1>n||a[x+1][y]==1)d=(d+1)%4;
                else{
                    if(l[x+1][y]==0){
                        l[x+1][y]=1;
                        ans++;
                    }
                    x++;
                }
            }
            else if(d==2){
                if(y-1<1||a[x][y-1]==1)d=(d+1)%4;
                else{
                    if(l[x][y-1]==0){
                        l[x][y-1]=1;
                        ans++;
                    }
                    y--;
                }
            }
            else {
                if(x-1<1||a[x-1][y]==1)d=(d+1)%4;
                else{
                    if(l[x-1][y]==0){
                        l[x-1][y]=1;
                        ans++;
                    }
                    x--;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

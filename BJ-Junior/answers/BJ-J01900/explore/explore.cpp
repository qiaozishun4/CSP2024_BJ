#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,d,sum,x,y;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        sum=1;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        char c;
        long long f[1002][1002];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='.'){
                    f[i][j]=1;
                }
                else f[i][j]=0;
            }
        }
        f[x][y]=2;
        while(k--){
            if(d==0){
                if(f[x][y+1]==0){
                    d=1;
                }
                else{
                    if(f[x][y+1]==1){
                        f[x][y+1]=2;
                        sum++;
                    }
                    y++;
                }
            }else if(d==1){
                if(f[x+1][y]==0){
                    d=2;
                }
                else{
                    if(f[x+1][y]==1){
                        f[x+1][y]=2;
                        sum++;
                    }
                    x++;
                }
            }else if(d==2){
                if(f[x][y-1]==0){
                    d=3;
                }
                else{
                    if(f[x][y-1]==1){
                        f[x][y-1]=2;
                        sum++;
                    }
                    y--;
                }
            }else if(d==3){
                if(f[x-1][y]==0){
                    d=0;
                }
                else{
                    if(f[x-1][y]==1){
                        f[x-1][y]=2;
                        sum++;
                    }
                    x--;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

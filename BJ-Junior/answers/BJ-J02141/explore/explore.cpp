#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,x,y,d;
char s[1001][1001];
long long v[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        long long sum=0;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>s[i][j];
                v[i][j]=0;
            }
        }
        v[x][y]=1;
        sum++;
        for(long long i=1;i<=k;i++){
            if(d==0){
                long long xx=x,yy=y+1;
                if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&s[xx][yy]=='.'){
                    if(v[xx][yy]==0){
                        y+=1;
                        sum++;
                        v[xx][yy]=1;
                    }else{
                        y+=1;
                    }
                    continue;
                }else{
                    d=1;
                    continue;
                }
            }else if(d==1){
                long long xx=x+1,yy=y;
                if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&s[xx][yy]=='.'){
                    if(v[xx][yy]==0){
                        x+=1;
                        sum++;
                        v[xx][yy]=1;
                    }else{
                        x+=1;
                    }
                    continue;
                }else{
                    d=2;
                    continue;
                }
            }else if(d==2){
                long long xx=x,yy=y-1;
                if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&s[xx][yy]=='.'){
                    if(v[xx][yy]==0){
                        y-=1;
                        sum++;
                        v[xx][yy]=1;
                    }else{
                        y-=1;
                    }
                    continue;
                }else{
                    d=3;
                    continue;
                }
            }else if(d==3){
                long long xx=x-1,yy=y;
                if(xx<=n&&xx>=1&&yy<=m&&yy>=1&&s[xx][yy]=='.'){
                    if(v[xx][yy]==0){
                        x-=1;
                        sum++;
                        v[xx][yy]=1;
                    }else{
                        x-=1;
                    }
                    continue;
                }else{
                    d=0;
                    continue;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

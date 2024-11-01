#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,k;
int T;
char map[1001][1001];
int note[1001][1001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){

       cin>>n>>m>>k;
       for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                note[i][j]=0;
            }
       }
       long long x,y,d;
       cin>>x>>y>>d;
       long long ans=1;
       note[x][y]=1;
       for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                cin>>map[i][j];
            }
       }
       for(long long i=1;i<=k;i++){
            if(d==0){
                if(map[x][y+1]=='.'&&x<=n&&x>=1&&y+1<=m&&y+1>=1){
                    y=y+1;
                }else{
                    d=1;
                }
            }else if(d==1){
                if(map[x+1][y]=='.'&&x+1<=n&&x+1>=1&&y<=m&&y>=1){
                    x=x+1;
                }else{
                    d=2;
                }
            }else if(d==2){
                if(map[x][y-1]=='.'&&x<=n&&x>=1&&y-1<=m&&y-1>=1){
                    y=y-1;
                }else{
                    d=3;
                }
            }else if(d==3){
                if(map[x-1][y]=='.'&&x-1<=n&&x-1>=1&&y<=m&&y>=1){
                    x=x-1;
                }else{
                    d=0;
                }
            }
            if(note[x][y]==0){
                note[x][y]=1;
                ans++;
            }
       }
       cout<<ans<<endl;
    }
    return 0;
}

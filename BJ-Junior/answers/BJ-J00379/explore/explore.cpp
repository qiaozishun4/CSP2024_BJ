#include <bits/stdc++.h>
using namespace std;
long long n,m,k,x,y,ans=1,nt[10000][10000];
char mp[10000][10000];
int d,t;
bool iskongdi(long long x1,long long y1){
    if(1<=x1<=n&&1<=y1<=m&&mp[x1][y1]=='.'){
            return true;
    }
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(long long nn=1;nn<=n;nn++){
            for(long long mm=1;mm<=m;mm++){
                cin>>mp[nn][mm];
            }
        }
        nt[x][y]=1;
        for(long long j=0;j<k;j++){
            if(d==0&&iskongdi(x,y+1)){
                y+=1;
                if(nt[x][y]==0){
                    ans+=1;
                    nt[x][y]=1;
                }
            }else if(d==1&&iskongdi(x+1,y)){
                x+=1;
                if(nt[x][y]==0){
                    ans+=1;
                    nt[x][y]=1;
                }
            }else if(d==2&&iskongdi(x,y-1)){
                y-=1;
                if(nt[x][y]==0){
                    ans+=1;
                    nt[x][y]=1;
                }
            }else if(d==3&&iskongdi(x-1,y)){
                x-=1;
                if(nt[x][y]==0){
                    ans+=1;
                    nt[x][y]=1;
                }
            }else{
                d=(d+1)%4;
            }
        }
        for(long long p=1;p<=n;p++){
            for(long long q=1;q<=m;q++){
                nt[p][q]=0;
            }
        }
        cout<<ans<<endl;
        ans=1;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,m,kk,xx,yy,dd;
long long ans=1;
int a[1010][1010],mem[1010][1010];
char c;
void find(int x,int y,int d,int k){
    if(k==0) return;
    if(d==0){
        if(a[x][y+1]==1){
            find(x,y,d+1,k-1);
        }
        else{
            find(x,y+1,d,k-1);
            if(mem[x][y+1]==0){
                mem[x][y+1]=1;
                ans++;
            }
        }
    }
    if(d==1){
        if(a[x+1][y]==1){
            find(x,y,d+1,k-1);

        }
        else{
            find(x+1,y,d,k-1);
            if(mem[x+1][y]==0){
                mem[x+1][y]=1;
                ans++;
            }
        }
    }
    if(d==2){
        if(a[x][y-1]==1){
            find(x,y,d+1,k-1);

        }
        else{
            find(x,y-1,d,k-1);
            if(mem[x][y-1]==0){
                mem[x][y-1]=1;
                ans++;
            }
        }
    }
    if(d==3){
        if(a[x-1][y]==1){
            find(x,y,0,k-1);

        }
        else{
            find(x-1,y,d,k-1);
            if(mem[x-1][y]==0){
                mem[x-1][y]=1;
                ans++;
            }
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        ans=1;
        cin>>n>>m>>kk;
        cin>>xx>>yy>>dd;
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++){
                a[i][j]=1;
                mem[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>c;
                if(c=='.') a[i][j]=0;
            }
        }
        mem[xx][yy]=1;
        find(xx,yy,dd,kk);
        cout<<ans<<endl;
    }
    return 0;
}

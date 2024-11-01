#include<bits/stdc++.h>
using namespace std;
char g[11000][11000];
int n,m,k;
bool visit[11000][11000];
int dix(int d){
    if(d==0){
        return 0;
    }else if(d==1){
        return 1;
    }else if(d==2){
        return 0;
    }else if(d==3){
        return -1;
    }
}
int diy(int d){
    if(d==0){
        return 1;
    }else if(d==1){
        return 0;
    }else if(d==2){
        return -1;
    }else if(d==3){
        return 0;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        memset(visit,sizeof(visit),0);
        int x0,y0,d;
        cin>>n>>m>>k;
        cin>>x0>>y0>>d;
        visit[x0][y0]=1;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                cin>>g[j][p];
            }
        }
        while(k!=0){
            int x1=dix(d);
            int y1=diy(d);
            if(g[x0+x1][y0+y1]=='.' && x0+x1>=1 && x0+x1<=n && y0+y1>=1 &&y0+y1<=m){
                x0=x0+x1;y0=y0+y1;
                visit[x0][y0]=1;
                k--;
            }else{
                d=(d+1)%4;
                k--;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            for(int p=1;p<=m;p++){
                if(visit[j][p]) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

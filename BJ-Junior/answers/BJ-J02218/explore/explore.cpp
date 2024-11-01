#include<bits/stdc++.h>
#define Maxn 1004
using namespace std;
int m,n,nx,ny,ans;
char Map[Maxn][Maxn];
bool founded[Maxn][Maxn];
bool Move(int d){
    int dx=nx,dy=ny;
    if(d==0) dy++;
    else if(d==1) dx++;
    else if(d==2) dy--;
    else if(d==3) dx--;
    if(founded[nx][ny]==false) founded[nx][ny]==true;
    if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&Map[dx][dy]=='.'){
        nx=dx;
        ny=dy;
        founded[dx][dy]=true;
        return true;
    }
    return false;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T,k,d;
    cin>>T;
    for(int t=0;t<T;t++){
        ans=0;
        for(int i=0;i<Maxn;i++){
            for(int j=0;j<Maxn;j++){
                founded[i][j]=false;
                Map[i][j]=' ';
            }
        }
        cin>>n>>m>>k;
        cin>>nx>>ny>>d;
        founded[nx][ny]=true;
        string s;
        for(int i=1;i<=n;i++){
            cin>>s;
            for(int j=1;j<=m;j++) Map[i][j]=s[j-1];
        }
        for(int i=0;i<k;i++){
            bool turn=Move(d);
            if(turn==false) d=((d+1)%4);
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(founded[i][j]==true) ans++;
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

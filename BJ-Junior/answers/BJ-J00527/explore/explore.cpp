#include <bits/stdc++.h>
using namespace std;
int T,n,m,x,y,d0,k,cnt;
bool b1,b2,b3,b4,flag[1001][1001];
char ma[1001][1001];
string s;
void dfs(int d,int xx,int yy,int kk){
    int xx0=xx,yy0=yy,kk0=kk-1;
    if(kk0==-1){
        return;
    }
    if(d==1){
        xx0++;
        if(xx0>=1 && xx0<=n && ma[xx0][yy0]=='.'){
            if(!flag[xx0][yy0]){
                flag[xx0][yy0]=true;
                cnt++;
                //cout << xx0 << yy0 << kk0<< "++\n";
            }
            dfs(d,xx0,yy0,kk0);
        }
        else{
            dfs(d+1,xx,yy,kk0);
            //cout<<"c";
        }
    }
    if(d==2){
        yy0--;
        if(yy0>=1 && yy0<=m && ma[xx0][yy0]=='.'){
            if(!flag[xx0][yy0]){
                flag[xx0][yy0]=true;
                cnt++;
                //cout << xx0 << yy0 << kk0<< "++\n";
            }
            dfs(d,xx0,yy0,kk0);
        }
        else{
            dfs(d+1,xx,yy,kk0);
        }
    }
    if(d==0){
        yy0++;
        if(yy0>=1 && yy0<=m && ma[xx0][yy0]=='.'){
            if(!flag[xx0][yy0]){
                flag[xx0][yy0]=true;
                cnt++;
                //cout << xx0 << yy0 << kk0<< "++\n";
            }
            dfs(d,xx0,yy0,kk0);
        }
        else{
            dfs(d+1,xx,yy,kk0);
        }
    }
    if(d==3){
        xx0--;
        if(xx0>=1 && xx0<=n && ma[xx0][yy0]=='.'){
            if(!flag[xx0][yy0]){
                flag[xx0][yy0]=true;
                cnt++;
                //cout << xx0 << yy0 << kk0<< "++\n";
            }
            dfs(d,xx0,yy0,kk0);
        }
        else{
            dfs(0,xx,yy,kk0);
        }
    }
    return;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    scanf("%d",&T);
    for(int TTT=1;TTT<=T;++TTT){
        cnt=0;
        scanf("%d%d%d%d%d%d",&n,&m,&k,&x,&y,&d0);
        for(int i=1;i<=n;++i){
                cin >> s;
            for(int j=1;j<=m;++j){
                ma[i][j]=s[j-1];
                flag[i][j]=false;
            }
        }
        flag[x][y]=true;
        cnt++;
        dfs(d0,x,y,k);
        printf("%d\n",cnt);
    }
    return 0;
}
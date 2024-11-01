#include<iostream>
using namespace std;
int x,y,s,d,n,m,t,cnt;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool h[1010][1010];
char mp[1010][1010];
void run(){
    int tx=x+dx[d],ty=y+dy[d];
    if(tx<=n&&tx>=1&&ty<=m&&ty>=1&&mp[tx][ty]!='x'){
        if(!h[tx][ty]){
            cnt++;
            h[tx][ty]=true;
        }
        x=tx;
        y=ty;
    }
    else{
        d=(d+1)%4;
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cnt=1;
        cin>>n>>m>>s>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>mp[j][k];
                if(mp[j][k]=='x'){
                    h[j][k]=true;
                }
                else{
                    h[j][k]=false;
                }
            }
        }
        h[x][y]=true;
        for(int j=0;j<s;j++){
            run();
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}

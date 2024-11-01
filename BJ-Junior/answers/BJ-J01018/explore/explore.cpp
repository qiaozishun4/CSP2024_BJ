#include<bits/std.c++>
using namespace std;
char map[2000][2000];
int _map[2000][2000];
int vist[2000][2000];
int sum;
int n,m,o,dqx,dqy,dqd;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>o;
    for(int _a=0;_a<o;_a++){
        cin>>n>>m>>dqx>>dqy>>dqd;
        vist[dqx][dqy]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>map[i][j];
                if(map[i][j]=='.'){
                    _map[i][j]=0;
                }
                else{
                    _map[i][j]=1;
                }
            }
        }
        for(int i=0;i<k;i++){
            if(dqd==0 && dqy+1<=m && _map[dqx][dqy+1]!=1){
                dqy+=1;
                vist[dqx][dqy]=1;
            }
            else if(dqd==1 && dqx+1<=n && _map[dqx+1][dqy]!=1){
                dqx+=1;
                vist[dqx][dqy]=1;
            }
            else if(dqd==2 && dqy-1>=1 && _map[dqx][dqy-1]!=1){
                dqy-=1;
                vist[dqx][dqy]=1;
            }
            else if(dqd==3 && dqx-1>=1 && _map[dqx-1][dqy]!=1){
                dqx-=1;
                vist[dqx][dqy]=1;
            }
            else{
                dqd=(dqd+1)%4;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vist[i][j]=1){
                    sum++;
                }
            }
        }
        cout<<sum<<endl();
    }

    return 0;
    }
    //谢谢老师：）
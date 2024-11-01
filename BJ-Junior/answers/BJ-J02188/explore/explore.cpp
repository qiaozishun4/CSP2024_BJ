#include<bits/stdc++.h>
using namespace std;
int pi,pj,dir,n,m,mp[1005][1005]={},k,d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int vis[1005][1005]={};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int num;
    cin>>num;
    for(int l=0;l<num;l++){
        cin>>n>>m>>k>>pi>>pj>>dir;
        vis[pi][pj]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char t;
                cin>>t;
                if(t=='x')mp[i][j]=1;
                else mp[i][j]=0;
            }
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<mp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        for(int i=0;i<k;i++){
            int nj,ni;
            ni=pi+d[dir][0];
            nj=pj+d[dir][1];
            if(mp[ni][nj]==0&&ni<=n&&nj<=m&&ni>0&&nj>0){
                pi=ni;
                pj=nj;
            }else{
                dir=(dir+1)%4;
            }
            vis[pi][pj]=1;
            //cout<<pi<<" "<<pj<<" "<<dir<<endl;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(vis[i][j])cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

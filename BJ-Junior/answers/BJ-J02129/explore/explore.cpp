#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dir[4][2]={0,1,1,0,0,-1,-1,0};
inline void turn_right(int& d){
    int nd=d+1;
    if(nd>3){
        nd=0;
    }
    d=nd;
}
inline int dfs(vector<string> &mp,int n,int m,int sx,int sy,int sd,int k){
    int rt=1;

    while(k--){
        int nx=sx+dir[sd][0];
        int ny=sy+dir[sd][1];

        if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&mp[nx][ny]=='.'){
                sx=nx;
                sy=ny;
                rt++;


        }
        else{

                turn_right(sd);
                //cout<<"tr ";
            }
            //cout<<"nx:ny="<<nx<<" "<<ny<<"\n";
    }
    return rt;
}
signed main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;
    cin>>T;

    int n,m,k;
    int x0,y0,d0;
    while(T--){
        cin>>n>>m>>k;
        cin>>x0>>y0>>d0;
        vector<string> mp;
        mp.assign(n+1," ");
        for(int i=1;i<=n;i++){
            string l;
            cin>>l;
            mp[i]+=l;

        }
        /*for(int k=1;k<=n;k++){
                for(int f=1;f<=m;f++){
                cout<<mp[k][f]<<" ";
            }
            cout<<"\n";
            }
            */
        cout<<dfs(mp,n,m,x0,y0,d0,k)<<endl;
    }
}

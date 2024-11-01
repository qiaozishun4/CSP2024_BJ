#include<bits/stdc++.h>
using namespace std;
bool a[1005][1005];const short fx[4]={0,1,0,-1},fy[4]={1,0,-1,0};
bool vi[1005][1005];
int dfs(short x,short y,short d,int k){
    int ans=0;
    while(k>0){
        if(a[x+fx[d]][y+fy[d]]){
            while(a[x+fx[d]][y+fy[d]]){
                d=(d+1)%4;
                k--;
            }//return dfs(x,y,d,k);
        }else{
            y+=fy[d],x+=fx[d];--k;
            if(!vi[x][y]){
                vi[x][y]=1;
                ++ans;
            }
        }
    }return ans;
}
void slove(){
    int n,m,k,x0,y0,d0;
    cin>>n>>m>>k>>x0>>y0>>d0;
    for(int i=0;i<=n+1;++i){
        for(int j=0;j<=m+1;++j){
            if(i==0||j==0||i==n+1||j==m+1){
                a[i][j]=1;continue;
            }else {
                char c;cin>>c;
                if(c=='x'){
                    a[i][j]=1;
                }else a[i][j]=0;
            }
        }
    }/*for(int i=0;i<=n+1;++i){
        for(int j=0;j<=m+1;++j){
            cout<<a[i][j]<<' ';
        }cout<<endl;
    }*/
    memset(vi,0,sizeof(vi));
    vi[x0][y0]=1;
    int ans=dfs(x0,y0,d0,k)+1;
    cout<<ans<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}
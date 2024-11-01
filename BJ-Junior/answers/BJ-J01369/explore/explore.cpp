#include<bits/stdc++.h>
using namespace std;
char MAP[1001][1001];
int d1[4]={1,0,-1,0};
int d2[4]={0,1,0,-1};
int sum=1;
int n,m,k,x,y,d;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    for(int a=0;a<t;a++){
        sum=1;
        int vis[1001][1001]={};
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>MAP[i][j];
            }
        }
        while(k--){
            if(x+d2[d]>0 && x+d2[d]<=n && y+d1[d]>0 && y+d1[d]<=m && MAP[x+d2[d]][y+d1[d]]=='.'){
                if(vis[x+d2[d]][y+d2[d]]==0){
                    vis[x+d2[d]][y+d2[d]]++;
                    sum++;
                }
                x+=d2[d];
                y+=d1[d];
            }else{
                d++;
                d%=4;
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

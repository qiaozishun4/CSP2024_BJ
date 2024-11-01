#include<bits/stdc++.h>
using namespace std;
int py[4]={1,0,-1,0};
int px[4]={0,1,0,-1};
int T;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    while(T--){
        int n,m,k,x,y,d,ans=0;
        char ma[1005][1005];
        cin>>n>>m>>k>>x>>y>>d;
        ma[x][y]='#';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>ma[i][j];
            }
        }
        while(k--){
            ma[x][y]='#';
            if(ma[x+px[d]][y+py[d]]=='x'||x+px[d]<=0||x+px[d]>n||y+py[d]<=0||y+py[d]>m){
                d=(d+1)%4;
            }
            else{
                x+=px[d];
                y+=py[d];
            }
            ma[x][y]='#';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(ma[i][j]=='#'){
                   ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
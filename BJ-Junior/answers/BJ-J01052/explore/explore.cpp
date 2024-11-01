#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool b[1005][1005]={false};
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    int n,m,k;
    int x,y,d;
    int ans=0;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }
        while(k--){
            b[x][y]=true;
            if(d==0){
                if(y+1<=m&&a[x][y+1]!='x'){
                    y++;
                }else{
                    d=(d+1)%4;
                }
            }
            if(d==1){
                if(x+1<=n&&a[x+1][y]!='x'){
                    x++;
                }else{
                    d=(d+1)%4;
                }
            }
            if(d==2){
                if(y-1>0&&a[x][y-1]!='x'){
                    y--;
                }else{
                    d=(d+1)%4;
                }
            }
            if(d==3){
                if(x-1>0&&a[x-1][y]!='x'){
                    y--;
                }else{
                    d=(d+1)%4;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(b[i][j]==true){
                    ans++;
                }
                //cout<<b[i][j]<<" ";
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

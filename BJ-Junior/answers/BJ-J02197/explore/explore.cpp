#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,m,k,cnt=1;
        cin>>n>>m>>k;
        int xut,yut,d;
        cin>>xut>>yut>>d;
        char a[n][m];
        bool vis[n][m];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                vis[i][j]=0;
            }
        }
        while(k--){
            if(d==0){
                if(yut+1>=1 && yut+1<=m && a[xut][yut+1]!='x'){
                    if(!vis[xut][yut+1]) cnt+=1;
                    yut+=1;
                }else{
                    d=(d+1)%4;
                }
                vis[xut][yut]=1;
            }
            else if(d==1){
                if(xut+1>=1 && xut+1<=n && a[xut+1][yut]!='x'){
                    if(!vis[xut+1][yut]) cnt+=1;
                    xut+=1;
                }else{
                    d=(d+1)%4;
                }
                vis[xut][yut]=1;
            }
            else if(d==2){
                if(yut-1>=1 && yut-1<=m && a[xut][yut-1]!='x'){
                    if(!vis[xut][yut-1]) cnt+=1;
                    yut-=1;
                }else{
                    d=(d+1)%4;
                }
                vis[xut][yut]=1;
            }
            else if(d==3){
                if(xut-1>=1 && xut-1<=m && a[xut-1][yut]!='x'){
                    if(!vis[xut-1][yut]) cnt+=1;
                    xut-=1;
                }else{
                    d=(d+1)%4;
                }
                vis[xut][yut]=1;
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
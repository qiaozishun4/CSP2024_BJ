#include<bits/stdc++.h>
#define N 1005
using namespace std;
char maps[N][N];
int nowx,nowy,nowd,jl[N][N]={0};
long long ans=0;
int main(){
    FILE* f1=freopen("explore.in","r",stdin);
    FILE* f2=freopen("explore.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=0;
        int n,m,k;
        cin>>n>>m>>k;
        cin>>nowx>>nowy>>nowd;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>maps[i][j];
                jl[i][j]=0;
            }
        }
        while(k--){
            if(!jl[nowx][nowy]){
                ans++;
                jl[nowx][nowy]=1;
            }
            int newx=nowx,newy=nowy,newd=nowd;
            if(nowd==0){
                newy++;
            }
            else if(nowd==1){
                newx++;
            }
            else if(nowd==2){
                newy--;
            }
            else if(nowd==3){
                newx--;
            }
            if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&maps[newx][newy]!='x'){
                nowx=newx;
                nowy=newy;
                nowd=newd;
            }
            else{
                nowd=(nowd+1)%4;
            }
        }
        if(!jl[nowx][nowy]){
            ans++;
            jl[nowx][nowy]=1;
        }
        cout<<ans<<endl;
    }
    fclose(f1);
    fclose(f2);
    return 0;
}


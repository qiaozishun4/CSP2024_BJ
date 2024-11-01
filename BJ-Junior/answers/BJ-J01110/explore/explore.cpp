#include<bits/stdc++.h>
using namespace std;
int dirx[4]={0,1,0,-1};
int diry[4]={1,0,-1,0};
long long n,m,k,x,y,d,ans,t;
int tmp[1007][1007];
char dt[1007][1007];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    for(int l=0;l<t;l++){
        ans=1;
        memset(dt,' ',sizeof(dt));
        memset(tmp,-1,sizeof(tmp));
        cin>>n>>m>>k>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>dt[i][j];
            }
        }
        tmp[x][y]=1;
        for(int i=0;i<k;i++){
            if(dt[x+dirx[d%4]][y+diry[d%4]]=='.'){
                if(tmp[x+dirx[d%4]][y+diry[d%4]]==-1){
                    tmp[x+dirx[d%4]][y+diry[d%4]]=1;
                    ans++;
                }
                x=x+dirx[d%4],y=y+diry[d%4];
            }
            if(dt[x+dirx[d%4]][y+diry[d%4]]!='.'){
                d++;
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
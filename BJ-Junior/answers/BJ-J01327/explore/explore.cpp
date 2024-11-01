#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
//rp++
using namespace std;
int T;
char mymap[1050][1050];
bool vis[1050][1050];
void dfs(int px,int py,int pd,int pk,int n,int m){
    if(pk==0)return;
    vis[px][py]=1;
    int dx,dy;
    if(pd==0)dx=px,dy=py+1;
    if(pd==1)dx=px+1,dy=py;
    if(pd==2)dx=px,dy=py-1;
    if(pd==3)dx=px-1,dy=py;
    if(mymap[dx][dy]=='.' && 1<=dx && dx<=n && dy>=1 && dy<=m)dfs(dx,dy,pd,--pk,n,m);
    else dfs(px,py,(pd+1)%4,--pk,n,m);
}
int myans(int chenzhe,int kkksc03)
{
    int xht=0;
    for(int i=1;i<=chenzhe;i++){
        for(int j=1;j<=kkksc03;j++){
			//cout<<vis[i][j]<<" ";
			if(vis[i][j]==1)xht++;
		}
		//cout<<endl;
    }
    return xht;
}
int main()
{
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        int x,y,d,n,m,k;
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int j=1;j<=n;j++){
            for(int f=1;f<=m;f++)cin>>mymap[j][f];
        }
        dfs(x,y,d,++k,n,m);
        cout<<myans(n,m)<<"\n";
        memset(vis,0,sizeof(vis));
    }
    fclose(stdin);fclose(stdout);
    return 0;
}

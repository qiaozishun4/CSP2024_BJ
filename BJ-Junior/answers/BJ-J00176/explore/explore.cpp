#include<bits/stdc++.h>
using namespace std;

int vis[1009][1009];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,x,y,z,mp[1009][1009];
        memset(vis,0,sizeof(vis));
        memset(mp,0,sizeof(mp));
        cin>>a>>b>>c>>x>>y>>z;
        int ans=0;
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                char d;
                cin>>d;
                if(d=='.') mp[i][j]=1;
            }
        }
        while(c--){
            if(vis[x][y]==0){
                vis[x][y]=1;
                ans++;
            }
            int u=x,v=y;
            if(z==0) v=y+1;
            if(z==1) u=x+1;
            if(z==2) v=y-1;
            if(z==3) u=x-1;
            if(mp[u][v]==0){
                z=(z+1)%4;
            }else{
                x=u,y=v;
            }
        }
        if(vis[x][y]==0) ans++;
        cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

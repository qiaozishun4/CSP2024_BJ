#include <bits/stdc++.h>
using namespace std;
int T,n,m,k,xx,yy,dd,t=0;
bool vis[1001][1001];
bool a[1001][1001];
char cc;
int sum=0;
int bfs(int x,int y,int d){
    if(t>=k){
        return sum+1;
    }
    if(d==0){
        if(vis[x][y+1]==1||y+1>m){
			t++;
            bfs(x,y,(d+1)%4);
        }else if(vis[x][y+1]==0&&y+1<=m){
			if(a[x][y+1]==0){
				a[x][y+1]=1;
				t++;
				sum++;
				bfs(x,y+1,d);
			}else{
				t++;
				bfs(x,y+1,d);
			}
			
        }
    }
    if(d==1){
        if(vis[x+1][y]==1||x+1>n){
			t++;
            bfs(x,y,(d+1)%4);
        }else if(vis[x+1][y]==0&&x+1<=n){
			if(a[x+1][y]==0){
				a[x+1][y]=1;
				t++;
				sum++;
				bfs(x+1,y,d);
			}else{
				t++;
				bfs(x+1,y,d);
			}
        }
    }
    if(d==2){
        if(vis[x][y-1]==1||y-1<=0){
			t++;
            bfs(x,y,(d+1)%4);
        }else if(vis[x][y-1]==0&&y-1>0){
			if(a[x][y-1]==0){
				a[x][y-1]=1;
				t++;
				sum++;
				bfs(x,y-1,d);
			}else{
				t++;
				bfs(x,y-1,d);
			}
        }
    }
    if(d==3){
        if(vis[x-1][y]==1||x-1<=0){
			t++;
            bfs(x,y,(d+1)%4);
        }else if(vis[x-1][y]==0&&x-1>0){
			if(a[x-1][y]==0){
				a[x-1][y]=1;
				t++;
				sum++;
				bfs(x-1,y,d);
			}else{
				t++;
				bfs(x-1,y,d);
			}
        }
    }
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>k;
        cin>>xx>>yy>>dd;
        a[xx][yy]=1;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                cin>>cc;
                if(cc=='x'){
                    vis[j][k]=1;
                }
            }
        }
        cout<<bfs(xx,yy,dd)<<endl;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                vis[j][k]=0;
            }
        }
        for(int j=1;j<=n;j++){
            for(int k=1;k<=m;k++){
                a[j][k]=0;
            }
        }
        t=0;
        sum=0;
	}
    return 0;
}

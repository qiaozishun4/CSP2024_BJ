#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+5;
char mp[MAXN][MAXN];
bool v[MAXN][MAXN];
struct node{
	int i1,j1,d1;
}t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		memset(v,0,sizeof(v));
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		int x,y,d;
		scanf("%d %d %d",&x,&y,&d);
		for(int j=1;j<=n;j++)
			for(int p=1;p<=m;p++)
				cin>>mp[j][p];
		t.i1=x,t.j1=y,t.d1=d;
		int ans=1;
		v[t.i1][t.j1]=1;
		for(int o=1;o<=k;o++){
			if(t.d1==0){
				int nx=t.i1,ny=t.j1+1;
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
					t.i1=nx,t.j1=ny;
					ans++;
					if(v[nx][ny]) ans--;
					v[nx][ny]=1;
				}
				else{
					t.d1=(t.d1+1)%4;
				}
			}
			else if(t.d1==1){
				int nx=t.i1+1,ny=t.j1;
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
					t.i1=nx,t.j1=ny;
					ans++;
					if(v[nx][ny]) ans--;
					v[nx][ny]=1;
				}
				else{
					t.d1=(t.d1+1)%4;
				}
			}
			else if(t.d1==2){
				int nx=t.i1,ny=t.j1-1;
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
					t.i1=nx,t.j1=ny;
					ans++;
					if(v[nx][ny]) ans--;
					v[nx][ny]=1;
				}
				else{
					t.d1=(t.d1+1)%4;
				}
			}
			else{
				int nx=t.i1-1,ny=t.j1;
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]=='.'){
					t.i1=nx,t.j1=ny;
					ans++;
					if(v[nx][ny]) ans--;
					v[nx][ny]=1;
				}
				else{
					t.d1=(t.d1+1)%4;
				}
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

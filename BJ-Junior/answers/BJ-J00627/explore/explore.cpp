#include<bits/stdc++.h>
using namespace std;
int t;
char a[1005][1005];
bool v[1005][1005];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,k,x,y,d,ans=0;
		scanf("%d%d%d",&n,&m,&k);
		scanf("%d%d%d",&x,&y,&d);
		v[x][y]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			if(d==0){
				if(y+1>m||a[x][y+1]=='x') d=1;
				else{
					y=y+1;
					v[x][y]=true;
				}
			}
			else if(d==1){
				if(x+1>n||a[x+1][y]=='x') d=2;
				else{
					x=x+1;
					v[x][y]=true;
				}
			}
			else if(d==2){
				if(y-1<1||a[x][y-1]=='x') d=3;
				else{
					y=y-1;
					v[x][y]=true;
				}
			}
			else if(d==3){
				if(x-1<1||a[x-1][y]=='x') d=0;
				else{
					x=x-1;
					v[x][y]=true;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(v[i][j]==1) ans++;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=1000;i++){
			for(int j=1;j<=1000;j++){
				v[i][j]=0;
			}
		}
	}
	return 0;
}

#include<iostream>
#include<cstring>
using namespace std;
int t,n,m,k,x,y,z,cnt,dy[]={1,0,-1,0},dx[]={0,1,0,-1},ans;
char a[1005][1005];
bool vi[1005][1005];
void ss(){
	while (cnt<k){
		if (x+dx[z]==0 || x+dx[z]>n || y+dy[z]==0 || y+dy[z]>m || a[x+dx[z]][y+dy[z]]=='x'){
			z=(z+1)%4;
			//cout<<z<<'\n';
			cnt++;
			continue;
		}
		x+=dx[z],y+=dy[z];
		cnt++;
		if (!vi[x][y])
			ans++,vi[x][y]=1;
	}
	cout<<ans<<'\n';
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.ans","w",stdout);
	cin>>t;
	for (int r=1;r<=t;r++){
		memset(vi,0,sizeof(vi));
		cnt=0,ans=1;
		cin>>n>>m>>k>>x>>y>>z;
		vi[x][y]=1;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		ss();
	}
	return 0;
}

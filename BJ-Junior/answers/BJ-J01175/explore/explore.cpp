#include <iostream>
#include <string>
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int main(){
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		string s;
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d,a[n+3][m+3],v[n+3][m+3];
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=1;j<=m;j++){
				if(s[j-1]=='.') a[j][i]=0;
				else if(s[j-1]=='x') a[j][i]=1;
			}
		}
		v[x][y]=1;
		for(int i=1;i<=k;i++){
			if(x+dx[d]<1 || y+dy[d]<1 || x+dx[d]>n || y+dy[d]>m || a[x+dx[d]][y+dy[d]]==1){
				d=(d+1)%4;
			}
			else{
				x+=dx[d],y+=dy[d];
				cout<<x<<' '<<y<<i<<endl;
				v[x][y]=1;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(v[i][j]==1) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

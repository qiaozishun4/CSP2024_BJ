#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		char a[1001][1001];
		int n,m,k,x,y,d;
		int dx[4]={0,1,0,-1};
		int dy[4]={1,0,-1,0};
		cin>>n>>m>>k>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		a[x][y]='#';
		while(k--){
			int x2=x+dx[d],y2=y+dy[d];
			if(x2<=n&&x2>=1&&y2<=m&&y2>=1&&a[x2][y2]!='x'){
				x=x2,y=y2;
				a[x][y]='#';
			}else{
				d=(d+1)%4;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(a[i][j]=='#'){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

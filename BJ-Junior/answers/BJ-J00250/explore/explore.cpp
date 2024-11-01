#include<bits/stdc++.h>
using namespace std;
string s;
int a[1010][1010];
int t;
int n,m,k;
int x,y,d;
int ans;
int xx,yy;
int ad[5][5]={{0,1},{1,0},{0,-1},{-1,0}};
void fun(){
	xx=x+ad[d][0];
	yy=y+ad[d][1];
	if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!=0){
		if(a[xx][yy]==1){
			a[xx][yy]=2;
			ans++;
		}
		x=xx;
		y=yy;
		//cout<<" x="<<x<<" xx="<<xx<<" y="<<y<<" yy="<<yy<<" d="<<d<<endl;
	}else{
		d=(d+1)%4;
		//cout<<" x="<<x<<" y="<<y<<" d="<<d<<endl;
	}
	return ;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>s;
			for(int j=0;j<m;j++){
				if(s[j]=='.'){
					a[i][j+1]=1;
				}else{
					a[i][j+1]=0;
				}
			}
		}
		a[x][y]=2;
		ans++;
		
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}*/
		
		for(int i=1;i<=k;i++){
			//cout<<" i="<<i;
			fun();
		}
		
		//cout<<endl;
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}*/
		
		cout<<ans<<endl;
	}
	return 0;
}
//特别

#include<bits/stdc++.h>
using namespace std;
long long t,n,m,k,d;
char arr[3111][3111];
bool st[3111][3111];
long long nxt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
long long x,y;
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>arr[i][j];
				st[i][j]=0;
			}
		}
		while(k--){
			st[x][y]=1;
			long long X=x+nxt[d][0],Y=y+nxt[d][1];
			if(X<=n&&X>=1&&Y<=m&&Y>=1&&arr[X][Y]=='.')x=X,y=Y;
			else d=(d+1)%4;
			st[x][y]=1;
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)ans+=st[i][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}

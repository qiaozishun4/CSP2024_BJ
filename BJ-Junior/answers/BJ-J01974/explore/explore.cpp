#include <bits/stdc++.h>
#define int long long

using namespace std;

int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

signed main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	
	int t;
	
	cin>>t;
	
	while(t--){
		int n,m,k,x,y,d,ans=0;
		
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		
		vector<vector<int> >mp(n+1,vector<int>(m+1,0));
		
		for(int i=1;i<=n;i++){
			string s;
			
			cin>>s;
			
			for(int j=0;j<m;j++){
				if(s[j]=='.'){
					mp[i][j+1]=0;
				}else{
					mp[i][j+1]=-1;
				}
			}
		}
		
		mp[x][y]=1;
		
		for(int i=1;i<=k;i++){
			int nx=x+dx[d],ny=y+dy[d];
			
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&mp[nx][ny]!=-1){
				mp[nx][ny]=1;
				x=nx;
				y=ny;
			}else{
				d=(d+1)%4;
			}
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mp[i][j]==1){
					ans++;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}

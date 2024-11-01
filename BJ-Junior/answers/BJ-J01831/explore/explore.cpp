#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vc=vector<char>;
using vl=vector<ll>;
const int inf=0x3f3f3f3f;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
const int D[]={1,2,3,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int x,y,d;
		cin>>x>>y>>d;
		vector<vc>mp(n+1,vc(m+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		vector<vi>b(n+1,vi(m+1));
		b[x][y]=1;
		int ans=1;
		for(int i=1;i<=k;i++){
			int xx=x+dx[d],yy=y+dy[d];
			if(0<xx&&xx<=n&&0<yy&&yy<=m&&mp[xx][yy]=='.'){
				x=xx,y=yy;
				ans+=1-b[x][y];
				b[x][y]=1;
			}else d=D[d];
			//cerr<<x<<" "<<y<<" "<<d<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}

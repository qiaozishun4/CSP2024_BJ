#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[1005];
bool vis[1005][1005][4],mp[1005][1005];
int yidong[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
struct node{
	int x,y,d,k;
}ling;
void jiejue(){
	cin>>n>>m>>ling.k;
	cin>>ling.x>>ling.y>>ling.d;
	for(int i=1;i<=n;++i){
		cin>>s[i];
		s[i]=" "+s[i];
	}
	//cout<<"NIHAO\n"<<" "<<n<<" "<<m<<" "<<ling.k<<"\n";
	memset(vis,0,sizeof(vis));
	memset(mp,0,sizeof(mp));
	queue<node> q;
	q.push(ling);
	int ans=0;
	while(!q.empty()){
		node x=q.front();q.pop();
		if(vis[x.x][x.y][x.d]) continue;
		vis[x.x][x.y][x.d]=1;
		if(!mp[x.x][x.y]) mp[x.x][x.y]=1,ans++;
		if(!x.k) continue;
		int bx=x.x+yidong[x.d][0],by=x.y+yidong[x.d][1];
		if(bx>=1&&bx<=n&&by>=1&&by<=m&&s[bx][by]=='.'){
			if(vis[bx][by][x.d]) continue;
			q.push((node){bx,by,x.d,x.k-1});
		}
		else{
			if(vis[x.x][x.y][(x.d+1)%4]) continue;
			q.push((node){x.x,x.y,(x.d+1)%4,x.k-1});
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	while(T--) jiejue();
	return 0;
}
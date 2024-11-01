#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int maxn=1e3+7;
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int n,m,k,ans=0;
struct robot{
	int x,y,d;
}now;
bool a[maxn][maxn];
void dr(int n,int m){
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++){
		char ch;cin>>ch;
		a[i][j]=(ch=='x'?1:0);
	}
}
bool check(int x,int y){
	if(x<1||x>n||y<1||y>m) return 0;
	return !a[x][y];
}
set<pair<int,int> >s;
void solve(){
	cin>>n>>m>>k;
    cin>>now.x>>now.y>>now.d;
    dr(n,m);
    s.clear();
    s.insert({now.x,now.y});
    while(k--){
		int tx=now.x+dx[now.d];
		int ty=now.y+dy[now.d];
		if(!check(tx,ty)){
			now.d++;
			now.d%=4;
		}else {
			now.x=tx,now.y=ty;
			s.insert({tx,ty});
		}
	}
	cout<<s.size()<<endl;
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
	int T;cin>>T;
	while(T--) solve();
    return 0;
}

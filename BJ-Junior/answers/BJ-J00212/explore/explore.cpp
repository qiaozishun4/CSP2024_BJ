#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,xf,yf,d,ans,cnt,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},headx,heady;
char M[1100][1100];
bool tmp[1100][1100];
queue<pair<int,int> >q;
pair<int,int>head;
bool check(int x,int y) {
	if(x<1||x>n||y<1||y>m||M[x][y]=='x') {
		return false;
	}
	return true;
}
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--) {
		ans=0;
		cnt=0;
		memset(M,0,sizeof(M));
		memset(tmp,0,sizeof(tmp));
		while(!q.empty()) {
			q.pop();
		}
		cin>>n>>m>>k;
		cin>>xf>>yf>>d;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>M[i][j];
			}
		}
		q.push({xf,yf});
		ans++;
		tmp[xf][yf]=true;
		while(cnt<k) {
			cnt++;
			head=q.front();
			headx=head.first;
			heady=head.second;
			if(check(headx+dx[d],heady+dy[d])) {
				q.pop();
				q.push({headx+dx[d],heady+dy[d]});
				if(!tmp[headx+dx[d]][heady+dy[d]]) {
					ans++;
					tmp[headx+dx[d]][heady+dy[d]]=true;
				}
			}
			else {
				d=(d+1)%4;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
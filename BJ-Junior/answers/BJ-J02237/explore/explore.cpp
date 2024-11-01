#include<bits/stdc++.h>
using namespace std;

int t;
int n,m,q;
int x,y,d;
char c;
int a[1005][1005],b[1005][1005];
int ans;

void solve(){
	if(d==0){
		if(y+1>m || a[x][y+1]==1){
			d=(d+1)%4;
		}
		else{
			++y;
		}
	}
	else if(d==1){
		if(x+1>n || a[x+1][y]==1){
			d=(d+1)%4;
		}
		else{
			++x;
		}
	}
	else if(d==2){
		if(y-1<1 || a[x][y-1]==1){
			d=(d+1)%4;
		}
		else{
			--y;
		}
	}
	else{
		if(x-1<1 || a[x-1][y]==1){
			d=(d+1)%4;
		}
		else{
			--x;
		}
	}
	if(b[x][y]==0){
		++ans;
		b[x][y]=1;
	}
	return;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		cin>>x>>y>>d;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>c;
				if(c=='.'){
					a[i][j]=0;
				}
				else{
					a[i][j]=1;
				}
				b[i][j]=0;
			}
		}
		ans=1;
		b[x][y]=1;
		while(q--){
			solve();
		}
		cout<<ans<<'\n';
	}
	return 0;
}

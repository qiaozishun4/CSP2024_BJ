#include<bits/stdc++.h>

using namespace std;

int t;
string s[1010];
bool f[1000][1000];
int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
int ans,cnt;
int n,m;

int dfs(int i,int j,int d,int k){
	ans=0;
	if(cnt==k){
		for(int l=1;l<=n;l++){
			for(int r=1;r<=m;r++){
				if(f[l][r]){
					ans++;
					f[l][r]=false;
				}
			}
		}
		return ans;
	}
		
	int a=i+x[d],b=j+y[d];
	if(s[a][b]=='.'){
		cnt++;
		f[a][b]=true;
		return dfs(a,b,d,k);
	}
	else {
		for(int l=0;l<=3;l++){
			d=(d+1)%4;
			cnt ++;
			a=i+x[d],b=j+y[d];
			if(s[a][b]=='.'){
				f[a][b]=true;
				break;
			}
		}
		return dfs(a,b,d,k);
	}
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);

	cin >> t;
	for(int i=0;i<t;i++){
		int k,x,y,d;
		cin >> n >> m >> k;
		cin >> x >> y >> d;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++)cin >> s[j][k];
		}

		cout << dfs(x,y,d,k) +1 <<'\n';
	}	


	return 0;
}

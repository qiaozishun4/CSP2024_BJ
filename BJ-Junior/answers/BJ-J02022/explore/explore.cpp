#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1010;
int n,m,k;
int x,y,d;
char a[N][N];
int cnt;
bool vis[N][N];
bool isin(int x,int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void solve(){
	cnt = 0;
	memset(vis, 0, sizeof vis);
	cin >> n >> m >> k;
	cin >> x >> y >> d;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j ++){
			cin >> a[i][j];
		}
	}
	k++;
	while(k){
		int tx = x, ty = y;
		if(d == 0) ty ++;
		if(d == 1) tx ++; 
		if(d == 2) ty--; 
		if(d == 3) tx--;
		if(!isin(tx,ty) || a[tx][ty] == 'x'){
			k--;
			//printf("%d %d a",tx,ty);
			d = (d + 1) % 4;
		}
		else{
			if(!vis[x][y]){
				cnt++;
				vis[x][y] = 1;
			}
			
			x = tx,y = ty;
			k--;
			
		}
	}
	cout << cnt << '\n';
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		solve();
	}




	
	return 0;
}

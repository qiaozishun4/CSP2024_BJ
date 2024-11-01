#include<bits/stdc++.h>
using namespace std;
long long n,m,k,t,c[11],r;
char a[1001][1001];
long long wx,wy,dc;
long long dx[5] = {0,1,0,-1},dy[5] = {1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> m >> k;
		cin >> wx >> wy >> dc;
		bool d[1001][1001] = {};
		for(long long i = 1;i <= n;i++){
			for(long long j = 1;j <= m;j++){
				cin >> a[i][j];
			}
		}
		int sum = 1;
		d[wx][wy] = true;
		for(long long i = 1;i <= k;i++){
			long long xx = wx+dx[dc];
			long long yy = wy+dy[dc];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && a[xx][yy] != 'x'){
				if(!d[xx][yy]){
					sum++;
					d[xx][yy] = true;
				}
				wx = xx;
				wy = yy;
			} else{
				dc = (dc+1)%4;
			}
		}
		c[++r] = sum;
	}
	for(long long i = 1;i <= r;i++){
		cout << c[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

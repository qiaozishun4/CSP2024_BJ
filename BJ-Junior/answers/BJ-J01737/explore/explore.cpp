#include <bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);	
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n,m,k,x,y,d,memo[1001][1001],walks = 0;
		char mp[1001][1001];
		cin >> n >> m >> k >> x >> y >> d;
		
		x--;
		y--;
		for(int j = 0; j < n; j++){
			cin >> mp[j];
			
			for(int l = 0; l < m; l++){
				memo[j][l] = 0;
			}
		}
		for(int j = 0; j <= k; j++){
		
			if(memo[x][y] == 0){
				walks++;
				memo[x][y] = 1;
			}
	
			if(d == 0  && x >= 0 && x < n && (y+1 >= 0) && (y+1 < m) && mp[x][y+1] == '.'){
		
				y = y+1;
				continue;
			}
			if(d == 1  && (x+1) >= 0 && (x+1) < n && y >= 0 && y < m && mp[x+1][y] == '.'){
				x = x+1;
				continue;
			}
			if(d == 2  && x >= 0 && x < n && (y-1) >= 0 && (y-1) < m && mp[x][y-1] == '.'){
				y = y-1;
				continue;
			}
			if(d == 3  && (x-1) >= 0 && (x-1) < n && y >= 0 && y < m && mp[x-1][y] == '.'){
				x = x-1;
				continue;
			}
			 
			if(d == 0 && (x < 0 || x >= n || (y+1) < 0 || (y+1) >= m || mp[x][y+1] == 'x')){
				d = (d+1)%4;
				continue;
			}
			if(d == 1 && ((x+1) < 0 || (x+1) >= n || y < 0 || y >= m || mp[x+1][y] == 'x')){
				d = (d+1)%4;
				continue;
			}
			
			if(d == 2 && (x < 0 || x >= n || (y-1) < 0 || (y-1) >= m || mp[x][y-1] == 'x')){
				d = (d+1)%4;
				continue;
			}
			if(d == 3 && ((x-1) < 0 || (x-1) >= n || y < 0 || y >= m || mp[x-1][y] == 'x')){
				d = (d+1)%4;
				continue;
			}
		}
		cout << walks << endl;
	}
	return 0;
}

